/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 17:33:22 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 14:47:11 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_edit.h"

char	*retrieve_prompt(char *prompt)
{
	static char	*lol = NULL;

	if (prompt == NULL)
		return (lol);
	else
		lol = prompt;
	return (lol);
}

void	print_prompt(char *prompt)
{
	ft_putstr("\033[1;35m");
	FP("%s > ", prompt);
	ft_putstr("\033[0m");
}

int		create_prompt(char **env)
{
	char	*prompt;
	char	*tmp = "Ouvre le README";
	int		i;

	(void)env;
	i = ft_strlen(tmp);
	prompt = (char*)malloc(sizeof(char) * (i + 1));
	i = -1;
	while (i++, tmp[i] != '\0')
		prompt[i] = tmp[i];
	prompt[i] = '\0';
	retrieve_prompt(prompt);
	print_prompt(prompt);
	return (1);
}

void	ft_error(char *s)
{
	FP2("42sh: ", 2);
	FP2(s, 2);
	FP2(".\n", 2);
}
