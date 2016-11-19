/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:43:35 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 15:33:53 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	resolve_args(char **args, t_config *conf)
{
	char	*tmp;
	char	*free_me;

	while ((free_me = *args))
	{
		if (**args == '~' && ((*(*args + 1) == '/') || (*(*args + 1) == 0)))
		{
			tmp = ft_getenv("HOME", conf->env);
			if (!tmp)
				return (msh_error(NULL, NULL, MSH_HOME_NOSET));
			*args = ft_strjoin(tmp, *args + 1);
			free(free_me);
		}
		else if (**args == '.' && (*(*args + 1) == '/'))
		{
			tmp = getcwd(NULL, _POSIX_PATH_MAX);
			if (!tmp)
				return (msh_error(NULL, NULL, MSH_ERR_MEM));
			*args = ft_strfjoin(tmp, *args + 1, 1);
			free(free_me);
		}
		args++;
	}
	return (0);
}

static void	clean_args(char **args)
{
	while (*args)
	{
		msh_strstrip(*args);
		args++;
	}
}

t_list		**msh_parse(char *cmd, t_config *conf, t_list **lcmd)
{
	char	**scargs;
	char	**args;
	char	**cp;
	int		err;

	scargs = msh_strsplit(cmd, ';');
	cp = scargs;
	free(cmd);
	while (*scargs)
	{
		args = msh_strspacesplit(*scargs);
		err = resolve_args(args, conf);
		clean_args(args);
		if (!*args || err)
		{
			msh_array_free(args);
			*lcmd = NULL;
		}
		else
			ft_lstadd_end(lcmd, ft_lstcreate(args, sizeof(args)));
		scargs++;
	}
	msh_array_free(cp);
	return (lcmd);
}
