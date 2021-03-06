/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 19:02:41 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/15 13:38:50 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

typedef	unsigned char	t_byte;
typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

/*
** tests
*/
int						ft_atoi(const char *str);
int						ft_isalnum(int c);
int						ft_isnum(char c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isspace(char c);
int						ft_stroccur(char *s, int c);
int						ft_strnoccur(char *s, int c, size_t n);
uintmax_t				ft_umax(uintmax_t a, uintmax_t b);
/*
** transformers
*/
char					*ft_itoa(int n);
char					*ft_ntoa(intmax_t n);
char					*ft_ntoa_base(uintmax_t nb, unsigned int base);
/*
** memory manipulation
*/
void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t size);
void					*ft_memrealloc(void *old, size_t size);
void					*ft_memccpy(void *dst, const void *src, int c,
									size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
/*
** Printing functions
*/
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
/*
** Strings manipulation
*/
char					*ft_strcat(char *s1, const char *s2);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
char					*ft_strndup(const char *src, size_t n);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char*));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strfjoin(char *s1, char *s2, int opt);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int, char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strfcat(char *s1, char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dst, const char *src, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strnchr(const char *s, int c, size_t n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnrchr(const char *s, int c, size_t n);
char					**ft_strsplit(char const *s, char c);
char					**ft_strsplitspace(char const *s);
char					*ft_strsub(char const *s, unsigned int start,
									size_t len);
char					*ft_strtrim(char const *s);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					*ft_char_to_string(int c);
char					*ft_wchar_to_string(int c);
char					*ft_wstring_to_string(wchar_t *s);
size_t					ft_wstrlen(wchar_t *ws);
void					ft_capitalize(char *str);
/*
** Lists manipulation
*/
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdelfst(t_list **alst, void (*del)(void*, size_t));
t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					**ft_lstpnew(void const *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstadd_end(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstcreate(void *content, size_t content_size);
size_t					ft_lstsumsize(t_list **lst);
void					ft_del_node(void *data, size_t n);
void					ft_lstsort(t_list **alst, t_list *new,
										int (*f)(void *, void *));
/*
** maths
*/
uintmax_t				ft_pow(int n, int p);
int						ft_nsize_base(uintmax_t nb, int base);
/*
** env
*/
char					*ft_getenv(const char *name, char **env);
#endif
