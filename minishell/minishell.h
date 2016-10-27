/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:30:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/27 15:06:30 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <sys/wait.h>

# include <errno.h>
# include <stdio.h>

typedef struct	s_config
{
	char		**env;
	char		**lbin;
	int			(**pbin)(int, char**, struct s_config*);
}				t_config;

typedef int		(*t_bin)(int, char**, t_config*);

int		msh_launch(char **args);
t_list	**msh_parse(char *cmd);
char	*msh_read_cmd(void);

#endif
