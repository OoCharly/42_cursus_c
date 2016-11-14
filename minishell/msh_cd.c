/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:56:16 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/14 18:39:08 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static char	**msh_prep_cmd(char *exec, char *env, char *val)
{
	char	*cmd[4];

	cmd[0] = exec;
	cmd[1] = env;
	cmd[2] = val;
	cmd[3] = NULL;
	return (cmd);
}
static int	msh_cd_access(char *path)
{
	struct stat *st;
	int			err;

	if (access(path, F_OK))
		return (MSH_NOFILE);
	if (!(st = ft_memalloc(sizeof(*st))))
		return (MSH_ERR_MEM);
	lstat(path, st);
	if (!S_ISDIR(st->st_mode))
		err = MSH_NODIR;
	free(st);
	if (!err && access(path, X_OK))
		return (MSH_NOPERM);
	return (err);
}

static int	msh_cd_path(char *arg, t_config *conf, char **path)
{
	if (arg[0] == '~')
	{
		if (arg[1] == '/' || !arg[1])
		{
			if (!(*path = ft_strjoin(ft_strdup(ft_getenv("HOME", conf->env)),
					arg + 1)))
				return (MSH_HOME_NOSET);
		}
		else
			return (MSH_UNAVAIL);
	}
	else if (arg[0] == '-' && !arg[1] &&
			!(*path = ft_strdup(ft_getenv("OLDPWD", conf->env))))
		return (MSH_OPWD_NOSET);
	else if (arg[0] == '/' && !(*path = ft_strdup(arg)))
		return (MSH_ERR_MEM);
	return ((getcwd(*path, _POSIX_PATH_MAX)) ? 0 : MSH_ERR_MEM);
}

int	msh_go(char *path, t_config *conf)
{
	int		err;
	char	*tmp;
	char	**cmd;
	
	err = 0;
	if (ft_strlen(path) > _POSIX_PATH_MAX)
		return (MSH_PATH_TLONG);
	if ((err = msh_cd_access(path)))
		return (err);
	if (!getcwd(tmp, _POSIX_PATH_MAX))
		return (MSH_ERR_MEM);
	if (chdir(path))
		err = MSH_UNKNOW;
	if (!err)
	{
		cmd = msh_prep_cmd("cd", "OLDPWD", tmp);
		err = msh_setenv(3, cmd, conf);
		if (!err)
		{
			cmd = msh_prep_cmd("cd", "PWD", path);
			err = msh_setenv(3, cmd, conf);
		}
	}
	free(tmp);
	return (err);
}

int	msh_cd(int	ac, char **args, t_config *conf)
{
	char	*path;
	int		err;

	err = MSH_ARGS_MANY;
	if (ac == 1 && !(err = msh_cd_path("~", conf, &path)))
		err = msh_go(path, conf);
	else if (ac == 2 && !(err = msh_cd_path(args[1], conf, &path)))
		err = msh_go(path, conf);
	else if (ac == 3)
		err = MSH_UNAVAIL;
	if (err)
		return (err);
	free(path);
	return (0);
}


