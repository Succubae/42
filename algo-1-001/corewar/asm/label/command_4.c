/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:24:46 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/14 18:24:47 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd	*cmd_createor(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("or");
	cmd->nb_arg = 3;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	return (cmd);
}

t_cmd	*cmd_createxor(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("xor");
	cmd->nb_arg = 3;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	return (cmd);
}

t_cmd	*cmd_createldi(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("ldi");
	cmd->nb_arg = 3;
	cmd->has_encoding = 1;
	cmd->is_idx = 1;
	return (cmd);
}

t_cmd	*cmd_createsti(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("sti");
	cmd->nb_arg = 3;
	cmd->has_encoding = 1;
	cmd->is_idx = 1;
	return (cmd);
}

t_cmd	*cmd_createlld(void)
{
	t_cmd	*cmd;

	cmd = cmd_create("lld");
	cmd->nb_arg = 2;
	cmd->has_encoding = 1;
	cmd->is_idx = 0;
	return (cmd);
}