/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:38:51 by sbuono            #+#    #+#             */
/*   Updated: 2014/01/17 16:32:07 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <asm.h>
#include <libft.h>

int		prt_err(int line, t_lexer *lst)
{
	write(2, "asm: Error line ", 16);
	ft_putnbr_fd(line, 2);
	write(2, " :\n", 3);
	while (lst->token != ENDOFLINE)
	{
		ft_putstr_fd(lst->value, 2);
		ft_putstr_fd(" ", 2);
		lst = lst->next;
	}
	write(2, "\n", 1);
	return (ASM_FAILURE);
}
