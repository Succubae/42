/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:30:18 by rgary             #+#    #+#             */
/*   Updated: 2014/02/18 11:23:38 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct s_info	t_info;
typedef struct s_room	t_room;
typedef struct s_pipe	t_pipe;
typedef struct s_tok	t_tok;

# define STARTL	"##start"
# define ENDL	"##end"
# define POSL	"0123456789"
# define NAMEL	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUWXYZ_0123456789"

typedef enum	e_type
{
	START = 0,
	END,
	COMMENT,
	NAME,
	POS,
	IGNORE,
	ENDLINE
}				t_type;

struct	s_tok
{
	enum e_type	type;
	char		*val;
	t_tok		*next;
};

struct	s_info
{
	int		ant;
	t_room	*start;
	t_room	*end;
	t_room	*list;
};

struct	s_room
{
	char	*name;
	int		posx;
	int		posy;
	t_pipe	*pipe;
	t_room	*next;
};

struct	s_pipe
{
	t_room	*list;
	t_pipe	*next;
};
/*
**BUILD ROOM
*/
t_tok	*tok_push_back(t_tok *tok, t_tok *new);
t_tok	*init_tok_list(t_tok *tok, char *line, t_type type);
/*char	*check_for_invalid_command(char *line);*/
t_room	*init_room(t_tok**, t_room*);

/*
**ERROR
*/
void	ft_error_1(char *s);
void	ft_error_2(char *s, char *s2);
void	ft_error_3(char *s, char *s2, char *s3);
void	ft_error_4(char *s, char *s2, char *s3, char *s4);
/*
**FT FREE
*/
void	free_one(void *any);
void	free_char_tab(char **tab);
/*
**GET INFO
*/
/*void	fill_start_and_end(t_info **info, char *line);*/
void	check_and_fill_ant_nbr(t_info **info, char *line);
void	get_info(t_info *info, t_tok *tok);
/*
**LEXER
*/
t_tok	*handle_command(char *line, t_tok *tok);
t_tok	*build_list_each_line(t_tok *tok, char *line, int *err);
t_tok	*build_lex_list(void);
#endif /* lemin.h */
