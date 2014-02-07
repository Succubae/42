/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:22:16 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/17 17:25:14 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd	*cmd_createfork(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("fork");
	cmd->nb_arg = 1;
	cmd->has_encoding = 0;
	cmd->is_idx = 1;
	cmd->size = 1 + IND_SIZE;
	return (cmd);
}

t_cmd	*cmd_createaff(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("aff");
	cmd->nb_arg = 1;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	cmd->size = 2 + NB_ENC_REG;
	return (cmd);
}

t_cmd	*cmd_createld(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("ld");
	cmd->nb_arg = 2;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	return (cmd);
}

t_cmd	*cmd_createst(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("st");
	cmd->nb_arg = 2;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	return (cmd);
}

t_cmd	*cmd_createand(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("and");
	cmd->nb_arg = 3;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	return (cmd);
}
