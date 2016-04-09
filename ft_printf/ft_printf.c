/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:28:26 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/08 15:12:47 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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

char	*ft_get_arg(char *str, t_flag flag, t_list **lst)
{
	while (!ft_strchr(LIST_FORMAT, *str))
	{
		
