/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:27:06 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/17 17:25:22 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd	*cmd_createlldi(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("lldi");
	cmd->nb_arg = 3;
	cmd->has_encoding = 1;
	cmd->is_idx = 1;
	return (cmd);
}

void	cmd_movelexer(t_lexer **lexed)
{
	while (*lexed != NULL && (*lexed)->token != ENDOFLINE)
		(*lexed) = (*lexed)->next;
}
