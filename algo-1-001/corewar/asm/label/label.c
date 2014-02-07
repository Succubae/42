/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:08:50 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/14 16:20:59 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*lab_create(t_lexer *lex, int cur_pos)
{
	t_label	*out;

	if ((out = (t_label *)ft_memalloc(sizeof(t_label))) == NULL)
		impossible_malloc("t_label in lab_create");
	out->name = ft_strdup(lex->value);
	out->address = cur_pos;
	out->next = NULL;
	return (out);
}

int	lab_addlabel(t_label **lb, t_lexer *lex, int cur_pos)
{
	t_label	*new;
	t_label	*save;

	new = lab_create(lex, cur_pos);
	if (*lb == NULL)
		*lb = new;
	else
	{
		save = *lb;
		while ((*lb)->next != NULL)
			*lb = (*lb)->next;
		(*lb)->next = new;
		*lb = save;
	}
	return (cur_pos);
}

int	lab_getsizebytype(t_lexer **lexed)
{
	int		out;
	t_cmd	*cmd;

	if ((cmd = cmd_getcmd((*lexed)->value)) == NULL)
	{
		ft_putstr_fd((*lexed)->value, 2);
		ft_putchar_fd('\n', 2);
		kill_me("Oups... command is not define");
	}
	if (cmd->size != CMD_DFL_SIZE)
	{
		out = cmd->size;
		cmd_movelexer(lexed);
	}
	else
		out = cmd_findsize(cmd, lexed);
	return (out);
}

int	lab_getelemsize(t_lexer **lexed, t_start **st)
{
	if ((*lexed)->token == CMD_NAME)
	{
		(*st)->name = (*lexed)->next->value;
		cmd_movelexer(lexed);
	}
	else if ((*lexed)->token == CMD_COM)
	{
		(*st)->comment = (*lexed)->next->value;
		cmd_movelexer(lexed);
	}
	else
		return (lab_getsizebytype(lexed));
	return (0);
}

int	lab_firstpass(char *file, t_lexer *lexed, t_start **st, t_label **lb)
{
	int	current_pos;

	if (sta_init(st, file) != ASM_SUCCESS)
		return (ASM_FAILURE);
	(*st)->lexer = lexed;
	current_pos = 0;
	while (lexed)
	{
		if (lexed->token != ENDOFLINE)
		{
			if (lexed->token == LAB)
				current_pos = lab_addlabel(lb, lexed, current_pos);
			else
				current_pos += lab_getelemsize(&lexed, st);
		}
		if (!lexed)
			break ;
		lexed = lexed->next;
	}
	if (lab_check((*st)->lexer, *lb) != ASM_SUCCESS)
		return (ASM_FAILURE);
	(*st)->prog_size = current_pos;
	return (ASM_SUCCESS);
}