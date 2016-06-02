/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:14:09 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/02 18:46:51 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../../libft/includes/libft.h"
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
	unsigned char	signd : 1;
	unsigned char	format : 1;
	char			alt_size : 4;
	char			sign_force;
	char			type;
	int				fw;
	int				precision;
	int				base;
}					t_flag;

char				*ft_transform(t_flag *f, va_list ap);
int					ft_printf(char *fmt, ...);
char				*ft_render_signed_integers(va_list ap, t_flag *f);
char				*ft_render_unsigned_integers(va_list ap, t_flag *f);
char				*ft_render_string(va_list ap, t_flag *f);
char				*ft_render_char(va_list ap, t_flag *f);
int					ft_parse_em_all(char *fmt, va_list ap, t_list **list);
void				ft_printf_field_parser(char *fmt, va_list ap, t_flag *f, int n);
t_flag				*new_flag(void);
char				*ft_process(t_flag *flag, va_list ap);
size_t				ft_concat_full(t_list **list, char *buff);

//debug
# include <stdio.h>
void				stat_flag(t_flag *f);
void				print_lst(t_list *lst);
#endif
