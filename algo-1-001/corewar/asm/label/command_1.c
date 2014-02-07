/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:17:06 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/17 17:22:31 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd	*cmd_initvariables(t_cmd **list);

t_cmd	*cmd_create(char *name)
{
	t_cmd	*out;

	if ((out = (t_cmd *)ft_memalloc(sizeof(t_cmd))) == NULL)
		impossible_malloc("t_cmd in cmd_create");
	out->cmd = ft_strdup(name);
	out->next = NULL;
	out->size = CMD_DFL_SIZE;
	return (out);
}

void	cmd_pushfront(t_cmd **list, t_cmd *cmd)
{
	if (*list != NULL)
		cmd->next = *list;
	*list = cmd;
}

void	cmd_initlist(t_cmd **list)
{
	cmd_pushfront(list, cmd_createlive());
	cmd_pushfront(list, cmd_createzjmp());
	cmd_pushfront(list, cmd_createsub());
	cmd_pushfront(list, cmd_createadd());
	cmd_pushfront(list, cmd_createlfork());
	cmd_pushfront(list, cmd_createfork());
	cmd_pushfront(list, cmd_createld());
	cmd_pushfront(list, cmd_createst());
	cmd_pushfront(list, cmd_createand());
	cmd_pushfront(list, cmd_createor());
	cmd_pushfront(list, cmd_createxor());
	cmd_pushfront(list, cmd_createldi());
	cmd_pushfront(list, cmd_createsti());
	cmd_pushfront(list, cmd_createlld());
	cmd_pushfront(list, cmd_createlldi());
	cmd_pushfront(list, cmd_createaff());
}

t_cmd	*cmd_getcmd(char *name)
{
	static t_cmd	*cmd_list = NULL;
	t_cmd			*save;
	t_cmd			*tmp;

	tmp = NULL;
	if (cmd_list == NULL)
		cmd_initlist(&cmd_list);
	save = cmd_list;
	while (cmd_list)
	{
		if (ft_strcmp(name, cmd_list->cmd) == 0)
		{
			tmp = cmd_list;
			break ;
		}
		cmd_list = cmd_list->next;
	}
	cmd_list = save;
	return (tmp);
}

int		cmd_findsize(t_cmd *cmd, t_lexer **lexed)
{
	int	out;

	out = 0;
	if (cmd->has_encoding == 1)
		out += 1;
	while (*lexed != NULL && (*lexed)->token != ENDOFLINE)
	{
		if (((*lexed)->token == DIR) || ((*lexed)->token == DIR_LAB))
			out += ((cmd->is_idx == 1) ? IND_SIZE : DIR_SIZE);
		else if ((*lexed)->token == OP)
			out += 1;
		else if (((*lexed)->token == IND) || ((*lexed)->token == IND_LAB))
			out += IND_SIZE;
		else
			out += NB_ENC_REG;
		*lexed = (*lexed)->next;
	}
	return (out);
}
