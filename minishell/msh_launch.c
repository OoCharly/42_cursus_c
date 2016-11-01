/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:43:34 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/01 16:41:25 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_launch(char **args)
{
	extern char	**environ;
	pid_t	pid;
	int		status;

	if (check_builtins(args))
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		//status = msh_puterror("minishell", ERR_FORKFAIL);
		else if (!pid)
		{
			if (execve(args[0], args, environ) == -1)
				exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
		return (1);
	}
}
