/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:14:09 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/10 16:18:12 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# define LIST_ARGS "#- 0.*CcSspDdioOuxXhljz"
# define INTEGER_TYPE "dDioOuUxX"
# define DOUBLE_TYPE "efgEFG"
# define STRING_TYPE "sScC"
# define OBSOLETE_TYPE "SCDOU"
# define POS(x) (((x) > 0) ? (x) : 0)

typedef struct		s_flag
{
	unsigned char	alt : 1;
	unsigned char	pad_0 : 1;
	unsigned char	pad_left : 1;
	unsigned char	signd : 1;
	char			alt_size : 4;
	char			sign_force;
	int				fw;
	int				precision;
	char			type;
}					t_flag;

#endif
