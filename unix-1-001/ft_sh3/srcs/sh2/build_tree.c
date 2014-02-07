/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 10:17:45 by rgary             #+#    #+#             */
/*   Updated: 2014/02/06 16:07:50 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

char	*build_cmd_line(char *cmd, char *val)
{
	char	*tmp;

	tmp = NULL;
	if (cmd == NULL)
	{
		cmd = ft_strdup(val);
		return (cmd);
	}
	else
	{
		tmp = ft_strjoin(cmd, " ");
		free(cmd);
		cmd = tmp;
		tmp = ft_strjoin(cmd, val);
		free(cmd);
	}
	return (tmp);
}

char	*fill_next_command(t_token **tok, char *cmd)
{
	while ((*tok) && ((*tok)->type == STDCHAR || (*tok)->type == QUOTE))
	{
		cmd = build_cmd_line(cmd, (*tok)->val);
		(*tok) = (*tok)->next;
	}
	return (cmd);
}

t_ast	*build_branch(t_ast *ast, t_token **tok, char *cmd)
{
	char	*nextcmd;
	t_ast	*new;

	nextcmd = NULL;
	new = (t_ast*)malloc(sizeof(t_ast));
	new->type = (*tok)->type;
	(*tok) = (*tok)->next;
	nextcmd = fill_next_command(tok, nextcmd);
	if (ast != NULL)
	{
		new->leftcmd = ast;
		new->left = NULL;
		ast->parent = new;
	}
	else
	{
		if (cmd)
			new->left = ft_strdup(cmd);
		new->leftcmd = NULL;
	}
	new->parent = NULL;
	new->right = nextcmd;
	return (new);
}

t_ast	*build_tree(t_token *tok)
{
	t_ast	*ast;
	char	*cmd;
	t_token	*save;

	cmd = NULL;
	ast = NULL;
	if (tok == NULL)
		ft_error("Empty Command line");
	save = tok;
	while (tok != NULL)
	{
		cmd = fill_next_command(&tok, cmd);
		ast = build_branch(ast, &tok, cmd);
		free(cmd);
		cmd = NULL;
	}
	while (save != NULL)
	{
		tok = save;
		save = save->next;
		free(tok->val);
		free(tok);
	}
	return (ast);
}
