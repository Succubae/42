/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 13:04:20 by rgary             #+#    #+#             */
/*   Updated: 2013/12/06 16:44:51 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 100000000
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "libft/libft.h"

int		get_next_line(int const, char**);

#endif
