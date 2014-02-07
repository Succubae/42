/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwagner <cwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:32:07 by cwagner           #+#    #+#             */
/*   Updated: 2014/01/17 15:10:52 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

static t_lexer	*lex_newlist(char *str, t_type type)
{
	t_lexer		*list;

	list = (t_lexer *) malloc(sizeof(t_lexer));
	list->token = type;
	list->value = ft_strdup(str);
	list->next = NULL;
	return (list);
}

void			lex_addlex(t_lexer **list, char *str, t_type type)
{
	static t_lexer	*last = NULL;

	if (!last)
	{
		*list = lex_newlist(str, type);
		last = *list;
	}
	else
	{
		last->next = lex_newlist(str, type);
		last = last->next;
	}
}

int				lex_printlist(t_lexer **list)
{
	t_lexer		*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		ft_printf("[%d\t][%s]\n", tmp->token, tmp->value);
		tmp = tmp->next;
	}
	return (1);
}
