/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:43:34 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 15:47:34 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_exec(char **args, t_config *conf)
{
	char	*exec;
	t_bin	bin;
	int		err;

	exec = ft_strdup(args[0]);
	if (**args == '/')
	{
		if ((err = msh_exec_access(".", args[0])))
			return (msh_error(NULL, args[0], err));
		return (err = msh_launch(args[0], args, conf->env));
	}
	if ((bin = msh_get_builtin(args[0])))
		err = (*bin)(msh_array_size(args), args, conf);
	else if ((err = msh_search_exec(&exec, ft_getenv("PATH", conf->env))))
		return (msh_error(NULL, args[0], (err == MSH_NOFILE) ? MSH_CMD_NFOUND :
					err));
	else
		err = msh_launch(exec, args, conf->env);
	if (exec)
		free(exec);
	return (err);
}

int	msh_launch(char *exec, char **args, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		exit(1);
	else if (!pid)
	{
		if (execve(exec, args, env) == -1)
			exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	return (1);
}
