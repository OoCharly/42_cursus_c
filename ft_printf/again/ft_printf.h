/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:14:09 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/11 14:52:06 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../../libft/includes/libft.h"
# define ARGS_LIST "CcSspDdioOuxXeEfFgG%"
# define FLAG_LIST "#- 0.*jzhl"
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
	unsigned char	sign_force : 2;
	unsigned char	format : 1;
	char			alt_size : 4;
	int				fw;
	int				precision;
	char			type;
	int				base;
}					t_flag;

int		ft_printf(char *fmt, ...);
char	*ft_render_integers(va_list ap, t_flag *f);
char	*ft_render_string(va_list ap, t_flag *f, int c);
int		ft_parse_em_all(char *fmt, va_list ap, t_flag *flag, t_list **list);
t_flag	*raz_flags(t_flag *flag);
char	*ft_process(t_flag *flag, t_list **lst, va_list ap);




//debug
# include <stdio.h>
void	stat_flag(t_flag *f);
#endif
