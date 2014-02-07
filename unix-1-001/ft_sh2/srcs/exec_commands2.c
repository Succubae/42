/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 15:54:39 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 16:17:00 by rgary            ###   ########.fr       */
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

void	exec_raredir(t_ast *ast, char **env, char **path)
{
	int		i;
	int		fildes;
	char	**cmd;

	if (ast->left)
	{
		cmd = ft_strsplit(ast->left, ' ');
		i = ft_check_builtins(&env, cmd);
		if (!i)
			ft_not_fd_right_append(path, cmd, &env, ast);
	}
	else
	{
		cmd = ft_strsplit(ast->right, ' ');
		if ((fildes = append_file(cmd[0])) == -1)
			return ;
		dup2(fildes, ast->fd[0]);
		close(ast->fd[1]);
		close(fildes);
	}
}

void	do_as_needed(char **path, char **env, t_ast *ast, int i)
{
	int		j;
	char	**cmd;

	if (i == 1)
		cmd = ft_strsplit(ast->right, ' ');
	else if (i == 0)
		cmd = ft_strsplit(ast->left, ' ');
	j = ft_check_builtins(&env, cmd);
	if (!j)
		ft_not_builtins(path, cmd, &env);
}
