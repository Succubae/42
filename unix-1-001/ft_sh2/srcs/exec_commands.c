/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 15:54:30 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 17:04:19 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

int		create_file(char *file)
{
	int		fd;
	int		retf;
	int		retw;

	if ((retf = access(file, F_OK)) == 0)
	{
		if ((retw = access(file, W_OK)) == 0)
		{
			fd = open(file, O_TRUNC | O_WRONLY);
			return (fd);
		}
		else
		{
			ft_error("{create_file} Access denied");
			return (-1);
		}
	}
	if ((fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	{
		ft_error("{create_file} Unable to create this file");
		return (-1);
	}
	return (fd);
}

int		open_file(char *file)
{
	int	retf;
	int	retr;
	int	fd;

	if ((retf = access(file, F_OK)) != -1)
	{
		if ((retr = access(file, R_OK)) != -1)
		{
			if ((fd = open(file, O_RDONLY)) != -1)
				return (fd);
		}
	}
	if (retf == -1)
		ft_error("{open_file} No such file or directory");
	else if (retr == -1)
		ft_error("{open_file} Access denied");
	return (-1);
}

void	exec_lredir(t_ast *ast, char **env, char **path)
{
	int		i;
	char	**cmd;

	if (ast->left)
	{
		cmd = ft_strsplit(ast->left, ' ');
		i = ft_check_builtins(&env, cmd);
		if (!i)
			ft_not_builtins_fd_left(path, cmd, &env, ast);
	}
	else
		(void)i;
}

void	exec_rredir(t_ast *ast, char **env, char **path)
{
	int		i;
	char	**cmd;

	if (ast->left)
	{
		cmd = ft_strsplit(ast->left, ' ');
		i = ft_check_builtins(&env, cmd);
		if (!i)
			ft_not_builtins_fd_right(path, cmd, &env, ast);
	}
	else
		(void)i;
}

void	exec_pipe(t_ast *ast, char **env, char **path)
{
	int		status;
	int		i;
	int		k;

	if ((i = fork()) > 0)
		waitpid(0, &status, WNOHANG & WUNTRACED);
	else if (i == 0)
	{
		if ((k = fork()) > 0)
		{
			dup2(ast->fd[1], 1);
			close(ast->fd[0]);
			do_as_needed(path, env, ast, 0);
		}
		else
		{
			dup2(ast->fd[0], 0);
			close(ast->fd[1]);
			do_as_needed(path, env, ast, 1);
		}
		exit(0);
	}
}
