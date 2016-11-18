/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 23:59:43 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/27 00:03:37 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at_size(t_list *lst, size_t n)
{
	if (lst == NULL)
		return (NULL);
	if (n == lst->content_size)
		return (lst);
	else
		return (ft_lst_at_size(lst->next, n));
}
