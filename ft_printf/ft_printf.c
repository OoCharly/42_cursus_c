/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:28:26 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/06 12:49:21 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str(char *str, t_list **lst)
{
	size_t	len;
	char	*out;
	
	len = 0;
	while (*str && *str != '%' && *str != '{')
		len++;
	if(!(out = ft_memalloc(len + 1)));
		return (NULL);
	out = ft_strncpy(out, format, len + 1);
	ft_lstadd_end(lst, ft_lstnew(out, len + 1));
	free(out);
	return ((char *)(format + len));
}

t_list	**ft_format_parse(char *format, va_list ap)
{
	t_list	**lst;

	if (!(lst = malloc(sizeof(*lst))))
		return (NULL);
	while (format)
	{
		if (format != '%')
			format = get_str(format, lst);
		else
			format = get_param(format, lst);
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	ft_format_parse(format, ap);
