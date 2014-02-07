/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwagner <cwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 14:45:26 by cwagner           #+#    #+#             */
/*   Updated: 2014/01/17 16:23:41 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		lex_error(char **tab, int i, int j)
{
	ft_putstr_fd("Error at line ", 2);
	ft_putnbr_fd(i, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(tab[j], 2);
	ft_putendl_fd(" is sooooooooooooooooo wrong.", 2);
	return (ASM_FAILURE);
}
