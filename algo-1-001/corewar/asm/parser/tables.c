/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 08:21:47 by sbuono            #+#    #+#             */
/*   Updated: 2014/01/11 11:00:54 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <libft.h>

t_type	*tab_return_table(int op)
{
	static t_type	tab[16][6] = {
		{DIR, 0, 0, 0, 0, 0},
		{IND | DIR | DIR_LAB | IND_LAB, SEP, REG, 0, 0, 0},
		{REG, SEP, REG | IND | IND_LAB, 0, 0, 0},
		{REG, SEP, REG, SEP, REG, 0},
		{REG, SEP, REG, SEP, REG, 0},
		{REG | IND | DIR | DIR_LAB | IND_LAB, SEP, REG | IND | DIR
			| DIR_LAB | IND_LAB, SEP, REG, 0},
		{REG | IND | DIR | DIR_LAB | IND_LAB, SEP, REG | IND | DIR
			| DIR_LAB | IND_LAB, SEP, REG, 0},
		{REG | IND | DIR | DIR_LAB | IND_LAB, SEP, REG | IND | DIR
			| DIR_LAB | IND_LAB, SEP, REG, 0},
		{DIR | DIR_LAB, 0, 0, 0, 0, 0},
		{REG | IND | DIR | DIR_LAB | IND_LAB, SEP, REG | DIR
			| DIR_LAB, SEP, REG, 0},
		{REG, SEP, REG | IND | DIR | DIR_LAB | IND_LAB, SEP, REG
			| DIR | DIR_LAB, 0},
		{DIR | DIR_LAB, 0, 0, 0, 0, 0},
		{IND | DIR | DIR_LAB | IND_LAB, SEP, REG, 0, 0, 0},
		{REG | IND | DIR | DIR_LAB | IND_LAB, SEP, REG | DIR
			| DIR_LAB, SEP, REG, 0},
		{DIR | DIR_LAB, 0, 0, 0, 0, 0},
		{REG, 0, 0, 0, 0, 0}
	};
	return (tab[op]);
}

int		tab_check_end(t_lexer *lst)
{
	t_type	tab[2] = {STR, ENDOFLINE};

	if (lst->token == tab[1])
		return (ASM_SUCCESS);
	else if (lst->token == tab[0])
	{
		if (lst->next->token == tab[1])
			return (ASM_SUCCESS);
		else
			return (ASM_FAILURE);
	}
	else
		return (ASM_FAILURE);
}

int		tab_get_opcode(t_lexer *lst)
{
	char	*tab[17] = {"live", "ld", "st", "add", "sub", "and", "or", "xor"
						, "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork"
						, "aff", NULL};
	int		i;

	i = 0;
	while (i < 16 && ft_strcmp(lst->value, tab[i]) != 0)
		++i;
	return (i);
}

int		tab_check_line(t_lexer *lst)
{
	t_type	*tab;
	int		i;

	i = -1;
	if ((lst->token == ENDOFLINE) || (lst->token == COM))
		return (ASM_SUCCESS);
	if (lst->token != OP)
		return (ASM_FAILURE);
	tab = tab_return_table(tab_get_opcode(lst));
	lst = lst->next;
	while (tab[++ i])
	{
		if ((lst->token & tab[i]) == lst->token)
			lst = lst->next;
		else
			return (ASM_FAILURE);
	}
	return (tab_check_end(lst));
}
