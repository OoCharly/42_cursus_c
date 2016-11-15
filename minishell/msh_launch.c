/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:43:34 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/15 16:39:34 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_exec(char **args, t_config *conf)
{
	char	*exec;
	t_bin	bin;
	int		err;

	exec = ft_strdup(args[0]);
	ft_putendl("	msh_exec start");
	ft_putstr("	arg[0] -> ");
	ft_putendl(exec);
	ft_putstr("	trying");
	if (write(1, "\tbuiltin", 8) && (bin = msh_get_builtin(args[0])) && write(1, "\n", 1))
		err = (*bin)(msh_array_size(args), args, conf);
	else if (write(1, "\texecutable", 11) && (err = msh_search_exec(&exec, ft_getenv("PATH", conf->env))) && write(1, "\n", 1))
		return (msh_error(err));
	else
		err = msh_launch(exec, args, conf->env);
	return (err);
}

int	msh_launch(char *exec, char **args, char **env)
{
	pid_t	pid;
	int		status;
	t_bin	bin;

	pid = fork();
	if (pid == -1)
		exit(1);
	//status = msh_puterror("minishell", ERR_FORKFAIL);
	else if (!pid)
	{
		if (execve(exec, args, env) == -1)
		{
			exit(EXIT_FAILURE);
			//msh_shell_free(exec, args, env);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (1);
}
