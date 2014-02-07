/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:00:42 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 12:39:25 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	start_commands(char *line, char ***env, char **path)
{
	int		ret;
	t_token	*tok;
	t_ast	*ast;

	tok = NULL;
	if ((tok = lexer(line)) == NULL)
		;
	else
	{
		deal_with_escape_char(tok);
		if ((ret = parser(tok)) == -1)
			return ;
		else if (ret == 0 && tok)
			execute_command(tok, env, path);
		else
		{
			ast = build_tree(tok);
			execute_tree(ast, env, path);
		}
	}
}

void	create_prompt2(char *pwd, char *prompt, int i, int j)
{
	while (j < 100 && pwd[i] != '\0')
	{
		prompt[j + 1] = pwd[i + 1];
		j++;
		i++;
	}
}

char	*retrieve_prompt(char *prompt)
{
	static char	*save = NULL;

	if (prompt != NULL)
	{
		if (save != NULL)
			free(save);
		save = ft_strdup(prompt);
		return (prompt);
	}
	return (save);
}

void	print_prompt(char *prompt)
{
	prompt = retrieve_prompt(prompt);
	ft_putstr("\033[1;35m");
	FP("%s > ", prompt);
	ft_putstr("\033[0m");
}

int		create_prompt(char **env)
{
	int		i;
	int		j;
	char	*home;
	char	*pwd;
	char	*prompt;

	i = j = -1;
	prompt = ft_strnew(100);
	home = GE("USER");
	while (i++, home[i] != '\0')
		prompt[i] = home[i];
	j = i;
	i = 0;
	prompt[j] = '@';
	free(home);
	home = GE("HOME");
	pwd = GE("PWD");
	create_prompt3(home, pwd, prompt, j);
	return (1);
}
