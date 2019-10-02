/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:14:09 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 11:27:59 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define MAXLONG 9223372036854775807

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_printf(const char *fmt, ...);
int					ft_isdelim(char c, char delim);
int					ft_str_is_lowercase(char *s);
int					ft_str_is_printable(char *s);
int					ft_isupper(int c);
int					ft_str_is_numeric(char *s);
int					ft_islower(int c);
int					ft_count_whtsp_start(char const *s);
char				*ft_strsep(char *s, const char delim);
int					ft_count_whtsp_end(char const *s);
int					ft_count_words(char const *s, char c);
int					ft_word_size(char const *s, char c);
void				ft_striter(char *s, void (*f)(char *));
int					ft_lower(int c);
int					ft_isascii(int c);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_putchar(char c);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_putendl(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dst, const char *src);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_itoa(int n);
int					ft_isascii(int c);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
char				*ft_strchr(const char *s, int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_strsplit(char const *s, char c);
int					ft_isprint(int c);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strdel(char **as);
char				*ft_strstr(const char *haystack, const char *needle);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_memdel(void **ap);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_isalnum(int c);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putnbr(int n);
char				*ft_strchr(const char *s, int c);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
int					ft_isalpha(int c);
void				ft_lstadd(t_list **alst, t_list *new);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_tolower(int c);
char				*ft_strrchr(const char *s, int c);
#endif
