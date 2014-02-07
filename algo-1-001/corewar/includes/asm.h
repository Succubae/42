/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuono <sbuono@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:34:49 by rgary             #+#    #+#             */
/*   Updated: 2014/01/18 15:37:26 by cwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ASM_SUCCESS	0
# define ASM_FAILURE	-1
# define CTW			O_CREAT | O_TRUNC | O_WRONLY
# define FP				ft_printf
# define LABEL 			8
# define CMD_DFL_SIZE	-1

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "op.h"
# include "encoding.h"
# include "libft.h"
# include "ftprintf.h"

# define NB_ENC_REG ((REG_NUMBER / 256) + 1)
# define NBR_TOK	8
# define EXT "cor"

typedef enum	e_opc
{
	LIVE = 1,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
}				t_opc;

typedef enum	e_type
{
	NOTHING = 0,
	REG = 1,
	IND = 2,
	DIR = 4,
	LAB = 8,
	OP = 16,
	CMD = 32,
	CMD_NAME = 64,
	CMD_COM = 128,
	DIR_LAB = 256,
	IND_LAB = 512,
	STR = 1024,
	ENDOFLINE = 2048,
	COM = 4096,
	WHIT = 8192,
	SEP = 16384
}				t_type;

typedef struct	s_lexer
{
	t_type			token;
	char			*value;
	struct s_lexer	*next;
}				t_lexer;

typedef struct	s_start
{
	char			*filename;
	char			*name;
	char			*comment;
	int				prog_size;
	t_lexer			*lexer;
}				t_start;

typedef struct	s_label
{
	char			*name;
	int				address;
	struct s_label	*next;
}				t_label;

typedef struct	s_adr
{
	int			fd;
	int			linepos;
	int			currentpos;
	int			onlive;
	int			getindex;
	int			index;
}				t_adr;

typedef struct	s_cmd
{
	char			*cmd;
	char			nb_arg;
	char			has_encoding;
	char			is_idx;
	int				size;
	struct s_cmd	*next;
}				t_cmd;

/*
** LEXER FUNCTION
*/
t_lexer	*lex_lexer(int fd);
int		lex_printlist(t_lexer **list);
void	lex_addlex(t_lexer **list, char *Str, t_type type);
int		lex_error(char **tab, int j, int i);
int		lex_verf1(t_lexer **list, char *trimmed, int j);
int		lex_tablex(t_lexer **list, char *word);

int		lex_iscmd_name(t_lexer **list, char *word);
int		lex_iscmd_com(t_lexer **list, char *word);
int		lex_iscmd(t_lexer **list, char *word);
int		lex_isreg(t_lexer **list, char *word);
int		lex_isdirlab(t_lexer **list, char *word);
int		lex_isdir(t_lexer **list, char *word);
int		lex_islab(t_lexer **list, char *word);
int		lex_isind(t_lexer **list, char *word);

int		lex_strnum(char *str);
int		lex_islabelchars(char *str);

/*
** PARSER FUNCTIONS
*/
int		par_parser(t_lexer *lexed);

/*
** LABELER FUNCTIONS
*/
t_cmd   *cmd_getcmd(char *name);
int		lab_firstpass(char *, t_lexer *, t_start **, t_label **);
int		lab_check(t_lexer *lexer, t_label *label);
int		sta_init(t_start **st, char *file);

void	cmd_movelexer(t_lexer **lexed);
int		cmd_findsize(t_cmd *cmd, t_lexer **lexed);
t_cmd	*cmd_create(char *name);
t_cmd	*cmd_createlive(void);
t_cmd	*cmd_createzjmp(void);
t_cmd	*cmd_createsub(void);
t_cmd	*cmd_createadd(void);
t_cmd	*cmd_createlfork(void);
t_cmd	*cmd_createand(void);
t_cmd	*cmd_createst(void);
t_cmd	*cmd_createld(void);
t_cmd	*cmd_createaff(void);
t_cmd	*cmd_createfork(void);
t_cmd	*cmd_createor(void);
t_cmd	*cmd_createxor(void);
t_cmd	*cmd_createldi(void);
t_cmd	*cmd_createsti(void);
t_cmd	*cmd_createlld(void);
t_cmd	*cmd_createlldi(void);

/*
** ENCODING FUNCTIONS
*/
t_lexer	*pri_print_live_params_values(t_lexer *lexer, t_adr *adr);
t_lexer	*pri_print_params_values(t_lexer *lexer, t_adr *adr, t_label *label);

int		swa_swap_char_by_params(char*, int, int);
int		swa_swap_int_by_params(int, int);

void	wri_write_direct(t_lexer*, t_adr*);
void	wri_calc_opcode(t_lexer *lexer, t_adr *adr, t_label *label);
void	wri_change_name(t_start *start);
void	wri_write_magic_number(t_adr *adr);
void	wri_write_name_and_comment(t_start *start, t_adr *adr);

void	enc_find_label_jmp_adrss(t_lexer*, t_adr*, t_label*);
int		enc_encoding(t_start*, t_label*);

/*
**	PARSE_DECL
*/
int		prt_err(int line, t_lexer *lst);
int		par_parser(t_lexer *lst);
int		tab_check_line(t_lexer *lst);
int		par_clear_lst(t_lexer **lst);
int		par_clear_empty_line(t_lexer **lst);

void	err_badlabel(char *label);

/*
** MAIN FUNCTIONS
*/
void	err_usage(void);
t_start	*test(t_lexer **lexer);
int		count_split(char **split);
#endif
