/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:18:13 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/14 18:18:14 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd	*cmd_createlive(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("live");
	cmd->nb_arg = 1;
	cmd->has_encoding = 0;
	cmd->is_idx = 0;
	cmd->size = 1 + DIR_SIZE;
	return (cmd);
}

t_cmd	*cmd_createzjmp(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("zjmp");
	cmd->nb_arg = 1;
	cmd->has_encoding = 0;
	cmd->is_idx = 1;
	cmd->size = 1 + IND_SIZE;
	return (cmd);
}

t_cmd	*cmd_createsub(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("sub");
	cmd->nb_arg = 3;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	cmd->size = 2 + 3 * NB_ENC_REG;
	return (cmd);
}

t_cmd	*cmd_createadd(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("add");
	cmd->nb_arg = 3;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	cmd->size = 2 + 3 * NB_ENC_REG;
	return (cmd);
}

t_cmd	*cmd_createlfork(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("lfork");
	cmd->nb_arg = 1;
	cmd->has_encoding = 0;
	cmd->is_idx = 1;
	cmd->size = 1 + IND_SIZE;
	return (cmd);
}