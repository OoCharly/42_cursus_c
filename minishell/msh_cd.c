/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:56:16 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/18 18:42:07 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_upwd(char *old, char*path, t_config *conf)
{
	char	*cmd[4];
	int		err;

	*cmd = "cd";
	cmd[1] = "OLDPWD";
	cmd[2] = old;
	cmd[3] = NULL;
	err = msh_setenv(3, cmd, conf);
	if (err)
		return (err);
	cmd[1] = "PWD";
	cmd[2] = path;
	return (msh_setenv(3, cmd, conf));
}

static int	msh_cd_access(char *path)
{
	struct stat *st;
	int			err;

	err = 0;
	if (access(path, F_OK))
		return (MSH_NOFILE);
	if (!(st = ft_memalloc(sizeof(*st))))
		return (MSH_ERR_MEM);
	lstat(path, st);
	if (!S_ISDIR(st->st_mode))
	{
		if (S_ISLNK(st->st_mode))
		{
			stat(path, st);
			if (!S_ISDIR(st->st_mode))
				err = MSH_NODIR;
		}
	}
	free(st);
	if (!err && access(path, X_OK))
		return (MSH_NOPERM);
	return (err);
}

static int	msh_cd_path(char *arg, t_config *conf, char **path)
{
	char	*tmp;

	if (arg[0] == '~' && (arg[1] == '/' || !arg[1]))
	{
		if (!(tmp = ft_strdup(ft_getenv("HOME", conf->env))))
			return (MSH_HOME_NOSET);
		if (!(*path = ft_strjoin(ft_getenv("HOME", conf->env), arg + 1)))
			return (MSH_ERR_MEM);
	}
	else if (arg[0] == '-' && !arg[1] &&
			!(*path = ft_strdup(ft_getenv("OLDPWD", conf->env))))
		return (MSH_OPWD_NOSET);
	else if (arg[0] == '/' && !(*path = ft_strdup(arg)))
		return (MSH_ERR_MEM);
	if (*path)
		return (0);
	if (*path || ((*path = getcwd(NULL, _POSIX_PATH_MAX)) &&
				(*path = ft_strfjoin(ft_strfjoin(*path, "/", 1), arg, 1))))
		return (0);
	else
		return (MSH_ERR_MEM);
}

int			msh_go(char *path, t_config *conf)
{
	int		err;
	char	*tmp;

	err = 0;
	if (ft_strlen(path) > _POSIX_PATH_MAX)
		return (MSH_PATH_TLONG);
	if ((err = msh_cd_access(path)))
		return (err);
	if (!(tmp = ft_strdup(ft_getenv("PWD", conf->env))) &&
			!(tmp = getcwd(NULL, _POSIX_PATH_MAX)))
		return (MSH_ERR_MEM);
	if (chdir(path))
		err = MSH_UNKNOW;
	if (!err)
		err = msh_upwd(tmp, path, conf);
	free(tmp);
	return (err);
}

int			msh_cd(int ac, char **args, t_config *conf)
{
	char	*path;
	int		err;

	err = MSH_ARGS_MANY;
	path = NULL;
	if (ac == 1 && !(err = msh_cd_path("~", conf, &path)))
		err = msh_go(path, conf);
	else if (ac == 2 && !(err = msh_cd_path(args[1], conf, &path)))
		err = msh_go(path, conf);
	else if (ac == 3)
		err = MSH_UNAVAIL;
	if (err)
		return (msh_error("cd", path, err));
	free(path);
	return (0);
}
