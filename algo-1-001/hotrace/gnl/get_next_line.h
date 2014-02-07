/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 11:57:59 by sbuono            #+#    #+#             */
/*   Updated: 2013/12/15 13:04:49 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFF_SIZE 512

typedef struct 		s_buf
{
	int 			fd;
	char			*buf;
	struct s_buf	*next;
}					t_buf;

typedef unsigned int	u_int;

int		ft_strnbchr(const char *str, int c);
char	*ft_strnjoin(const char *s1, const char *s2, int n);
char	*ft_strnew(size_t size);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int		get_next_line(int const fd, char **line);
void	ft_bzero(void *s, size_t n);

#endif
