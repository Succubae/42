/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:48:07 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 10:49:08 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# define PAD_LEFT 0
# define PAD_RIGHT 1

# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void const *content, size_t content_size);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_strsplitlst(const char *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char*, const char*, size_t);
char	**ft_strsplit(char const *s, char c);
char	*ft_padding(const char*, size_t, int, char);
char	*ft_strdup(const char*);
char	*ft_strcpy(char*, const char*);
char	*ft_strncpy(char*, const char*, size_t);
char	*ft_strcat(char*, const char*);
char	*ft_strncat(char*, const char*, size_t);
char	*ft_strchr(const char*, int);
char	*ft_strrchr(const char*, int);
char	*ft_strstr(const char*, const char*);
char	*ft_strnstr(const char*, const char*, size_t);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, int n);
char	*ft_strtrim(char const *s);
char	*ft_itoa(long n);
char	*ft_strnew(size_t);
char	*ft_strmap(const char*, char (*f)(char));
char	*ft_strmapi(char const *s, char(*f)(unsigned int, char));
void	*ft_memset(void*, int, size_t);
void	*ft_memcpy(void*, const void*, size_t);
void	*ft_memccpy(void*, const void*, int, size_t);
void	*ft_memmove(void*, const void*, size_t);
void	*ft_memchr(const void*, int, size_t);
void	*ft_memalloc(size_t);
int		ft_lstcount(t_list *lst);
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_memdel(void**);
void	ft_putchar(char);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char*);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(long);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbrl(int n);
void	ft_strdel(char**);
void	ft_strclr(char*);
void	ft_striter(char*, void (*f)(char*));
void	ft_striteri(char*, void (*f)(unsigned int, char*));
void	ft_bzero(void*, size_t);
int		ft_strirchr(const char *str, int l);
int		ft_star(const char*, const char*);
int		ft_word_count(const char *s, char c);
int		*ft_build_length_tab(const char *s, char c, int);
int		ft_strichr(char *str, int l);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strcmp(const char*, const char*);
int		ft_strncmp(const char*, const char*, size_t);
int		ft_atoi(const char*);
int		ft_isalpha(int);
int		ft_isdigit(int);
int		ft_isalnum(int);
int		ft_isascii(int);
int		ft_isprint(int);
int		ft_toupper(int);
int		ft_tolower(int);
int		ft_memcmp(const void*, const void*, size_t);
#endif
