/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_edit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:49:28 by rgary             #+#    #+#             */
/*   Updated: 2014/02/22 14:49:49 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRING_EDIT_H
# define STRING_EDIT_H

# include <curses.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "42sh.h"

# define LINE			print->line
# define IS_ESC(s)		(s[0] == 27 && s[1] == 0)
# define IS_LEFT(s)		(s[0] == 27 && s[1] == 91 && s[2] == 68 && s[3] == 0)
# define IS_RIGHT(s)	(s[0] == 27 && s[1] == 91 && s[2] == 67 && s[3] == 0)
# define IS_DOWN(s)		(s[0] == 27 && s[1] == 91 && s[2] == 66 && s[3] == 0)
# define IS_UP(s)		(s[0] == 27 && s[1] == 91 && s[2] == 65 && s[3] == 0)
# define IS_SPACE(s)	(s[0] == 32 && s[1] == 0)
# define IS_ENTER(s)	(s[0] == 10 && s[1] == 0)
# define IS_DELETE(s)	(s[0] == 127 && s[1] == 0)
# define IS_DEL(s)		(s[0] == 27 && s[1] == 91 && s[2] == 51 && s[3] == 126\
		&& s[4] == 0)
# define IS_TAB(s)		(s[0] == 9 && s[1] == 0)
# define IS_HOME(s)		(s[0] == 27 && s[1] == 91 && s[2] == 72 && s[3] == 0)
# define IS_END(s)		(s[0] == 27 && s[1] == 91 && s[2] == 70 && s[3] == 0)
# define IS_S_LEFT(s)	(s[0] == 27 && s[1] == 91 && s[2] == 49 && s[3] == 59\
		&& s[4] == 50 && s[5] == 68 && s[6] == 0)
# define IS_S_RIGHT(s)	(s[0] == 27 && s[1] == 91 && s[2] == 49 && s[3] == 59\
		&& s[4] == 50 && s[5] == 67 && s[6] == 0)
# define IS_S_UP(s)		(s[0] == 27 && s[1] == 91 && s[2] == 49 && s[3] == 59\
		&& s[4] == 50 && s[5] == 65 && s[6] == 0)
# define IS_S_DOWN(s)	(s[0] == 27 && s[1] == 91 && s[2] == 49 && s[3] == 59\
		&& s[4] == 50 && s[5] == 66 && s[6] == 0)
# define WRITE_FD		1
# define READ_FD		0

typedef struct	s_termdata
{
	char	*termtype;
	int		tty;
	int		wnbr;
	int		padlength;
	int		totalline;
	int		totalarg;
	int		lastline;
	int		wincol;
	int		winline;
	int		poscol;
	int		poslin;
	char	*lineup;
	char	*clear;
}				t_termdata;

typedef struct	s_history
{
	char				*line;
	struct s_history	*prev;
	struct s_history	*next;
}				t_history;

typedef struct	s_print
{
	int			pos;
	int			startsel;
	int			endsel;
	int			ins;
	int			length;
	char		*line;
	char		*select;
	t_history	*histo;
}				t_print;

typedef int	(t_keys)(char *, t_print*);
/*
**BUILD PROMPT
*/
void		print_prompt(char *prompt);
char		*retrieve_prompt(char *prompt);
int			create_prompt(char **env);
void		ft_error(char *s);
/*
**HANDLE HISTORY
*/
void		remove_line(t_print *print);
t_history	*store_history(t_history *lnk, int i);
char		*get_line_from_history(t_history *lnk, int i);
void		build_history_list(t_print*);
/*
**HANDLE_KEYS
*/
int			pressed_key_up(char*, t_print*);
int			pressed_key_down(char*, t_print*);
int			pressed_key_delete(char*, t_print*);
int			pressed_key_del(char*, t_print*);
int			pressed_key_left(char*, t_print*);
int			pressed_key_right(char*, t_print*);
int			pressed_key_home(char*, t_print*);
int			pressed_key_end(char*, t_print*);
int			pressed_key_tab(char*, t_print*);
int			pressed_shift_left(char*, t_print*);
int			pressed_shift_right(char*, t_print*);
int			pressed_shift_up(char*, t_print*);
int			pressed_shift_down(char*, t_print*);
void		ft_to_get_under_25_lines_1(t_print *print);
void		ft_to_get_under_25_lines_2(t_print*, int, int);
/*
**INITIATE TERM
*/
int			out(int i);
t_termdata	*change_term_info(t_termdata *s);
void		change_back_term_info(char **);
void		revers_insert_mode(t_print *print);
t_termdata	*malloc_struct(void);
/*
**LISTEN
*/
void		delete_char_tab_tab(char **com);
void		wait_and_read(t_print*);
void		do_even_more_shit(char **env, char **path);
/*
**STRING EDIT
*/
void		delete_left(t_print *print);
void		delete_right(t_print *print);
void		insert_char(char c, t_print *print);
void		remove_left_symbole(void);
void		re_print_line(t_print *print);
/*
**STRING EDIT 2
*/
void		insert_string(char *c, t_print *print);
void		move_cursor_to_end_of_line(t_print *print);
void		check_length_and_realloc(t_print *print);
char		*cpy_history(char *histo);


#endif
