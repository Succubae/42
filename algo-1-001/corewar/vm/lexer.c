/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 17:02:07 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 09:27:39 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			lex_pushback(t_lex **lex, char *ag, t_tok tmp2)
{
	t_lex	*new;
	t_lex	*tmp;

	if ((new = (t_lex *)ft_memalloc(sizeof(t_lex))) == NULL)
		kill_me("Bad malloc in lex_pushback");
	new->token = tmp2;
	new->value = ft_strdup(ag);
	new->next = NULL;
	if (*lex == NULL)
		*lex = new;
	else
	{
		tmp = *lex;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static t_tok	lex_gettoken(char *ag)
{
	if (ft_strcmp(ag, "-dump") == 0)
		return (DUMP);
	else if (ft_strcmp(ag, "-v") == 0)
		return (VERBOSE);
	else
		return (HERO_NUMB);
}

void			lexer_parser(t_lex **lex, char **ag)
{
	t_tok	tmp2;

	ag++;
	tmp2 = UNKNOWN;
	while (*ag)
	{
		if ((*ag)[0] == '-')
		{
			tmp2 = lex_gettoken(*ag);
			if (tmp2 == VERBOSE)
			{
				lex_pushback(lex, *ag, tmp2);
				tmp2 = UNKNOWN;
			}
		}
		else
		{
			tmp2 = (tmp2 == UNKNOWN ? HERO_FILE : tmp2);
			lex_pushback(lex, *ag, tmp2);
			tmp2 = UNKNOWN;
		}
		ag++;
	}
}

int				lex_checksyntax(t_lex *lex)
{
	int	nb_hero;

	nb_hero = 0;
	while (lex)
	{
		if (lex->token == HERO_NUMB)
		{
			if (lex->next == NULL || lex->next->token != HERO_FILE)
				ptr_err_heroneeded();
		}
		else if (lex->token == HERO_FILE)
			nb_hero++;
		lex = lex->next;
	}
	if (nb_hero == 0)
		ptr_err_scary();
	else if (nb_hero > 4)
		ptr_err_battleroyal();
	return (CORE_SUCCESS);
}
