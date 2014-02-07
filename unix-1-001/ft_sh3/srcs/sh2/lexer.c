/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 17:24:37 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 12:43:10 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	deal_with_escape_char(t_token *tok)
{
	t_token	*save;

	save = tok;
	while (tok)
	{
		if (tok->type == STDCHAR)
			tok->val = remove_escape_char_from_stdchar(tok->val);
		else if (tok->type == QUOTE)
			tok->val = remove_escape_char_from_quote(tok->val);
		tok = tok->next;
	}
	tok = save;
}

t_token	*build_list(t_token *tok, char *val, t_type type)
{
	t_token		*save;
	t_token		*new;

	save = tok;
	new = (t_token*)malloc(sizeof(t_token));
	new->val = ft_strdup(val);
	free(val);
	new->type = type;
	new->prev = NULL;
	new->next = NULL;
	if (tok == NULL)
		return (new);
	while (tok->next != NULL)
		tok = tok->next;
	tok->next = new;
	new->prev = tok;
	return (save);
}

t_token	*lexer(char *line)
{
	int			i;
	int			j;
	int			k;
	t_token		*tok;

	i = j = k = 0;
	tok = NULL;
	if (line == NULL)
		return (tok);
	while (line[i] != '\0')
	{
		j = 0;
		if (line[i] == ' ')
		{
			while ((line[i + j] == ' ' || line[i + j] == '\t'
					|| line[i + j] == '\n') && line[i + j] != '\0')
				j++;
			i += j - 1;
		}
		else
			tok = lexer_next(line, &i, tok);
		i++;
	}
	return (tok);
}

t_token	*lexer_next(char *line, int *i, t_token *tok)
{
	int		j;

	j = 1;
	if (line[*i] == '\"' && line[*i - 1] != '\\')
	{
		while (line[*i + j] != '\"' && line[*i + j] != '\0')
		{
			if (line[*i + j] == '\\')
				j += 2;
			j++;
		}
		tok = build_list(tok, ft_strsub(line, *i + 1, j - 1), QUOTE);
		*i += j;
	}
	else if (line[*i] == ';')
		tok = build_list(tok, ft_strsub(line, *i, 1), SEMICOLON);
	else if (line[*i] == '<' && line[*i + 1] != '<')
		tok = build_list(tok, ft_strsub(line, *i, 1), LREDIR);
	else
		tok = lexer_next_2(line, i, tok);
	return (tok);
}

t_token	*lexer_next_2(char *line, int *i, t_token *tok)
{
	int		j;

	j = 0;
	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		tok = build_list(tok, ft_strsub(line, *i, 2), LAREDIR);
		*i += 2;
	}
	else if (line[*i] == '>' && line[*i + 1] != '>')
		tok = build_list(tok, ft_strsub(line, *i, 1), RREDIR);
	else if (line[*i] == '>' && line[*i + 1] == '>')
	{
		tok = build_list(tok, ft_strsub(line, *i, 2), RAREDIR);
		*i += 1;
	}
	else if (line[*i] == '|')
		tok = build_list(tok, ft_strsub(line, *i, 1), PIPE);
	else
		tok = lexer_next_3(line, i, tok);
	return (tok);
}
