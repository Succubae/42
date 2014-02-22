/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:18:14 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/17 14:33:34 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <wchar.h>

#ifndef LIBFT_H
# define LIBFT_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define EOL '\n'

typedef unsigned long	t_ul;
typedef unsigned int	t_ui;

typedef enum	e_paddir
{
	PAD_LEFT,
	PAD_RIGHT
}				t_paddir;


typedef struct	s_nextline
{
	char	*prev;
	int		kill;
}				t_nextline;

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);

void	*ft_memalloc(size_t size);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char *str);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putwchar(wchar_t c);
void	ft_putunbr(unsigned long n);
void	ft_putnbr(long n);
void	ft_putnbr_fd(long n, int fd);
void	ft_putendl_fd(char const *str, int fd);

char	**ft_strsplit(char const *s, char c);
char	**ft_strsplitwhite(char const *s);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);
char	*ft_stoa(long n);
char	*ft_strsub(char const *s, t_ui start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strichr(char const *s, char c);
char	*ft_strjoinc(char const *s1, char const c);
int		ft_strncmp(const char *str, const char *str2, size_t n);
char	*ft_strrev(char const *s1);
char	*ft_strtrim(char const *s);
char	*ft_strglue(char **split, char glue);
int		ft_countsplit(char **split);

char	*ft_utoa(t_ul n, t_ul base);
char	*ft_uitoa(unsigned long n);
char	*ft_itoa(long n);

void	impossible_malloc(char *s);

void	kill_me(char *s);

int		get_next_line(const int, char **);
#endif
