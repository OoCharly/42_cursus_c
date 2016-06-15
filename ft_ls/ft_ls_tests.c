/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:18:35 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/15 17:02:03 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_test_alpha(t_file *input, t_file *current, int reverse)
{
	return ((-1 * reverse) * ft_strcmp(input->fn, current->fn));
}

int		ft_ls_test_mtime(t_file *input, t_file *current, int reverse)
{
	time_t	in_t;
	time_t	cu_t;

	in_t = input->ls_stat->st_mtimespec.tv_sec;
	cu_t = current->ls_stat->st_mtimespec.tv_sec
	if (in_t > cu_t)
		return ((int)ft_pow(-1, reverse));
	else if (in_t < cu_t)
		return ((int)ft_pow(-1, reverse + 1));
	else
		return (0);
}


