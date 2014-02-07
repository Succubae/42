/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 11:43:53 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 14:03:37 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SH1_H
# define FT_SH1_H

# include "../srcs/gnl/get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

# define FP ft_printf
# define JOIN ft_strjoin
# define AM "allocate suffisant memory to copy the environment variables"
# define GE(a) ft_getenv(a, env)
# define SUB ft_strsub

typedef void	(t_func)(char***, char**);
typedef void	(t_cd)(char ***, char*);
typedef void	(*sig_t)(int);

void	ft_putqstr(const char*);
char	*ft_strtoupper(char *c);
int		ft_check_builtins(char ***env, char **arg);

void    ft_not_builtins(char **path, char **arg, char ***env);
void	ft_copy_environ(char **environ, char ***env);
void	ft_execute(char **path, char **arg, char ***env);
int     ft_compare_cd_operation(char*, char**, char ***, int);

void    ft_print_discard(int i);
void    ft_print_stop(int i);
void    ft_print_core(int i);
void    ft_print_kill(int i);

void    ft_signal(void);
void    ft_signal_2(void);
void	ft_signal_init(void);

int     ft_check_builtins(char ***env, char **arg);
void	mod_path(char **path);
void	ft_find_env_and_path(char **env, char **path);

void    do_shit(char **env, char **path);

void	ft_null(char ***env, char *arg);
void	ft_slash(char ***env, char *arg);
void	ft_dot(char ***env, char *arg);
void	ft_tild(char ***env, char *arg);
void	ft_other(char ***env, char *arg);

void	ft_error_unsetenv(char*);
void	ft_error_chdir(char*);
void	ft_error_malloc(char *);

void	ft_chopchop_env(char **env, char ***envcpy);
void	ft_execute_or_print_env(char **env, char **arg, int i, int j);
void	ft_chopchop(char***, char*);
void	ft_execute_cmd_from_env(char ***env, char **arg, int);
void	ft_print_env(char **env);

void	ft_go_oldpwd(char***);
int		ft_check_cd(char**, char**);

char	*ft_slice_and_dice(char*, int*, int*);
char	*ft_cleanup_pwd(char*);
int     ft_check_var_exist(char*varname, char **env);

char	*ft_getenv(char *s, char **env);
char	**ft_b_setenv_tab(char *varname, char *varvalue, int ow);
int		ft_check_setenv_ag(char**, char**, char**, int*);
void	ft_realloc_env_rev(char***, char*);
void	ft_realloc_env(char***, char*, char*);

void	ft_cd(char***, char **arg);
void	ft_setenv(char***, char **arg);
void	ft_unsetenv(char***, char **arg);
void	ft_env(char***, char **arg);
void	ft_exit(char***, char **arg);

int		main(void);
#endif
