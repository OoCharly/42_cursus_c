/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:33:28 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/07 17:20:05 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

# define LIST_FORMAT "sSpdDioOuUxXcC"
# define UNSIGNED_TYPES "ouxX"
# define SIGNED_TYPES "di"

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
	unsigned char	alt : 1;
	unsigned char	pad_0 : 1;
	unsigned char	pad_left : 1;
	char			alt_size : 4;
	char			sign_force;
	unsigned int	precision;
}					t_flag;

#endif
