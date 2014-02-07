/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_existence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:19:42 by mfaye             #+#    #+#             */
/*   Updated: 2014/01/17 17:19:43 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static char	*lab_sanitizelexerlabel(t_lexer *lexer)
{
	size_t	len;
	char	*out;

	len = ft_strlen(lexer->value);
	len = (lexer->token == DIR_LAB ? len - 2 : len - 1);
	if ((out = ft_strnew(len + 1)) == NULL)
		impossible_malloc("char in lab_sanitizelexerlabel");
	ft_memcpy(out, (lexer->value + 2), len);
	return (out);
}

static char	*lab_sanitizelabel(char *label)
{
	size_t	len;
	char	*out;

	len = ft_strlen(label);
	if ((out = ft_strnew(len)) == NULL)
		impossible_malloc("char in lab_sanitizelabel");
	ft_memcpy(out, label, len - 1);
	return (out);
}

static int	lab_checkexistence(t_lexer *lexer, t_label *label)
{
	t_label	*tmp;
	char	*lex_label;
	char	*lab_label;

	tmp = label;
	lex_label = lab_sanitizelexerlabel(lexer);
	while (tmp)
	{
		lab_label = lab_sanitizelabel(tmp->name);
		if (ft_strcmp(lex_label, lab_label) == 0)
		{
			free(lab_label);
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		err_badlabel(lex_label);
		free(lex_label);
		return (ASM_FAILURE);
	}
	free(lex_label);
	return (ASM_SUCCESS);
}

int			lab_check(t_lexer *lexer, t_label *label)
{
	while (lexer)
	{
		if (lexer->token == DIR_LAB || lexer->token == IND_LAB)
		{
			if (lab_checkexistence(lexer, label) != ASM_SUCCESS)
				return (ASM_FAILURE);
		}
		lexer = lexer->next;
	}
	return (ASM_SUCCESS);
}