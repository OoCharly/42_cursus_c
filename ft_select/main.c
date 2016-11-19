/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:01:47 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 20:16:12 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sel_starterror(int ac, t_term *tios)
{
	char	*term;

	if (!(ac >> 1))
		sel_exit(SEL_ARGS_FEW);
	if (!(term = getenv("TERM")))
		sel_exit(SEL_TERM_NSET);
	if (!tgetent(NULL, term))
		sel_exit(SEL_TERM_NDB);
	if (tcgetattr(0, tios))
		sel_exit(SEL_DATA_NLOAD);
}

int	main(int ac, char **av)
{
	t_term	*tios;

	sel_starterror(ac, tios);
	return (0);
}

