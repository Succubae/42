/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 12:07:40 by sbuono            #+#    #+#             */
/*   Updated: 2014/02/02 09:24:25 by sbuono           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "ftprintf.h"
# include "libft.h"
# include "op.h"
# include "verbose.h"

# define CORE_SUCCESS		0
# define CORE_FAILURE		-1

# define LOAD_NEW_INSTRUCT	-1
# define EXECUTE_INSTRUCT	0
# define END_OF_WAR			-1
# define NO_DUMP			-1
# define GO_DUMP			0

# define REG(a)				proc->reg + ((a - 1) * REG_SIZE)
# define NB_ENC_REG			((REG_NUMBER / 256) + 1)

# define HERO_ALIVE "un processus dit que le joueur %d(%s) est en vie\n"
# define HERO_WIN "Le joueur %d(%s) a gagne\n"

typedef struct s_proc	t_proc;
typedef struct s_hero	t_hero;
typedef struct s_dat	t_dat;
typedef struct s_lex	t_lex;
typedef void	(ft_inst)(t_dat *dat, t_proc *proc);

typedef unsigned char	t_uc;

typedef enum	e_tok
{
	UNKNOWN = 0,
	DUMP = 1,
	NUMBER = 2,
	HERO_NUMB = 4,
	HERO_FILE = 8,
	VERBOSE = 16
}				t_tok;

struct	s_proc
{
	t_uc	reg[REG_SIZE * REG_NUMBER];
	int		pc;
	int		carry;
	t_uc	instruct;
	t_uc	params;
	int		cycle_to_exec;
	int		nbr_live;
	t_proc	*next;
};

struct	s_hero
{
	t_uc	*buf;
	char	*name;
	int		hero_num;
	t_hero	*next;
};

struct	s_dat
{
	t_uc	arena[MEM_SIZE];
	t_proc	**bgn_lst;
	t_hero	*hero_lst;
	int		cycle_to_die;
	int		do_we_check;
	int		nb_checks;
	int		current_cycle;
	int		dump;
	int		last_player_alive;
	int		verbose;
};

struct	s_lex
{
	t_tok	token;
	char	*value;
	t_lex	*next;
};

int		prt_err(char *function, char *add);
void	*prt_err_null(char *function, char *add);
void	prt_err_usage(void);
void	ptr_err_heroneeded(void);
void	ptr_err_scary(void);
void	ptr_err_battleroyal(void);

int		tot_nb_of_heroes(t_lex *lex);
int		next_num_available(t_hero *lst);
t_ui	find_prog_size(int fd);
void	hero_push_back(t_dat *d, t_hero *new);
int		check_magic_number(int);

int		load_heroes(t_dat *d, t_lex *lex, t_proc **bgn_proc_lst);
int		cycling_machine(t_dat *d);
int		new_proc(t_proc **bgn_lst, long r1, int pc);

int		dump(t_dat *d);
void	display_winner(t_dat *d);

void	free_proc_lst(t_proc **lst);
void	free_hero_lst(t_hero *lst);
void	free_data(t_dat *d);

/*
**TOOLS
*/
void	write_long_to_mem(long i, t_uc *end_s, int size);
long	power_256(int coef);
long	get_val(t_uc *s, int addr, int size);
void	get_params(t_dat *d, t_proc *p, long param_val[3], int dir_s);
void	move_pc(t_proc *proc, int dir_s);
int		get_addr(t_proc *proc, long param_val[3]);
void	cpy_to_arena(t_uc *reg, t_dat *d, int addr, int size);
int		isreg(long param);
long	get_true_val(long val, int idx, int size);
void	get_long_params(t_dat *d, t_proc *p, long param_val[3], int dir_s);

void	f_live(t_dat *dat, t_proc *proc);
void	f_ld(t_dat *dat, t_proc *proc);
void	f_st(t_dat *dat, t_proc *proc);
void	f_add(t_dat *dat, t_proc *proc);
void	f_sub(t_dat *dat, t_proc *proc);
void	f_and(t_dat *dat, t_proc *proc);
void	f_or(t_dat *dat, t_proc *proc);
void	f_xor(t_dat *dat, t_proc *proc);
void	f_ldi(t_dat *dat, t_proc *proc);
void	f_sti(t_dat *dat, t_proc *proc);
void	f_lld(t_dat *dat, t_proc *proc);
void	f_lldi(t_dat *dat, t_proc *proc);
void	f_aff(t_dat *dat, t_proc *proc);
void	f_st(t_dat *dat, t_proc *proc);
void	f_zjmp(t_dat *dat, t_proc *proc);
void	f_fork(t_dat *dat, t_proc *proc);
void	f_lfork(t_dat *dat, t_proc *proc);

void	lexer_parser(t_lex **lex, char **ag);
int		lex_checksyntax(t_lex *lex);
#endif
