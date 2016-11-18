/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:30:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/18 17:44:39 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include <errno.h>
# include <stdio.h>

# define CLP_BUFFSIZE	42
# define CLP_FLUSH		2

# define MSH_ERR_MEM	9
# define MSH_UNAVAIL	8
# define MSH_UNKNOW		7

# define MSH_ARGS_FEW	11
# define MSH_ARGS_MANY	12

# define MSH_NOFILE		21
# define MSH_NODIR		22
# define MSH_NOPERM		23
# define MSH_PATH_TLONG	24
# define MSH_INV_OPT	25
# define MSH_CMD_NFOUND	26

# define MSH_HOME_NOSET	31
# define MSH_OPWD_NOSET	32

# define MSH_ENV_NALNUM	41
# define MSH_ENV_MISARG	42

# define MSH_ERR_PTED	50

# define MSG_NOFILE		"No such file or directory: "
# define MSG_NODIR		"Not a directory: "
# define MSG_NOPERM		"Permission Denied: "
# define MSG_PATH_TLONG	"Path specified is too long."
# define MSG_INV_OPT	"Invalid Option: "
# define MSG_CMD_NFOUND	"Command not found: "

# define MSG_HOME_NOSET	"HOME not set."
# define MSG_OPWD_NOSET	"OLDPWD not set."

# define MSG_ERR_MEM	"Something went wrong with memory."
# define MSG_UNAVAIL	"Option currently unavailable."
# define MSG_UNKNOW		"Unknown Error."

# define MSG_ARGS_FEW	"Too few argument."
# define MSG_ARGS_MANY	"Too many arguments."

# define MSG_ENV_NALNUM	"Variable name must contain alphanumeric characters."
# define MSG_ENV_MISARG	"option require an argument -- "

typedef struct	s_config
{
	char		**env;
}				t_config;

typedef int		(*t_bin)(int, char**, t_config*);

int				msh_launch(char *exec, char **args, char **env);
t_list			**msh_parse(char *cmd);
int				msh_cmd_parser(int fd, char **line);
char			*msh_read_cmd(void);
void			msh_strstrip(char *str);
char			**msh_strsplit(char *str, char c);
char			**msh_strspacesplit(char *str);
char			**msh_inarray(char *str, char **array);
int				msh_array_size(char **array);
char			**msh_array_add_elem(char **array, char *elem);
void			msh_array_free(char **array);
char			**msh_arraydup(char **array);
int				msh_exec(char **args, t_config *conf);
int				msh_unsetenv(int ac, char **args, t_config *conf);
int				msh_setenv(int ac, char **args, t_config *conf);
int				msh_print_array(char **array);
int				msh_env(int	ac, char **args, t_config *conf);
int				msh_exit(int ac, char **args, t_config *conf);
int				msh_cd(int	ac, char **args, t_config *conf);
int				msh_echo(int ac, char **args, t_config *conf);
t_bin			msh_get_builtin(char *name);
int				msh_search_exec(char **name, char *path);
int				msh_error(char *exec, char *name, int err);
int				msh_exec_access(char *dir, char *file);
int				msh_export(int ac, char **args, t_config *conf);
void			msh_lstarray_free(void *array, size_t n);

#endif
