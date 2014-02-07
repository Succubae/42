/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 10:35:56 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 17:23:13 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	parse_error(char *tok)
{
	FP2("Minishell: parse error near ", 2);
	FP2(tok, 2);
	FP2(".\n", 2);
}

int		check_legality(t_token *tok, int *type)
{
	int		i;

	i = 0;
	while (type[i] != -1)
	{
		if ((int)tok->type == type[i])
			return (0);
		i++;
	}
	return (-1);
}

t_sh2	*build_tab(void)
{
	static t_sh2	*tab = NULL;

	if (tab != NULL)
		return (tab);
	tab = (t_sh2*)malloc(sizeof(t_sh2) * 9);
	tab[QUOTE] = check_quote;
	tab[LREDIR] = check_lredir;
	tab[RREDIR] = check_rredir;
	tab[LAREDIR] = check_laredir;
	tab[RAREDIR] = check_raredir;
	tab[PIPE] = check_pipe;
	tab[SEMICOLON] = check_semicolon;
	tab[WHITESPACE] = check_whitespace;
	tab[STDCHAR] = check_stdchar;
	tab[ENDOFLINE] = check_endofline;
	return (tab);
}

int		parser(t_token *tok)
{
	int		i;
	int		j;
	t_sh2	*tab;
	t_token	*save;

	j = 0;
	tab = build_tab();
	save = tok;
	while (save != NULL)
	{
		if (save->type != STDCHAR && save->type != QUOTE)
			j++;
		i = (tab[save->type])(save);
		if (i == -1)
			return (-1);
		save = save->next;
	}
	return (j);
}
