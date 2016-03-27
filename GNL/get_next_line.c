/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 17:01:52 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/27 23:46:06 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*linencat(char *a, size_t size_a, t_mem *mem)
{
	char	*out;
	size_t	i;
	int	nline;

	i = 0;
	nline = 0;
	while (i < (size_t)(mem->last_read))
	{
		if (mem->buff[i++] == '\n')
		{
			nline++;
			mem->next_nl = (!mem->next_nl) ? i : mem->next_nl;
		}
	}
	mem->nb_nline = nline;
	if (!(out = ft_memalloc(sizeof(char) * (size_a + mem->last_read + 1))))
		return (NULL);
	ft_memcpy(out, a, size_a);
	i = (mem->nb_nline) ? mem->next_nl - 1 : mem->last_read;
	ft_memcpy(&out[size_a], mem->buff, i);
	out[size_a + mem->last_read] = '\0';
	if (a == NULL)
		return (out);
	free(a);
	return (out);
}

char	*get_line(t_mem *mem, const int fd)
{
	char	*out;
	size_t	size;

	size = 0;
	out = NULL;
	out = linencat(out, size, mem);
	while (mem->nb_nline == 0 && mem->last_read)
	{
		size += mem->last_read;
		mem->last_read = read(fd, mem->buff, BUFF_SIZE);
		if (mem->last_read == -1)
			return (NULL);
		out = linencat(out, size, mem);
		if (out == NULL)
			return (NULL);
	}
	if (!mem->last_read)
		return (out);
	mem->last_read -= mem->next_nl;
	ft_memmove(mem->buff, &(mem->buff[mem->next_nl]), mem->last_read);
	mem->nb_nline--;
	mem->next_nl = 0;
	return ((out) ? out : NULL);
}

void	del_mem(t_list **lst, int fd)
{
	t_list	*tmp;
	t_list	*father;

	father = NULL;
	tmp = *lst;
	while (((t_mem *)tmp->content)->fd != fd)
	{
		father = tmp;
		tmp = tmp->next;
	}
	if (father)
		father->next = tmp->next;
	else
		(*lst) = tmp->next;
	free(((t_mem*)tmp->content)->buff);
	free(tmp->content);
	free(tmp);
}

t_mem	*get_mem(t_list **lst, int fd, t_list *mem)
{
	t_mem	*out;
	
	if (mem->content == NULL)
	{
		if (!(out = malloc(sizeof(t_mem))))
			return (NULL);
		if (!(out->buff = malloc(sizeof(char) * BUFF_SIZE)))
			return (NULL);
		ft_lstadd(lst, ft_lstnew(out, sizeof(out)));
		out->nb_nline = 0;
		out->last_read = read(fd, out->buff, BUFF_SIZE);
		out->fd = fd;
		if (out->last_read < 0)
		{
			del_mem(lst, fd);
			return (NULL);
		}
		return (out);
	}
	else if (((t_mem*)mem->content)->fd == fd)
		return ((t_mem *)(mem->content));
	else
		return (get_mem(lst, fd, mem->next));
}

int		get_next_line(const int fd, char **line)
{
	static t_list	**lst;
	t_mem		*mem;

	if (lst == NULL)
	{
		lst = (t_list **)ft_memalloc(sizeof(t_list **));
		*lst = ft_lstnew(NULL, 0);
	}
	if (line == NULL || fd < 0 || lst == NULL)
		return (-1);
	mem = get_mem(lst, fd, *lst);
	if (mem == NULL)
		return (-1);
	if (mem->last_read == 0)
	{
		del_mem(lst, fd);
		return(0);
	}
	if (mem->last_read != 0)
		*line = get_line(mem, fd);
	if (mem->last_read == 0)
		del_mem(lst, fd);
	if (*line == NULL)
		return (-1);
	return (1);
}
