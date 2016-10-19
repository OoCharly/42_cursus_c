/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:36:26 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/19 20:22:48 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_invalid_opt(char ch)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(ch, 2);
	write(2, "\n", 1);
}

void	color_error(char c)
{
	ft_putstr_fd("error: invalid character '", 2);
	write(2, &c, 1);
	ft_putstr_fd("' in LSCOLORS env var\n", 2);
}

void	ls_error(char *file)
{
	write(2, "ft_ls: ", 7);
	if (!*file)
		perror("open");
	else
		perror(file);
}

int		usage(void)
{
	ft_putendl_fd("usage: ls [1ACFGRSTUacdfgilorstu] [file ...]", 2);
	exit(2);
}
