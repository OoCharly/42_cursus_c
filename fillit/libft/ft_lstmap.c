/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:52:35 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 22:33:14 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*prev;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	if (lst->next)
	{
		prev = ft_lstmap(lst->next, f);
		if (prev == NULL)
			return (NULL);
	}
	tmp = ft_lstnew(NULL, 0);
	if (tmp == NULL)
		return (NULL);
	tmp = (*f)(lst);
	out = ft_lstnew(tmp->content, tmp->content_size);
	if (out == NULL)
		return (NULL);
	ft_lstadd(&prev, out);
	return (out);
}
