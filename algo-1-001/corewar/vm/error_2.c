/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:09:54 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/25 17:09:56 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	prt_err_usage(void)
{
	ft_putstr_fd("Usage :\n", 2);
	ft_putstr_fd("\t[-dump nbr_cycles] [[-n number] champion1.cor] ...\n", 2);
	exit(1);
}

void	ptr_err_heroneeded(void)
{
	ft_putstr_fd("-n option needs to be followed by a hero file\n", 2);
	prt_err_usage();
}

void	ptr_err_scary(void)
{
	ft_putstr_fd("Too scared to fight others ? (Need at least 1 hero)\n", 2);
	prt_err_usage();
}

void	ptr_err_battleroyal(void)
{
	ft_putstr_fd("This is not SPARTAAAAAA ! (4 heroes max)\n", 2);
	prt_err_usage();
}