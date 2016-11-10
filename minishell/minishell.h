/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:30:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/10 13:43:42 by cdesvern         ###   ########.fr       */
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

# define CLP_BUFFSIZE	42

# define MSH_ERR_MEM	9

# define CLP_FLUSH		2

# define MSH_ARGS_FEW	11
# define MSH_ARGS_MANY	12

# define MSH_ENV_NALNUM	21
typedef struct	s_config
{
	char		**env;
}				t_config;

int		(*t_bin)(char **args, char **env);
int		msh_launch(char **args);
t_list	**msh_parse(char *cmd);
char	*msh_read_cmd(void);
void	msh_strstrip(char *str);
char	**msh_strsplit(char *str, char c);
char	**msh_strspacesplit(char *str);
char	**msh_inarray(char *str, char **array);
int		msh_array_size(char **array);
char	**msh_array_add_elem(char **array, char *elem);
void	msh_array_free(char **array);

#endif
