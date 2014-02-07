/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:46:45 by rgary             #+#    #+#             */
/*   Updated: 2014/01/14 17:46:42 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"

t_lexer  *pri_print_live_params_values(t_lexer *lexer, t_adr *adr)
{
	int	i;

	i = swa_swap_char_by_params(lexer->value, 4, 0);
	write(adr->fd, &i, 4);
	adr->currentpos += 4;
	lexer = lexer->next;
	return (lexer);
}

t_lexer  *pri_print_params_values(t_lexer *lexer, t_adr *adr, t_label *label)
{
	int	i;
	int	j;

	j = 0;
	while (j++, lexer->token != ENDOFLINE)
	{
		if (lexer->token == DIR)
			wri_write_direct(lexer, adr);
		if (lexer->token == IND)
		{
			i = swa_swap_char_by_params(lexer->value, IND_SIZE, 1);
			write(adr->fd, &i, IND_SIZE);
			adr->currentpos += 2;
		}
		if (lexer->token == REG)
		{
			i = ft_atoi(lexer->value + 1);
			write(adr->fd, &i, NB_ENC_REG);
			adr->currentpos += 1;
		}
		if (lexer->token == DIR_LAB)
			enc_find_label_jmp_adrss(lexer, adr, label);
		lexer = lexer->next;
	}
	return (lexer);
}
