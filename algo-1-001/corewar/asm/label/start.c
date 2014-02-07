/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:45:51 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/07 12:45:52 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "asm.h"

void	sta_free(t_start **st)
{
	if ((*st)->filename)
		free((*st)->filename);
	if ((*st)->name)
		free((*st)->name);
	if ((*st)->comment)
		free((*st)->comment);
}

int		sta_init(t_start **st, char *file)
{
	if ((*st = (t_start *)ft_memalloc(sizeof(t_start))) == NULL)
	{
		ft_putstr_fd("malloc of start failed\n", 2);
		return (ASM_FAILURE);
	}
	(*st)->filename = ft_strdup(file);
	return (ASM_SUCCESS);
}