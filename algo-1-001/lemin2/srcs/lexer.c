/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 11:34:28 by rgary             #+#    #+#             */
/*   Updated: 2014/02/17 16:49:08 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "lemin.h"

#include <stdio.h>
t_tok	*handle_command(char *line, t_tok *tok)
{
		if (ft_strcmp(line, STARTL) == 0)
		{
			tok = init_tok_list(tok, line, START);
			tok = init_tok_list(tok, "endline", ENDLINE);
			return (tok);
		}
		if (ft_strcmp(line, ENDL) == 0)
		{
			tok = init_tok_list(tok, line, END);
			tok = init_tok_list(tok, "endline", ENDLINE);
			return (tok);
		}
		else
		{
			tok = init_tok_list(tok, line, IGNORE);
			tok = init_tok_list(tok, "endline", ENDLINE);
			return (tok);
		}
}

t_tok	*build_list_each_line(t_tok *tok, char *line, int *err)
{
	int			i;
	int			j;
	char		*tokblok;
	static int	ln = 0;


	i = j = 0;
	ln += 1;
	if (line[0] == '#' && line[1] == '#')
		return (tok = handle_command(line, tok));
	else if (line[0] == '#' && line[1] != '#')
		return (tok = init_tok_list(tok, line, COMMENT));
	else if (line[0] == '\0')
	{
		*err = 1;
		return (tok);
	}
	else if (ft_strichr(NAMEL, line[0]) != -1)
	{
		while (j = 0, line[i] != '\0')
		{
			if (ft_strichr(NAMEL, line[i]) == -1)
			{
				ft_error_4("Lexing error on line ", ft_itoa(ln), " for ", line);
				*err = 1;
				return (tok);
			}
			while (line[i + j] != '\0' && ft_strichr(NAMEL, line[i + j]) != -1)
				j++;
			if (j != 0)
			{
				tokblok = ft_strsub(line, i, j);
				tok = init_tok_list(tok, tokblok, NAME);
				free_one(tokblok);
			}
			i += j + 1;
		}
		return (tok = init_tok_list(tok, "endline", ENDLINE));
	}
	*err = 1;
	return (tok);
}

t_tok	*build_lex_list(void)
{
	int		ret;
	int		err;
	char	*line;
	t_tok	*tok;

	tok = NULL;
	err = 0;
	while ((ret = get_next_line(0, &line)) > 0 && err == 0)
	{
		tok = build_list_each_line(tok, line, &err);
		free_one(line);
	}
	return (tok);
}
