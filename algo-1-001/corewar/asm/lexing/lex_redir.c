/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwagner <cwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 11:45:08 by cwagner           #+#    #+#             */
/*   Updated: 2014/02/02 14:54:16 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

static void	putsep(t_lexer **list, char *word)
{
	word[ft_strlen(word)] = ',';
	lex_addlex(list, ",", SEP);
}

int			lex_tablex(t_lexer **list, char *word)
{
	int		j;
	int		sep;
	int		(*funcs[NBR_TOK])(t_lexer **list, char *word) =
		{lex_iscmd_name, lex_iscmd_com, lex_iscmd, lex_isreg,
		lex_isdirlab, lex_isdir, lex_islab, lex_isind};

	j = sep = 0;
	if (word[0] == SEPARATOR_CHAR)
	{
		lex_addlex(list, ",", SEP);
		word++;
	}
	if (word[ft_strlen(word) - 1] == SEPARATOR_CHAR)
	{
		sep = 1;
		word[ft_strlen(word) - 1] = '\0';
	}
	while (j < NBR_TOK && (funcs[j])(list, word) == ASM_FAILURE)
		j++;
	if (sep)
		putsep(list, word);
	if (j == NBR_TOK)
		return (ASM_FAILURE);
	return (ASM_SUCCESS);
}
