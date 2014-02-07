/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:49:25 by rgary             #+#    #+#             */
/*   Updated: 2014/02/01 17:38:15 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"

void			enc_find_label_jmp_adrss(t_lexer *lex, t_adr *adr, t_label *lab)
{
	t_label	*save;
	int		i;

	i = 0;
	save = lab;
	while (lab != NULL)
	{
		if (ft_strcmp(ft_strjoinc(lex->value + 2, ':'), lab->name) == 0)
		{
			if (adr->linepos > lab->address)
				i = 65536 + lab->address - adr->linepos;
			else
				i = lab->address - adr->linepos;
			i = swa_swap_int_by_params(i, IND_SIZE);
			write(adr->fd, &i, IND_SIZE);
			adr->currentpos += 2;
			break ;
		}
		lab = lab->next;
	}
	lab = save;
}

static t_lexer	*enc_write_op(t_lexer *lexer, t_adr *adr, int *openable, int i)
{
	char	*op[16] = {"live", "ld", "st", "add", "sub", "and", "or", "xor",
						"zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork",
						"aff"};
	char	*opcode[4] = {"live", "zjmp", "fork", "lfork"};

	if (LVAL("sti") || LVAL("ldi") || LVAL("lldi") || LVAL("zjmp")
		|| LVAL("lfork") || LVAL("fork"))
		adr->getindex = 1;
	if (ft_strcmp(lexer->value, "live") == 0)
		adr->onlive = 1;
	while (ft_strcmp(op[i], lexer->value) != 0)
		i++;
	i++;
	write(adr->fd, &i, 1);
	adr->currentpos += 1;
	i = -1;
	while (i++, i < 4)
	{
		if (ft_strcmp(opcode[i], lexer->value) == 0)
			*openable = 1;
	}
	lexer = lexer->next;
	return (lexer);
}

static t_lexer	*enc_fill_file(t_lexer *lexer, t_adr *adr, t_label *label)
{
	int		i;
	int		openable;

	i = openable = 0;
	if (lexer->token == OP)
		lexer = enc_write_op(lexer, adr, &openable, i);
	else
		return (lexer);
	while (lexer->token != ENDOFLINE)
	{
		if (openable == 0)
			wri_calc_opcode(lexer, adr, label);
		if (adr->onlive == 1)
			lexer = pri_print_live_params_values(lexer, adr);
		else
			lexer = pri_print_params_values(lexer, adr, label);
	}
	return (lexer);
}

static void		enc_delete_lists(t_start *start, t_label *label, t_adr *adr)
{
	t_label	*ltmp;
	t_lexer	*tmp;

	while (start->lexer != NULL)
	{
		tmp = start->lexer;
		start->lexer = start->lexer->next;
		free(tmp->value);
		free(tmp);
	}
	while (label != NULL)
	{
		ltmp = label;
		label = label->next;
		free(ltmp->name);
		free(ltmp);
	}
	free(start->filename);
	free(start->name);
	free(start->comment);
	free(start);
	free(adr);
}

int				enc_encoding(t_start *start, t_label *label)
{
	t_adr	*adr;

	wri_change_name(start);
	adr = (t_adr *)malloc(sizeof(t_adr));
	adr->linepos = 0;
	if ((adr->fd = open(start->filename, CTW, 0644)) < 0)
		kill_me("Impossible to create output file");
	wri_write_name_and_comment(start, adr);
	while (start->lexer != NULL && start->lexer->token != OP)
		start->lexer = start->lexer->next;
	while (start->lexer != NULL)
	{
		adr->currentpos = 0;
		adr->getindex = 0;
		adr->index = 0;
		adr->onlive = 0;
		start->lexer = enc_fill_file(start->lexer, adr, label);
		start->lexer = start->lexer->next;
		adr->linepos += adr->currentpos;
	}
	enc_delete_lists(start, label, adr);
	return (0);
}
