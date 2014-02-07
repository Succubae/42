/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 11:37:16 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/08 15:09:46 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

void	err_usage(void)
{
	ft_putstr_fd("Usage: ./asm file\n", 2);
	ft_putstr_fd("\tfile: File that you want to compile for war\n", 2);
	exit(1);
}

void	err_badlabel(char *label)
{
	ft_putstr_fd("label : ", 2);
	ft_putstr_fd(label, 2);
	ft_putstr_fd(" called but never define\n", 2);
}