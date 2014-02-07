/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_funcs1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwagner <cwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 12:39:29 by cwagner           #+#    #+#             */
/*   Updated: 2014/01/17 19:15:36 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

int			lex_iscmd_name(t_lexer **list, char *word)
{
	int		ret;

	ret = ft_strcmp(word, NAME_CMD_STRING);
	if (!ret)
	{
		lex_addlex(list, word, CMD_NAME);
		return (ASM_SUCCESS);
	}
	return (ASM_FAILURE);
}

int			lex_iscmd_com(t_lexer **list, char *word)
{
	int		ret;

	ret = ft_strcmp(word, COMMENT_CMD_STRING);
	if (!ret)
	{
		lex_addlex(list, word, CMD_COM);
		return (ASM_SUCCESS);
	}
	return (ASM_FAILURE);
}

int			lex_iscmd(t_lexer **list, char *word)
{
	char	*cmd[16] = \
		{"lfork", "sti", "fork", "lld", "ld", "add", "zjmp",
		"sub", "ldi", "or", "st", "aff", "live", "xor", "lldi", "and"};
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(word, cmd[i]) == 0)
		{
			lex_addlex(list, word, OP);
			return (ASM_SUCCESS);
		}
		i++;
	}
	return (ASM_FAILURE);
}

int			lex_strnum(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (ASM_FAILURE);
		i++;
	}
	return (ASM_SUCCESS);
}

int			lex_isreg(t_lexer **list, char *word)
{
	if (*word == 'r')
	{
		word++;
		if (lex_strnum(word) == ASM_SUCCESS && ft_atoi(word) >= 0 && \
			ft_atoi(word) <= REG_NUMBER)
		{
			lex_addlex(list, --word, REG);
			return (ASM_SUCCESS);
		}
	}
	return (ASM_FAILURE);
}

