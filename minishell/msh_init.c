/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:07:06 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/18 19:17:45 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_cd_access(char *path)
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
		err = MSH_NODIR;
	}
	free(st);
	if (!err && access(path, X_OK))
		return (MSH_NOPERM);
	return (err);
}

int		msh_exec_access(char *dir, char *file)
{
	if (access(dir, F_OK | X_OK))
		return (MSH_NOFILE);
	if (access(dir, R_OK))
		return (MSH_NOPERM);
	if (access(file, F_OK))
		return (MSH_NOFILE);
	if (access(file, R_OK | X_OK))
		return (MSH_NOPERM);
	return (0);
}

int		msh_search_exec(char **name, char *path)
{
	char	**cp;
	char	*tmp;
	int		err;

	err = MSH_CMD_NFOUND;
	if (!path)
		return (err);
	if (!(cp = msh_strsplit(path, ':')))
		return (MSH_ERR_MEM);
	while (*cp)
	{
		if (!(tmp = ft_strnew(ft_strlen(*name) + ft_strlen(*cp) + 2)))
			return (MSH_ERR_MEM);
		ft_strcat(ft_strcat(ft_strcat(tmp, *cp),
					((*cp)[ft_strlen(*cp) - 1] == '/') ? "" : "/"), *name);
		if (!(err = msh_exec_access(*cp, tmp)))
			break ;
		free(tmp);
		cp++;
	}
	free(*name);
	*name = (err) ? NULL : tmp;
	return (err);
}

t_bin	msh_get_builtin(char *name)
{
	int				i;
	static char		*b[] = {"cd", "echo", "setenv", "unsetenv", "env", "exit"};
	static t_bin	pbin[] = {&msh_cd, &msh_echo, &msh_setenv, &msh_unsetenv,
								&msh_env, &msh_exit};

	i = 0;
	while (i < 6)
	{
		if (!(ft_strcmp(name, b[i])))
			return (pbin[i]);
		i++;
	}
	return (NULL);
}
