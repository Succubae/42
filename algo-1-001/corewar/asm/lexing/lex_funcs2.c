/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwagner <cwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 15:50:04 by cwagner           #+#    #+#             */
/*   Updated: 2014/01/17 19:15:11 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

int			lex_islabelchars(char *str)
{
	int		i;
	int		j;

	i = j = 0;
	while (str[i])
	{
		while (LABEL_CHARS[j])
		{
			if (str[i] == LABEL_CHARS[j])
				break ;
			j++;
		}
		if (!LABEL_CHARS[j])
			return (ASM_FAILURE);
		j = 0;
		i++;
	}
	return (ASM_SUCCESS);
}

int			lex_isdirlab(t_lexer **list, char *word)
{
	if (word[0] == DIRECT_CHAR && word[1] == LABEL_CHAR)
	{
		if (lex_islabelchars(word + 2) == ASM_SUCCESS)
		{
			lex_addlex(list, word, DIR_LAB);
			return (ASM_SUCCESS);
		}
	}
	return (ASM_FAILURE);
}

int			lex_isdir(t_lexer **list, char *word)
{
	if (word[0] == DIRECT_CHAR && lex_strnum(word + 1) == ASM_SUCCESS)
	{
		lex_addlex(list, word, DIR);
		return (ASM_SUCCESS);
	}
	return (ASM_FAILURE);
}

int			lex_islab(t_lexer **list, char *word)
{
	if (word[ft_strlen(word) - 1] == LABEL_CHAR)
	{
		word[ft_strlen(word) - 1] = '\0';
		if (lex_islabelchars(word) == ASM_FAILURE)
			return (ASM_FAILURE);
		word[ft_strlen(word)] = LABEL_CHAR;
		lex_addlex(list, word, LAB);
		return (ASM_SUCCESS);
	}
	return (ASM_FAILURE);
}

int			lex_isind(t_lexer **list, char *word)
{
	int			i;

	i = 0;
	if (word[i] == '-')
		i++;
	while (word[i] && ft_isdigit(word[i]))
		i++;
	if (!word[i])
	{
		lex_addlex(list, word, IND);
		return (ASM_SUCCESS);
	}
	return (ASM_FAILURE);
}
