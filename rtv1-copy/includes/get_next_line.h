/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 13:04:20 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 17:08:33 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 10000
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

typedef struct	s_buf
{
	int				fd;
	char			*buf;
	struct s_buf	*next;
}				t_buf;

int		get_next_line(const int, char**);
#endif
