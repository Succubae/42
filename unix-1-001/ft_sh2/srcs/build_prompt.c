/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:00:42 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 18:13:05 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	start_commands(char *line, char **env, char **path)
{
	int		ret;
	t_token	*tok;
	t_ast	*ast;

	if ((tok = lexer(line)) == NULL)
		;
	else
	{
		deal_with_escape_char(&tok);
		if ((ret = parser(tok)) == -1)
			ft_error("ME CAY TRAUZORIBLE !!!!");
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

void	create_prompt(char **env)
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
	home = GE("HOME");
	pwd = GE("PWD");
	while (pwd[i] == home[i])
		i++;
	if (i != (int)ft_strlen(home))
		prompt = ft_strcat(prompt, pwd);
	else
		create_prompt2(pwd, prompt, i, j);
	FP("%s > ", prompt);
}
