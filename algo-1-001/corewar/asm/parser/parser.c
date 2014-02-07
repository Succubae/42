/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 11:56:29 by sbuono            #+#    #+#             */
/*   Updated: 2014/01/17 17:38:14 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <asm.h>

t_lexer		*par_parse_begining(t_lexer *lst)
{
	t_type	cod_lin[6] = {CMD_NAME, STR, ENDOFLINE, CMD_COM, STR, ENDOFLINE};
	int		i;

	i = -1;
	while ((lst->token == ENDOFLINE) || (lst->token == COM))
		lst = lst->next;
	while (++i < 6)
	{
		if (lst->token != cod_lin[i])
		{
			prt_err(1, lst);
			return (NULL);
		}
		lst = lst->next;
	}
	return (lst);
}

int			par_clear_lst(t_lexer **lst)
{
	t_lexer	*tmp;
	t_lexer	*tmp2;

	while ((*lst)->token > 4095)
	{
		tmp2 = *lst;
		*lst = (*lst)->next;
		free(tmp2->value);
		free(tmp2);
	}
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->next->token > 4095)
		{
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp2->value);
			free(tmp2);
		}
		else
			tmp = tmp->next;
	}
	return (ASM_SUCCESS);
}

int			par_clear_empty_line(t_lexer **lst)
{
	t_lexer		*tmp;
	t_lexer		*tmp2;

	while ((*lst)->token == ENDOFLINE)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->value);
		free(tmp);
	}
	tmp2 = *lst;
	while (tmp2->next)
	{
		if (tmp2->token == ENDOFLINE && tmp2->next->token == ENDOFLINE)
		{
			tmp = tmp2->next;
			tmp2->next = tmp2->next->next;
			free(tmp->value);
			free(tmp);
		}
		else
			tmp2 = tmp2->next;
	}
	return (ASM_SUCCESS);
}

int			par_parser(t_lexer *lst)
{
	int		line;

	line = 2;
	if ((lst = par_parse_begining(lst)) == NULL)
		return (ASM_FAILURE);
	while (line++, lst)
	{
		if (lst->token == LABEL)
		{
			lst = lst->next;
			if (lst->token != ENDOFLINE && lst->token != OP)
				return (prt_err(line, lst));
			else if (lst->token == OP)
			{
				if (tab_check_line(lst) == ASM_FAILURE)
					return (prt_err(line, lst));
			}
		}
		else if (tab_check_line(lst) == ASM_FAILURE)
			return (prt_err(line, lst));
		while (lst->token != ENDOFLINE)
			lst = lst->next;
		lst = lst->next;
	}
	return (ASM_SUCCESS);
}
