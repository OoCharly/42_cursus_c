/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:47:23 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/10 16:18:10 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_do_stuff(char *fmt, va_list ap, t_flag *flag, t_list **lst)
{
	char 	*next_arg;

	next_arg = ft_strchr(fmt, '%')
	if (!next_arg)
	{
		ft_lstadd_end(lst, ft_lstcreate_node(ft_strdup(fmt), ft_strlen(fmt)));
		return (0);
	}
	else if (next_arg > fmt)
	{
		ft_lstadd_end(lst, ft_lstcreate_node(ft_strndup(fmt, next_arg - fmt), next_arg - fmt));
		
