/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 10:25:12 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 18:14:42 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SH2_H
# define FT_SH2_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_sh1.h"
# include "get_next_line.h"

# define FP			ft_printf
# define FP2		ft_putstr_fd
# define TPT		tok->prev->type
# define TNT		tok->next->type
# define APPENDFILE	O_CREAT | O_APPEND | O_WRONLY
# define TRUNCFILE	O_CREAT
# define IS_STDCHAR	line[*i + j] != ' ' && line[*i + j] != '"'		\
					&& line[*i + j] != ';' && line[*i + j] != '|'	\
					&& line[*i + j] != '<' && line[*i + j] != '>'

typedef struct s_token	t_token;
typedef struct s_ast	t_ast;

typedef enum	e_type
{
	QUOTE = 0,
	LREDIR,
	RREDIR,
	LAREDIR,
	RAREDIR,
	PIPE,
	SEMICOLON,
	WHITESPACE,
	STDCHAR,
	ENDOFLINE
}				t_type;

struct	s_token
{
	char		*val;
	t_type		type;
	t_token		*next;
	t_token		*prev;
};

struct	s_ast
{
	t_type		type;
	t_ast		*parent;
	t_ast		*leftcmd;
	char		*left;
	char		*right;
	int			fd[2];
};

typedef int (*t_sh2)(t_token*);
typedef void (*t_tree)(t_ast*, char**, char**);

/*
**OPERATION ON COMMAND
*/
void	ft_not_builtins_fd_left(char **path, char **arg, char***, t_ast*);
void	ft_not_builtins_fd_right(char **path, char **arg, char***, t_ast*);
void	ft_not_fd_right_append(char **path, char **arg, char***, t_ast*);
void	do_more_shit(char **env, char **path);

/*
**LEXER
*/
char	*remove_escape_char_from_stdchar(char *val);
char	*remove_escape_char_from_quote(char *val);
void	deal_with_escape_char(t_token**);
t_token	*lexer(char *line);
t_token	*lexer_next(char *line, int *i, t_token *tok);
t_token	*lexer_next_2(char *line, int *i, t_token *tok);
/*
**PARSER
*/
void	parse_error(char *tok);
int		check_legality(t_token *tok, int *type);
t_sh2	*build_tab(void);
int		parser(t_token *tok);
int		check_lredir(t_token *tok);
int		check_rredir(t_token *tok);
int		check_pipe(t_token *tok);
int		check_laredir(t_token *tok);
int		check_raredir(t_token *tok);
int		check_quote(t_token *tok);
int		check_semicolon(t_token *tok);
int		check_whitespace(t_token *tok);
int		check_stdchar(t_token *tok);
int		check_endofline(t_token *tok);
/*
**TESTS
*/
void	start_tests(void);
/*
**BUILD TREE
*/
t_ast	*build_branch(t_ast *ast, t_token **tok, char *cmd);
t_ast	*build_tree(t_token *tok);
/*
**EXECUTE TREE
*/
void	execute_command(t_token *tok, char **env, char **path);
t_tree	*build_f_tab(void);
void	execute_tree(t_ast *ast, char **env, char **path);
/*
**EXEC LREDIR
*/
int		create_file(char *file);
int		open_file(char*file);
void	exec_lredir(t_ast *ast, char **env, char **path);
void	exec_rredir(t_ast *ast, char **env, char **path);
void	exec_pipe(t_ast *ast, char **env, char **path);
/*
**EXEC COMMANDS 2
*/
int		append_file(char *file);
void	exec_raredir(t_ast *ast, char **env, char **path);
void	do_as_needed(char **path, char **env, t_ast *ast, int i);
/*
**BUILD PROMPT
*/
void	start_commands(char *line, char **env, char **path);
void	create_prompt2(char *pwd, char *prompt, int i, int j);
void	create_prompt(char **env);
#endif
