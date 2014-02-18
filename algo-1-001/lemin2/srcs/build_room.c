/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 11:19:03 by rgary             #+#    #+#             */
/*   Updated: 2014/02/18 11:25:25 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include "lemin.h"

t_tok	*tok_push_back(t_tok *old, t_tok *new)
{
	t_tok	*save;

	save = old;
	if (old == NULL)
		return (new);
	while (old->next != NULL)
		old = old->next;
	old->next = new;
	return (save);
}

t_room	*room_push_back(t_room *old, t_room *new)
{
	t_room	*save;

	save = old;
	if (old == NULL)
		return (new);
	while (old->next != NULL)
		old = old->next;
	old->next = new;
	return (save);
}

t_tok	*init_tok_list(t_tok *tok, char *line, t_type type)
{
	t_tok	*new;

	new = (t_tok*)malloc(sizeof(t_tok));
	new->type = type;
	new->val = ft_strdup(line);
	new->next = NULL;
	tok = tok_push_back(tok, new);
	return (tok);
}
/*
char	*check_for_invalid_command(char *line)
{
	char	*save;
	char	**tab;

	save = ft_strdup(line);
	free_one(line);
	if (get_next_line(0, &line) > 0)
	{
		(*info)->name =
	}
	else
		ft_error("Parse Error. Informations required after ", save);
	free_one(save);
}*/

t_room	*init_room(t_tok **tok, t_room *room)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room));
	while ((*tok)->type != 3)
		(*tok) = (*tok)->next;
	new->name = ft_strdup((*tok)->val);
	(*tok) = (*tok)->next;
	new->posx = ft_atoi((*tok)->val);
	(*tok) = (*tok)->next;
	new->posy = ft_atoi((*tok)->val);
	new->pipe = NULL;
	new->next = NULL;
	room = room_push_back(room, new);
	return (room);
}
