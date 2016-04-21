/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:28:26 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/21 12:38:09 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

parse_arg(t_flag *flag, va_list ap)
{


int		check_args(char *fmt, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!ft_strnchr(ARGS_LIST, *(fmt + i)))
			return (0);
		i++;
	}
	return (1);
}
{
	char	*next_arg;
	char	*new;

	while (*format)
	{
		next_arg = ft_strchr(format, '%');
		if (next_arg == NULL)
		{
			ft_lstadd_end(lst, ft_lstcreate_node(format, ft_strlen(format)));
			return ();
		}
		else if (next_arg > format)
		{
			if (!(new = ft_strndup(format, (size_t)(next_arg - format))))
				return (NULL);
			ft_lstadd_end(lst, ft_lstcreate_node(new, ft_strlen(new)));
			format = ft_get_arg(next_arg, lst);
		}
		else
			format = ft_get_arg(next_arg, lst);
	}
}

char	*ft_get_arg(char *fmt, t_list **lst, va_list ap)
{
	t_flag	*flag;
	char	*out;

	if(!(flag = ft_get_flags(fmt)))
		return (fmt + 1);
	out = parse_arg(flag, ap);
