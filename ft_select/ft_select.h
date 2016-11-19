/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:29:21 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 20:29:37 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

typedef struct termios	t_term;
typedef struct			s_dclist
{
	char				*elem;
	struct s_dclist		near[2];
}						t_dclist;

# define DC_NEXT near[1]
# define DC_PREV near[0]

#endif
