/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:07:06 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/10 16:43:00 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_exec_access(char *dir, char *file)
{
	if (access(dir, F_OK))
		return (MSH_NOFILE);
	if (access(dir, X_OK|R_OK))
}

int		msh_search_exec(char **name, char **path)
{
	char	**cp;
	char	*tmp;
	int		err;

	cp = path;
	err = MSH_NOFILE;
	while (*cp)
	{
		if (!(tmp = ft_strnew(ft_strlen(*name) + ft_strlen(*cp) + 2)))
			return (MSH_ERR_MEM);
		ft_strcat(ft_strcat(ft_strcat(tmp, *cp),
					(*cp[ft_strlen(*cp) - 1] == '/') ? "" : "/"), *name);
		if (!(err = msh_exec_access(*cp, tmp)))
				break ;
		free (tmp);
		cp++;
	}
	free (*name);
	msh_array_free(path);
	*name = (err) ? NULL : tmp;
	return (err);
}

t_bin	*msh_get_builtin(char *name, t_config *config)
{
	int		i;
	char	*bin[6];
	t_bin	pbin[6];

	bin = {"cd", "echo", "setenv", "unsetenv", "env", "exit"};
	pbin = {&msh_cd, &msh_echo, &msh_setenv, &msh_unsetenv, &msh_env,
			&msh_exit};
	i = 0;
	while (i < 6)
	{
		if (!(ft_strcmp(name, cp[i])))
			return (pbin[i]);
		i++;
	}
	return (NULL);
}
