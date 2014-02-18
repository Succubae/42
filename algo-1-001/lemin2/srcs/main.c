/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 09:52:49 by rgary             #+#    #+#             */
/*   Updated: 2014/02/17 18:29:17 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

#include <stdio.h>

t_info	*info_structs(void)
{
	static t_info	*info = NULL;

	if (info == NULL)
	{
		info = (t_info*)malloc(sizeof(t_info));
		info->ant = 0;
		info->start = NULL;
		info->end = NULL;
		return (info);
	}
	else
		return (info);
}

#include <unistd.h>
int		main(void)
{
	t_info	*info;
	t_tok	*tok;

	info = info_structs();
	if ((tok = build_lex_list()) == NULL)
		ft_error_1("Parse Error at line 0 : . No information");
/*	while (tok != NULL)
	{
		printf("type = %d | val = %s\n", tok->type, tok->val);
		tok = tok->next;
		}*/
	get_info(info, tok);
	return (0);
}
