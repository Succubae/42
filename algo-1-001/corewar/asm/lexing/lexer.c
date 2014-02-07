/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:01:16 by cwagner           #+#    #+#             */
/*   Updated: 2014/01/18 15:32:35 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
static int	lex_comment(t_lexer **list, char **tab, int j)
{
	char	*str;

	str = "";
	while (tab[j])
	{
		str = ft_strjoin(str, tab[j]);
		if (tab[j + 1])
			str = ft_strjoin(str, " ");
		j++;
	}
	if (!str)
		return (ASM_FAILURE);
	if (str[0] == '"')
	{
		if (str[ft_strlen(str) - 1] == '"')
			lex_addlex(list, str, STR);
		else
			return (ASM_FAILURE);
	}
	free(str);
	return (ASM_SUCCESS);
}

static int	lex_line(t_lexer **list, char *str, int line)
{
	char	**tab;
	int		j;

	j = 0;
	tab = ft_strsplitwhite(str);
	while (tab[j])
	{
		if (*(tab[j]) == COMMENT_CHAR || *(tab[j]) == '#' || *(tab[j]) == '"')
			return (lex_comment(list, tab, j));
		else
		{
			if (lex_tablex(list, tab[j]) == ASM_FAILURE)
				return (lex_error(tab, line, j));
		}
		j++;
	}
	return (ASM_SUCCESS);
}

t_lexer			*lex_lexer(int fd)
{
	char	*str;
	t_lexer	*list;
	int		ret;
	int		line;

	str = NULL;
	list = NULL;
	line = 1;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (lex_line(&list, str, line) == ASM_FAILURE)
			return (NULL);
		if (ret != 0)
			lex_addlex(&list, "", ENDOFLINE);
		line++;
	}
	if (ret == -1)
	{
		ft_putendl_fd("An error occured while reading file", 2);
		return (NULL);
	}
	return (list);
}
