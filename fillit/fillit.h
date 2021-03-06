/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:52:27 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/04 10:34:50 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_tetros
{
	char		***tets;
	int			tot;
}				t_tetros;

typedef struct	s_grid
{
	char		**tab;
	int			len;
}				t_grid;

int				usage(int ac);
char			***ft_triplemalloc(int i_max);
void			free_grid(t_grid *grid);
void			free_tetros(t_tetros *tetros);
int				ft_pow(int nb, int power);

int				read_fillit(int fd, char *buffi, t_tetros *tetros);
int				get_tetros(char *buff, int n, t_tetros *tetros);

int				place(int current, t_tetros *tetros, t_grid *grid);

int				rearrange_tetros(t_tetros *tetros);

int				check_tetros(char *buff, int p,
							t_tetros *tetros);
int				get_cohesion(int p, t_tetros *tetros);

void			ft_putstr(char const *str);
size_t			ft_strlen(const char *s);
void			*ft_memalloc(size_t size);

#endif
