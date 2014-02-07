/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:13:13 by rgary             #+#    #+#             */
/*   Updated: 2014/01/23 17:57:26 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	ft_not_builtins_fd_left(char **p, char **arg, char ***env, t_ast *ast)
{
	int		status;
	int		i;
	int		fildes;
	char	**cmd;

	if ((i = fork()) > 0)
		waitpid(-1, &status, WNOHANG & WUNTRACED);
	else if (i == 0)
	{
		cmd = ft_strsplit(ast->right, ' ');
		if ((fildes = open_file(cmd[0])) == -1)
			ft_error_exit("{f_n_b_f_l} An error occurred while opening file");
		dup2(fildes, 0);
		close(fildes);
		ft_execute(p, arg, env);
	}
}

void	ft_not_fd_right_append(char **path, char **arg, char ***env, t_ast *ast)
{
	int		status;
	int		i;
	int		fildes;
	char	**cmd;

	if ((i = fork()) > 0)
		waitpid(-1, &status, WNOHANG & WUNTRACED);
	else if (i == 0)
	{
		cmd = ft_strsplit(ast->right, ' ');
		if ((fildes = append_file(cmd[0])) == -1)
			return ;
		dup2(fildes, 1);
		ft_execute(path, arg, env);
	}
}

void	ft_not_builtins_fd_right(char **p, char **arg, char ***env, t_ast *ast)
{
	int		status;
	int		i;
	int		fildes;
	char	**cmd;

	if ((i = fork()) > 0)
		waitpid(-1, &status, WNOHANG & WUNTRACED);
	else if (i == 0)
	{
		cmd = ft_strsplit(ast->right, ' ');
		if ((fildes = create_file(cmd[0])) == -1)
			return ;
		dup2(fildes, 1);
		ft_execute(p, arg, env);
	}
}

void	print_tree(t_ast *ast)
{
	while (ast->leftcmd != NULL)
		ast = ast->leftcmd;
	FP("%s | %d | %s\n", ast->left, ast->type, ast->right);
	while (ast != NULL)
	{
		ast = ast->parent;
		if (ast != NULL)
			FP("%p | %d | %s\n", ast->leftcmd, ast->type, ast->right);
	}
}

void	do_more_shit(char **env, char **path)
{
	int		ret;
	int		i;
	char	*line;
	char	**commands;

	while (create_prompt(env), (ret = get_next_line(0, &line)) > 0)
	{
		i = 0;
		commands = ft_strsplit(line, ';');
		while (commands[i] != NULL)
		{
			start_commands(commands[i], env, path);
			i++;
		}
	}
}
