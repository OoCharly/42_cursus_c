/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:33:28 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/06 12:59:41 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

# define LIST_FORMAT "diouXxfFeEgGaAcsb"

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

typedef struct		s_flag
{
	char			alt : 1;
	char			pad_0 : 1;
	char			pad_left : 1;
	char			sign_force;
	unsigned int	precision;
}					t_flag;


#endif
