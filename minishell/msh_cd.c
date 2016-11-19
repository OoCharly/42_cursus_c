/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:56:16 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 14:45:22 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_upwd(char *old, t_config *conf)
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
	cmd[2] = getcwd(NULL, _POSIX_PATH_MAX);
	err = msh_setenv(3, cmd, conf);
	free(cmd[2]);
	return (err);
}

static char	*msh_get_dir(char *arg, t_config *conf)
{
	char	*tmp;
	char	*prev;
	int		i;

	i = 1;
	if (!(tmp = ft_strdup(ft_getenv("PWD", conf->env))))
		tmp = getcwd(tmp, _POSIX_PATH_MAX);
	if (*(arg + 1) == '.')
	{
		prev = ft_strrchr(tmp, '/');
		*prev = 0;
		i++;
	}
	return (ft_strfjoin(ft_strfjoin(tmp, (*(arg + i) == '/') ? "" : "/", 1),
				arg + i, 1));
}

static int	msh_cd_path(char *arg, t_config *conf, char **path)
{
	char	*tmp;

	if (arg[0] == '~' && (arg[1] == '/' || !arg[1]))
	{
		if (!(tmp = ft_strdup(ft_getenv("HOME", conf->env))))
			return (MSH_HOME_NOSET);
		if (!(*path = ft_strfjoin(tmp, arg + 1, 1)))
			return (MSH_ERR_MEM);
	}
	else if (arg[0] == '-' && !arg[1] &&
			!(*path = ft_strdup(ft_getenv("OLDPWD", conf->env))))
		return (MSH_OPWD_NOSET);
	else if (arg[0] == '/' && !(*path = ft_strdup(arg)))
		return (MSH_ERR_MEM);
	else if ((arg[0] == '.') && !(*path = msh_get_dir(arg, conf)))
		return (MSH_ERR_MEM);
	if (*path || ((*path = getcwd(NULL, _POSIX_PATH_MAX)) &&
				(*path = ft_strfjoin(ft_strfjoin(*path, "/", 1), arg, 1))))
		return (0);
	else
		return (MSH_ERR_MEM);
}

static int	msh_go(char *path, t_config *conf)
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
		err = msh_upwd(tmp, conf);
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
