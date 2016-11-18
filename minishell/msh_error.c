/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 12:44:00 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/18 17:10:40 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_errget(int err)
{
	static int	errint[] = {MSH_NOFILE, MSH_NODIR, MSH_NOPERM, MSH_PATH_TLONG,
	MSH_INV_OPT, MSH_CMD_NFOUND, MSH_HOME_NOSET, MSH_OPWD_NOSET, MSH_ERR_MEM,
	MSH_UNAVAIL, MSH_UNKNOW, MSH_ARGS_FEW, MSH_ARGS_MANY, MSH_ENV_NALNUM,
	MSH_ENV_MISARG};
	static char	*errmsg[] = {MSG_NOFILE, MSG_NODIR, MSG_NOPERM, MSG_PATH_TLONG,
	MSG_INV_OPT, MSG_CMD_NFOUND, MSG_HOME_NOSET, MSG_OPWD_NOSET, MSG_ERR_MEM,
	MSG_UNAVAIL, MSG_UNKNOW, MSG_ARGS_FEW, MSG_ARGS_MANY, MSG_ENV_NALNUM,
	MSG_ENV_MISARG};
	int			i;

	i = 0;
	while (errint[i] != err)
		i++;
	return (errmsg[i]);
}

int		msh_error(char *exec, char *name, int err)
{
	if (!err)
		return (0);
	if (err == MSH_ERR_PTED)
		return (MSH_ERR_PTED);
	if (!exec)
		ft_putstr_fd("msh", 2);
	else
		ft_putstr_fd(exec, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msh_errget(err), 2);
	if (name)
		ft_putstr_fd(name, 2);
	ft_putendl_fd("", 2);
	return (MSH_ERR_PTED);
}
