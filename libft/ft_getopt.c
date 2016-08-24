/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 16:14:02 by cdesvern          #+#    #+#             */
/*   Updated: 2016/08/24 18:49:18 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getopt(int ac, char **av, const char *all)
{
	static char *l_opt;
	static int	current;
	static char	*ch;

	if (ac == 1)
		current = 1;
	if (!(l_opt = (l_opt) ? l_opt : ft_memalloc(sizeof(char * ft_strlen(all)))))
		return (-1);
	ch = (ch) ? ch : av[current];
	

