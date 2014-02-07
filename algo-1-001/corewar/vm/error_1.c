/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:38:51 by sbuono            #+#    #+#             */
/*   Updated: 2014/01/19 16:10:15 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "corewar.h"
#include "libft.h"

int		prt_err(char *function, char *add)
{
	write(2, "corewar: ", 16);
	ft_putstr_fd(function, 2);
	write(2, ": ", 2);
	if (add[0] != 0)
	{
		ft_putstr_fd(add, 2);
		write(2, ": ", 2);
	}
	perror(NULL);
	write(2, "\n", 1);
	return (CORE_FAILURE);
}

void	*prt_err_null(char *function, char *add)
{
	write(2, "corewar: ", 16);
	ft_putstr_fd(function, 2);
	write(2, ": ", 2);
	if (add[0] != 0)
	{
		ft_putstr_fd(add, 2);
		write(2, ": ", 2);
	}
	perror(NULL);
	write(2, "\n", 1);
	return (NULL);
}