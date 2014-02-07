/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 10:30:30 by rgary             #+#    #+#             */
/*   Updated: 2014/02/06 16:21:04 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	free_tok_list(t_token *tok)
{
	t_token	*tmp;

	while (tok->next != NULL)
	{
		tok = tok->next;
	}
	while (tok)
	{
		tmp = tok->prev;
		free(tok->val);
		free(tok);
		tok = tmp;
	}
}

void	free_tree(t_ast *ast)
{
	t_ast	*tmp;

	while (ast != NULL)
	{
		tmp = ast->parent;
		if (ast->left != NULL)
			free(ast->left);
		free(ast->right);
		free(ast);
		ast = tmp;
	}
}
