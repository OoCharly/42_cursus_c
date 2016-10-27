/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:43:34 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/27 16:29:20 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_prelaunch(char **args, t_config *config)
{
	t_bin	bin;
	char	**path;
	char	*exe;

	if ((bin = get_builtin(args[0], config)))
		return ((*bin)(msh_asize(args), args, config));
	path = ft_strsplit(ft_getenv(config, "PATH"), ':');
	if (!(exe = msh_getexe(path, args[0])))
		return (1);
	return (msh_launch(args, config->env));
}


int	msh_launch(char **args, char *env)
{
	pid_t	pid;
	int		status;
	t_bin	bin;

	pid = fork();
	if (pid == -1)
		exit(1);
	else if (!pid)
		if (execve(args[0], args, env) == -1)
			return(EXIT_FAILURE);
	else
		waitpid(pid, &status, 0);
	return (status);
}
