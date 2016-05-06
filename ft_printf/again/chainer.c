
#include "ft_printf.h"

char	*concat_full(t_list *list)
{
	char	*out;
	t_list	tmp;

	if (!(out = ft_memalloc(ft_lstsumsize(list) + 1)))
		return (NULL);
	tmp = list;
	while (tmp)
	{
		ft_strcat(out, (const char*)tmp->data);
		tmp = tmp->next;
	}
	return (out);
}

char	*
