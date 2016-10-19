/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:34:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/19 21:03:43 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ftn(t_list *mem, t_list **alst, t_list *new, t_list *cp)
{
	if (mem)
		mem->next = new;
	else
		*alst = new;
	new->next = cp;
}

void		ft_lstsort(t_list **alst, t_list *new, int (*f)(void *, void *))
{
	t_list	*cp;
	t_list	*mem;

	if (!(cp = *alst))
	{
		*alst = new;
		return ;
	}
	mem = NULL;
	while (cp)
	{
		if (f)
			if ((*f)(cp->content, new->content) < 0)
				return (ft_ftn(mem, alst, new, cp));
		mem = cp;
		cp = cp->next;
	}
	mem->next = new;
}
