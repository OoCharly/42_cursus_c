/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:27:31 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/26 14:08:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		display(int opt, t_grid *grid)
{
	int i;

	i = 0;
	if (opt == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	while (i < grid->len)
	{
		write(1, grid->tab[i], grid->len);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

t_grid	*alloc_init_grid(void)
{
	int		i;
	t_grid	*grid;

	i = 0;
	if (!(grid = malloc(sizeof(t_grid))))
		return (NULL);
	if (!(grid->tab = (char**)malloc(sizeof(char*) * 105)))
		return (NULL);
	while (i < 105)
	{
		if (!(grid->tab[i] = (char*)malloc(sizeof(char) * 105)))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < 11025)
	{
		grid->tab[i / 106][i % 106] = '.';
		i++;
	}
	return (grid);
}

int		solve(t_tetros *tetros, t_grid *grid)
{
	int	i;

	i = 2;
	while ((tetros->tot * 4) > ft_pow(i, 2))
		i++;
	grid->len = i;
	while (!place(0, tetros, grid))
	{
		grid->len++;
	}
	return (1);
}

int		tests(char *filename, char *buff, t_tetros *tetros)
{
	int		fd;
	int		n;

	fd = open(filename, O_RDONLY);
	if (fd < 2)
		return (0);
	n = read_fillit(fd, buff, tetros);
	if (close(fd) < 0)
		return (0);
	tetros->tets = ft_triplemalloc(tetros->tot);
	if (n && tetros->tets)
	{
		if (get_tetros(buff, n, tetros))
		{
			rearrange_tetros(tetros);
			return (1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int			valid;
	char		buff[601];
	t_tetros	*tetros;
	t_grid		*grid;

	valid = 0;
	if (argc != 2)
		return (usage(argc));
	if (!(tetros = malloc(sizeof(t_tetros))))
		return (display(valid, NULL));
	grid = alloc_init_grid();
	if (!grid)
		return (display(valid, grid));
	valid = tests(argv[1], buff, tetros);
	if (valid)
		solve(tetros, grid);
	return (display(valid, grid));
}
