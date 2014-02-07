/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 12:37:24 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 12:43:04 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	create_prompt3(char *home, char *pwd, char *prompt, int j)
{
	int		i;

	i = 0;
	while (pwd[i] == home[i])
		i++;
	if (i != (int)ft_strlen(home))
		prompt = ft_strcat(prompt, pwd);
	else
		create_prompt2(pwd, prompt, i, j);
	free(home);
	free(pwd);
	print_prompt(prompt);
	free(prompt);
}

t_token	*lexer_next_3(char *line, int *i, t_token *tok)
{
	int		j;

	j = 0;
	if (IS_STDCHAR)
	{
		while (IS_STDCHAR && line[*i + j] != '\0')
		{
			if (line[*i + j] == '\\')
				j += 2;
			j++;
		}
		tok = build_list(tok, ft_strsub(line, *i, j), STDCHAR);
		*i += j - 1;
	}
	return (tok);
}
