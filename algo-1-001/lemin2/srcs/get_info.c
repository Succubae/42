/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 09:55:21 by rgary             #+#    #+#             */
/*   Updated: 2014/02/18 12:06:42 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "lemin.h"
/*
void	fill_start_and_end(t_info **info, char *line)
{
	t_room	*start;

	start = init_room();
	if (ft_strcmp(line, "##start") == 0)
	{
		check_for_invalid_command(info, line);
		(*info)->start
	}
}
*/
void	check_and_fill_ant_nbr(t_info **info, char *line)
{
	if (line[0] >= '0' && line[0] <= '9')
		(*info)->ant = ft_atoi(line);
	else
		ft_error_2("Error in parsing ant number. "
				, "First param must be the ant number");
	if ((*info)->ant < 1)
		ft_error_2("Error in parsing ant number. ", "Ant number must be > 0");
}

#include <stdio.h>

int		find_arg_number(t_tok *tok)
{
	int		i;

	i = 0;
	while (tok != NULL && tok->type != 3)
	{
		i++;
		tok = tok->next;
	}
	while (tok != NULL && tok->type != 6)
	{
		i++;
		tok = tok->next;
	}
	return (i);
}

t_room	*copy_room(t_room *ori)
{
	t_room	*cpy;

	cpy = (t_room*)malloc(sizeof(t_room));
	cpy->name = ft_strdup(ori->name);
	cpy->posx = ori->posx;
	cpy->posy = ori->posy;
	cpy->pipe = NULL;
	cpy->next = NULL;
	return (cpy);
}

t_pipe	*pipe_push_back(t_pipe *old, t_pipe *new)
{
	t_pipe	*save;

	save = old;
	if (old == NULL)
		return (new);
	while (old->next != NULL)
		old = old->next;
	old->next = new;
	return (save);
}

t_pipe	*build_pipe_list(t_room *room, t_room *save)
{
	t_pipe	*pipe;

	pipe = (t_pipe*)malloc(sizeof(t_pipe));
	pipe->list = save;
	pipe->next = NULL;
	room->pipe = pipe_push_back(room->pipe, pipe);
	return (room->pipe);
}

void	connection_list(t_tok *tok, t_room *room, t_room *bgn_lst)
{
	t_room	*save;
/*	t_room	*tmp;*/

/*	while (tok != NULL)
	{*/
		save = bgn_lst;
		while (save != NULL)
		{
			if (ft_strcmp(save->name, tok->val) == 0)
			{
				printf("save = %s, tok = %s\n", save->name, tok->val);
				room->pipe = build_pipe_list(room, save);
			}
			save = save->next;
		}
/*		tok = tok->next;
		}*/
}

void	get_info(t_info *info, t_tok *tok)
{
	t_tok	*save;
/*	t_tok	*tmp;*/
	int		i;
	t_room	*saveroom;

	save = tok, i = -1;
	info->ant = ft_atoi(tok->val);
	tok = tok->next;
	while (tok != NULL)
	{
		if (find_arg_number(tok) == 4)
			info->list = init_room(&tok, info->list);
		else
			tok = tok->next;
	}
	tok = save->next->next;
	while (tok != NULL)
	{
		saveroom = info->list;
		if (find_arg_number(tok) == 3)
		{
/*			tok = tok->next;*/
			printf("tok = %s\n", tok->val);
			while (saveroom != NULL)
			{
				printf("saveroom = %s\n", saveroom->name);
				if (ft_strcmp(tok->val, saveroom->name) == 0)
				{
					printf("Quand je rentre ici saveroom = %s et tok = %s\n", saveroom->name, tok->val);
					connection_list(save->next->next, saveroom, info->list);
				}
				saveroom = saveroom->next;
				/*CREER LES TUBES ICI*/
			}
		}
		tok = tok->next;
	}
	while (info->list != NULL)
	{
		printf("name = %s\n", info->list->name);
		while (info->list->pipe != NULL)
		{
			printf("pipe = %s\n", info->list->pipe->list->name);
			info->list->pipe = info->list->pipe->next;
		}
		info->list = info->list->next;
	}
}
