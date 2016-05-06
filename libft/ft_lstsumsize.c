#include "libft.h"

size_t	ft_lstsumsize(t_list *lst)
{
	size_t	out;
	t_list	*tmp;

	if (!lst)
		return (0);
	out = 0;
	tmp = lst;
	while (tmp->next)
	{
		out += tmp->content_size;
		tmp = tmp->next;
	}
	return (out + tmp ->content_size);
}
