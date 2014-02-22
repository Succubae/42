/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 17:43:25 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 16:15:51 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "string_edit.h"

void		delete_char_tab_tab(char **com)
{
	int		i;

	i = 0;
	while (com[i] != NULL)
	{
		free(com[i]);
		com[i] = NULL;
		i++;
	}
	if (com)
	{
		free(com);
		com = NULL;
	}
}

void		remove_line(t_print *print)
{
	int		i;

	i = ft_strlen(print->line);
	tputs(tgetstr("dm", NULL), 1, out);
	while (print->pos <= i)
	{
		tputs(tgetstr("nd", NULL), 1, out);
		print->pos += 1;
	}
	while (print->pos > 0)
	{
		tputs(tgetstr("le", NULL), 1, out);
		tputs(tgetstr("dc", NULL), 1, out);
		print->line[print->pos] = '\0';
		print->pos -= 1;
	}
	print->line[print->pos] = '\0';
	tputs(tgetstr("de", NULL), 1, out);
}

void		special_cases(char *c, t_print *print)
{
	t_keys	*keys[14] = {pressed_key_up, pressed_key_down, pressed_key_delete,
						pressed_key_left, pressed_key_right, pressed_key_home,
						pressed_key_end, pressed_key_tab, pressed_key_del,
						pressed_shift_left, pressed_shift_right,
						pressed_shift_up, pressed_shift_down, NULL};
	int		i;

	i = -1;
	while (i++, i < 13)
	{
		if (keys[i](c, print) == 1)
		{
			re_print_line(print);
			return ;
		}
	}
}

void		wait_and_read(t_print *print)
{
	char	*c;

	print->pos = print->ins = print->length = 0;
	print->line = ft_strnew(256);
	while (1)
	{
		c = ft_strnew(11);
		read(0, c, 10);
		if ((c[0] < 32 || c[0] > 126) && c[0] != 10 && c[0] != 4)
			special_cases(c, print);
		else if (c[0] == 4 && c[1] == 0)
			exit(0);
		else if (c[0] == 10 && c[1] == 0)
		{
			move_cursor_to_end_of_line(print);
			free(c);
			break ;
		}
		else
		{
			insert_string(c, print);
			re_print_line(print);
		}
		free(c);
	}
}

void		do_even_more_shit(char **env, char **path)
{
	int			i;
	t_print		*print;
/*	char		**commands;*/

	(void)env;
	(void)path;
	print = (t_print*)malloc(sizeof(t_print));
	print->line = NULL;
	print->histo = NULL;
	while (create_prompt(NULL))
	{
		change_term_info(malloc_struct());
		i = -1;
		wait_and_read(print);
		build_history_list(print);

/* ************************************************************************** */
/*  STRSPLIT SUR LES ; A REMPLACER PAR LE PARSER ? */
/*  LA LIGNE DE COMMANDE EST STOCKEE DANS LA STRUCTURE PRINT : PRINT->LINE */
		/*commands = ft_strsplit(print->line, ';');*/
/* ************************************************************************** */

/**************************************************************************** */
/*  JE FAIS UN STRCMP-exit POUR QUITTER EN ATTENDANT LA GESTION DES BUILTINS  */
/*  CE BLOC DEVRA ETRE SUPPRIME                                               */
		if (ft_strcmp(print->line, "exit") == 0)
		{
			change_back_term_info(NULL);
			exit(-1);
		}
/* ************************************************************************** */

/* ************************************************************************** */
/*  REMISE A ZERO DES PARAMETRES DU SHELL AVANT L'EXECUTION D'UNE COMMANDE    */
		if (print->line != NULL)
			free(print->line);
		FP("\n");
		tputs(tgetstr("ei", NULL), 1, out);
		change_back_term_info(NULL);
/* ************************************************************************** */

/* ************************************************************************** */
/*  EXECUTION DES COMMANDES SEPAREES PAR LES ;                                */
		/*while (++i, commands[i] != NULL)
			start_commands(commands[i], &env, path);
			delete_char_tab_tab(commands);*/
/* ************************************************************************** */

		revers_insert_mode(print);
	}
	free(print);
}
