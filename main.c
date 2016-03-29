#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
void	get_info(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->content)
	{
		printf("----------\n");
		printf("-\nfd %d\nnline %d\nlread %d\n%s\n-\n",
				((t_mem*)tmp->content)->fd,
				((t_mem*)tmp->content)->nb_nline,
				((t_mem*)tmp->content)->last_read,
				((t_mem*)tmp->content)->buff);
		tmp = tmp->next;
		printf("----------\n");
	}
}


int	main(int ac, char **av)
{
	int	fd;
	char *out;

	fd = open(av[1], O_RDONLY);
	while (get_next_line (fd, &out))
	{
		printf("%s\n", out);
	}
	return (1);
}

