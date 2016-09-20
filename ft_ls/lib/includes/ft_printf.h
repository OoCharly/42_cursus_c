/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:14:09 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/20 13:13:43 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# define ARGS_LIST "bCcSspDdioOuUxXeEfFgG%"
# define FLAG_LIST "#+- 0.*jzhl"
# define SINTEGER_TYPE "dDi"
# define UINTEGER_TYPE "oOuUxXbp"
# define INTEGER_TYPE "dDioOuUxXbp"
# define DOUBLE_TYPE "efgEFG"
# define OBSOLETE_TYPE "SCDOU"
# define POS(x) (((x) > 0) ? (x) : 0)
# define BUFF_SIZE 9046

typedef struct		s_flag
{
	unsigned char	alt : 1;
	unsigned char	pad_0 : 1;
	unsigned char	pad_left : 1;
	char			alt_size : 4;
	char			sign_force;
	char			type;
	size_t			size;
	int				fw;
	int				precision;
	int				base;
}					t_flag;

int					ft_printf(char *fmt, ...);
char				*ft_printf_transform(t_flag *f, va_list ap);
char				*ft_printf_process(t_flag *flag, va_list ap);
void				ft_printf_field_parser(char *fmt, va_list ap, t_flag *f,
																		int n);
t_flag				*ft_printf_new_flag(void);
int					ft_printf_parse(char *fmt, va_list ap, t_list **list);
char				*ft_printf_render_unsignedint(va_list ap, t_flag *f);
char				*ft_printf_render_signedint(va_list ap, t_flag *f);
char				*ft_printf_render_string(va_list ap, t_flag *f);
char				*ft_printf_render_char(va_list ap, t_flag *f);
#endif
