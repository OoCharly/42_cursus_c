/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:33:28 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/09 13:41:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

# define ARGS_LIST
# define LIST_FORMAT "sSpdDioOuUxXcC"

typedef struct		s_flag
{
	unsigned char	alt : 1;
	unsigned char	pad_0 : 1;
	unsigned char	pad_left : 1;
	char			alt_size : 4;
	char			sign_force;
	unsigned int	min_fw;
//	unsigned int	precision;
	char			type;
}					t_flag;

#endif

/*
 *

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
*/
