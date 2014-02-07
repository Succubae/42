/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 15:54:39 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 12:28:52 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

int		append_file(char *file)
{
	int		fd;
	int		retf;
	int		retw;

	if ((retf = access(file, F_OK)) == 0)
	{
		if ((retw = access(file, W_OK)) == 0)
		{
			fd = open(file, O_APPEND | O_WRONLY);
			return (fd);
		}
		else
		{
			ft_error("{append_file} Access denied");
			return (-1);
		}
	}
	if ((fd = open(file, O_CREAT | O_WRONLY, 0644)) == -1)
	{
		ft_error("{append_file} Unable to create this file");
		return (-1);
	}
	return (fd);
}

void	exec_raredir(t_ast *ast, char ***env, char **path)
{
	int		i;
	int		fildes;
	char	**cmd;

	if (ast->left)
	{
		cmd = ft_strsplit(ast->left, ' ');
		i = ft_check_builtins(env, cmd);
		if (!i)
			ft_not_fd_right_append(path, cmd, env, ast);
	}
	else
	{
		cmd = ft_strsplit(ast->right, ' ');
		if ((fildes = append_file(cmd[0])) == -1)
		{
			free_cmd(cmd);
			return ;
		}
		dup2(fildes, ast->fd[0]);
		close(ast->fd[1]);
		close(fildes);
	}
	free_cmd(cmd);
}

void	do_as_needed(char **path, char ***env, t_ast *ast, int i)
{
	int		j;
	char	**cmd;

	cmd = NULL;
	if (i == 1)
		cmd = ft_strsplit(ast->right, ' ');
	else if (i == 0)
		cmd = ft_strsplit(ast->left, ' ');
	j = ft_check_builtins(env, cmd);
	if (!j)
		ft_not_builtins(path, cmd, env);
}

void	exec_pipe_commands(char **cmd, char **cmd2, char ***env, char **path)
{
	int		fd[2];

	if (pipe(fd) == -1)
	{
		ft_error("pipe error");
		return ;
	}
	if (!fork())
	{
		close(fd[READ_FD]);
		dup2(fd[WRITE_FD], 1);
		ft_execute(path, cmd, env);
		close(fd[WRITE_FD]);
		exit(0);
	}
	else
	{
		wait(0);
		close(fd[WRITE_FD]);
		dup2(fd[READ_FD], 0);
		ft_execute(path, cmd2, env);
		close(fd[READ_FD]);
	}
	exit(0);
}
