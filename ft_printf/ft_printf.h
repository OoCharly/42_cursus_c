/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:33:28 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/31 18:03:42 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

typedef union		u_type
{
	char				c;
	unsigned char		hhu;
	short				h;
	unsigned short		hu;
	int					i;
	unsigned int		iu;
	long				l;
	unsigned long		lu;
	long long			ll;
	unsigned long long	llu;
	intmax_t			j;
	uintmax_t			ju;
	size_t				z;
	ssize_t				zs;
	void				*p;
}					t_type;
/*
typedef struct		s_flag
{
	unsigned int	u : 1;
	unsigned int	l : 1;
*/
#endif
