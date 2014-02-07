/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 10:57:53 by rgary             #+#    #+#             */
/*   Updated: 2013/12/26 09:47:18 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <unistd.h>
#include "ft_sh1.h"

int		ft_check_cd(char **env, char **arg)
{
	int			i;
	int			j;
	char		*join;
	struct stat	*stats;

	i = 0;
	j = 1;
	stats = NULL;
	if (arg[j] == NULL)
		return (1);
	while (arg[j][0] == '-')
		j++;
	join = ft_getenv("PWD", env);
	if (join[ft_strlen(join)] != '/')
		join = ft_strjoin(ft_strjoin(join, "/"), arg[j]);
	else
		join = ft_strjoin(ft_strjoin(ft_getenv("PWD", env), "/"), arg[j]);
	return (1);
}

void	ft_go_oldpwd(char ***env)
{
	char	*tmp;

	tmp = ft_getenv("OLDPWD", (*env));
	if (chdir(tmp) < 0)
	{
		ft_error_chdir(tmp);
		return ;
	}
	FP("%s\n", tmp);
	ft_setenv(env, ft_b_setenv_tab("OLDPWD", ft_getenv("PWD", (*env)), 1));
	ft_setenv(env, ft_b_setenv_tab("PWD", tmp, 1));
}
