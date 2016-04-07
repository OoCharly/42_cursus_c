#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int	main(int ac, char **av)
{
	int	fd;
	int	tab_fd[10];
	int	a;
	int	i;
	char *line;

	if (ac == 1)
	{
		while ((a = get_next_line(0, &line)) > 0)
			printf("%s|->%d\n", line, a);
		printf("%d\n", a);
		return (0);
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((a = get_next_line(fd, &line)) > 0)
			printf("%s|->%d\n", line, a);
		printf("%d\n", a);
		return (0);
	}
	else if (ac < 12)
	{
		i = 0;
		while (i < ac)
		{
			tab_fd[i] = open(av[i + 1], O_RDONLY);
			i++;
		}
		i = 0;
		while (i < ac)
		{
			if ((a = get_next_line(tab_fd[i++], &line) > 0))
				printf("%s|->%d\n", line, a);
			else
				printf("%d\n", a);
		}
		i = 0;
		while (i < ac)
		{
			if ((a = get_next_line(tab_fd[i++], &line) > 0))
				printf("%s|->%d\n", line, a);
			else
				printf("%d\n", a);
		}
		return (0);
	}
	else
		return (0);
}
