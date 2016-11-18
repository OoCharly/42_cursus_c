/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:16:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/06 10:10:13 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

# define CRED "\x1B[31m"
# define CGRE "\x1B[32m"
# define CYEL "\x1B[33m"
# define CBLU "\x1B[34m"
# define CMAG "\x1B[35m"
# define CCYA "\x1B[36m"
# define CWHI "\x1B[37m"
# define CEND "\x1B[0m"

void		ft_putstr_color(char *str, char *color);

#endif
