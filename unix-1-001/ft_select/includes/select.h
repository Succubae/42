/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:00:14 by rgary             #+#    #+#             */
/*   Updated: 2014/01/11 12:17:20 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SELECT_H
# define SELECT_H

# include <termcap.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

# define FP				ft_printf
# define FP2			ft_putstr_fd
# define IS_ESC(s)		(s[0] == 27 && s[1] == 0)
# define IS_LEFT(s)		(s[0] == 27 && s[1] == 91 && s[2] == 68 && s[3] == 0)
# define IS_RIGHT(s)	(s[0] == 27 && s[1] == 91 && s[2] == 67 && s[3] == 0)
# define IS_UP(s)		(s[0] == 27 && s[1] == 91 && s[2] == 66 && s[3] == 0)
# define IS_DOWN(s)		(s[0] == 27 && s[1] == 91 && s[2] == 65 && s[3] == 0)
# define IS_SPACE(s)	(s[0] == 32 && s[1] == 0)
# define IS_ENTER(s)	(s[0] == 10 && s[1] == 0)
# define IS_DELETE(s)	(s[0] == 127 && s[1] == 0)
# define IS_DEL(s)		(s[0] == 27 && s[1] == 91 && s[2] == 51)
# define TTA			td->totalarg
# define TPL			td->padlength
# define TWC			td->wincol
# define TWL			td->winline



typedef struct	s_select
{
	char			*arg;
	int				argnbr;
	int				poscol;
	int				posline;
	int				selected;
	struct s_select	*next;
}				t_select;

typedef struct	s_termdata
{
	char			*termtype;
	int				tty;
	int				wnbr;
	int				padlength;
	int				totalline;
	int				totalarg;
	int				lastline;
	int				wincol;
	int				winline;
	int				poscol;
	int				poslin;
	char			*lineup;
	char			*clear;
}				t_termdata;

/*
**ft error
*/
void		ft_error(const char*);
/*
**remove elem
*/
void		remove_any_elem(t_select **s, int j);
void		remove_first_elem(t_select **s);
void		delete_arg(t_termdata *td, t_select **s);
/*
**ft select
*/
void		rebuild_arg_list(t_select **s);
t_select	*build_arg_list(char *, t_select*, int);
void		move_cursor(int, int, t_termdata*, t_select*);
void		move_cursor_again(int u, int v, t_termdata *td, t_select *s);
void		ft_select(char **argv);
/*
**wait and read
*/
t_select	*malloc_select(char**);
void		select_arg(t_termdata *td, t_select *s);
void		space_pressed(t_termdata *td, t_select *s);
void		wait_while_read(t_termdata *td, t_select *s);
void		return_selection(t_termdata *td, t_select *s);
/*
**ft print arg
*/
int			find_pad(t_select *s);
t_termdata	*change_term_info(t_termdata *s);
void		change_back_term_info(void);
t_termdata	*get_term_data(t_termdata *s, t_select*);
void		ft_print_arg(t_termdata*, t_select *s);
/*
**second arg func
*/
int			out(int);
t_termdata	*malloc_struct(void);
void		print_selected(t_termdata *td, t_select *s);
void		print_with_mod(t_termdata *td, t_select *s);
void		print_arg_and_count(t_termdata*, t_select*, int*, int*);
/*
**main
*/
void	ft_continue(int i);
void	ft_stop(int i);
void	ft_signal(int i);
int		main(int, char**);

#endif
