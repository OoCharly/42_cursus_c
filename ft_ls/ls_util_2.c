/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_util_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:54:38 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/18 17:48:04 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_valid_color(char c)
{
	char	cp;

	cp = ft_tolower(c);
	return ((cp == 'x') || (cp == 'a') || (cp == 'b') || (cp == 'c') ||
			(cp == 'd') || (cp == 'e') || (cp == 'f') || (cp == 'g') ||
			(cp == 'h'));
}

char		*get_lscol(void)
{
	char	*out;
	char	*env;
	int		i;

	i = 0;
	(out = ft_memalloc(sizeof(char) * 23)) ? : exit(2);
	ft_strcat(out, LS_COLOR_DEFAULT);
	if (!(env = ft_strdup(ft_getenv("LSCOLORS"))))
		return (out);
	else
		while ((i < 22) && env[i])
		{
			if (is_valid_color(env[i]))
				out[i] = env[i];
			else
			{
				color_error(env[i]);
				out[i] = 'x';
			}
			i++;
		}
	free(env);
	return (out);
}

void		get_util(t_util *util, int flag)
{
	util->flag = flag;
	util->cmp = get_cmpfunction(flag);
	util->fetch = (flag & NO_STAT) ? &fetch_info_long : &fetch_info_simple;
	if (flag & OPT_CLR)
	{
		util->lscol = get_lscol();	
		if (flag & OPT_LNG)
			util->print = (flag & GOT_PREFIX) ? &ls_clrprint_long_prefix
				: &ls_clrprint_long;
		else
			util->print = (flag & GOT_PREFIX) ? &ls_clrprint_prefix
				: &ls_clrprint_simple;
	}
	else if (flag & GOT_PREFIX)
		util->print = (flag & OPT_LNG) ? &ls_print_long_prefix
			: &ls_print_prefix;
	else
		util->print = (flag & OPT_LNG) ? &ls_print_long : &ls_print_simple;
}

blkcnt_t	ls_sum_blocks(t_list **plst)
{
	long long int	out;
	t_list			*tmp;

	out = 0;
	tmp = *plst;
	while (tmp)
	{
		out += ((t_info*)tmp->content)->i_stat->st_blocks;
		tmp = tmp->next;
	}
	return (out);
}

int			ls_by_rname(void *old, void *new)
{
	return (ft_strcmp(((t_info*)old)->i_name, ((t_info*)new)->i_name));
}

int			ls_by_name(void *old, void *new)
{
	return (ft_strcmp(((t_info*)new)->i_name, ((t_info*)old)->i_name));
}

