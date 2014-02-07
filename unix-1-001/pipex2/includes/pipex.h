/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 11:56:38 by rgary             #+#    #+#             */
/*   Updated: 2013/12/31 12:12:11 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

# define FP ft_printf
# define FP2 ft_putstr_fd
# define AM "allocate suffisant memory to copy the environment variables"

typedef struct	s_cmd
{
	int		fd[2];
	char	**av;
	char	**cmd1;
	char	**cmd2;
	char	**env;
}				t_cmd;
/*
**ft environ
*/
void	mod_path(char **path);
char	**ft_getenv(char *s, char **env);
/*
**ft check things
*/
int		ft_check_file_exist(t_cmd *arg);
char	*ft_check_command_2(t_cmd *arg, int amode);
char	*ft_check_command(t_cmd *arg, int amode);
int		ft_check_file(char *s, int amode);
int		ft_check_files_and_commands(t_cmd *arg);
/*
**ft pipe
*/
void	ft_write_to_file(t_cmd *arg);
void	ft_execute_2(t_cmd *arg);
void	ft_execute(t_cmd *arg);
void	ft_begin(t_cmd *arg);
/*
**ft error
*/
void	ft_fork_error(void);
void	ft_right_error(const char *s);
void	ft_exist_error(const char *s);
void    ft_arg_error(const char *s);
/*
**ft error2
*/
void	ft_malloc_error(const char *s);
void	ft_lseek_error(void);
void	ft_command_error(void);
void	ft_unknown_error(const char *s);
void	ft_execve_error(const char *s);
/*
**main
*/
void	ft_copy_environ(char **environ, char ***env);

#endif
