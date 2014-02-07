/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_shits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 16:40:09 by rgary             #+#    #+#             */
/*   Updated: 2014/02/01 17:32:17 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "asm.h"

void	wri_write_direct(t_lexer *lexer, t_adr *adr)
{
	int		i;

	if (adr->getindex == 1)
	{
		i = swa_swap_char_by_params(lexer->value, IND_SIZE, 0);
		write(adr->fd, &i, IND_SIZE);
		adr->currentpos += 2;
	}
	else
	{
		i = swa_swap_char_by_params(lexer->value, DIR_SIZE, 0);
		write(adr->fd, &i, REG_SIZE);
		adr->currentpos += 4;
	}
}

void	wri_calc_opcode(t_lexer *lexer, t_adr *adr, t_label *label)
{
	int		i;
	int		j;
	int		res;
	t_lexer	*save;

	adr->currentpos += 1;
	(void)label;
	res = j = 0;
	i = 4;
	save = lexer;
	while (i--, lexer->token != ENDOFLINE)
	{
		j++;
		if (lexer->token == REG)
			res += (REG_CODE << (i * 2));
		else if (lexer->token == IND)
			res += (IND_CODE << (i * 2));
		else if (lexer->token == DIR || lexer->token == DIR_LAB)
			res += (DIR_CODE << (i * 2));
		lexer = lexer->next;
	}
	write(adr->fd, &res, 1);
	if (adr->getindex == 1)
		adr->index = j;
}

void	wri_change_name(t_start *start)
{
	int		i;
	char	**path;
	char	**filename;

	path = ft_strsplit(start->filename, '/');
	i = ft_countsplit(path);
	filename = ft_strsplit(path[i - 1], '.');
	free(filename[1]);
	filename[1] = ft_strdup(EXT);
	free(path[i - 1]);
	path[i - 1] = ft_strglue(filename, '.');
	free(start->filename);
	start->filename = ft_strglue(path, '/');
}

void	wri_write_magic_number(t_adr *adr)
{
	int	i;
	int	swap;

	i = COREWAR_EXEC_MAGIC;
	swap = ((i >> 24) & 0xff)
		| ((i << 8) & 0xff0000)
		| ((i >> 8) & 0xff00)
		| ((i << 24) & 0xff000000);
	write(adr->fd, &swap, 4);
}

void	wri_write_name_and_comment(t_start *start, t_adr *adr)
{
	int		i;

	wri_write_magic_number(adr);
	i = ft_strlen(start->name);
	write(adr->fd, start->name + 1, i - 2);
	i -= 3;
	while (i++, i < PROG_NAME_LENGTH + 1)
		write(adr->fd, "\0", 1);
	while ((i % 4) != 0)
	{
		write(adr->fd, "\0", 1);
		i++;
	}
	i = swa_swap_int_by_params(start->prog_size, 4);
	write(adr->fd, &i, 4);
	i = ft_strlen(start->comment);
	write(adr->fd, start->comment + 1, i - 2);
	i -= 3;
	while (i++, i < COMMENT_LENGTH + 1)
		write(adr->fd, "\0", 1);
	while ((i % 4) != 0)
	{
		write(adr->fd, "\0", 1);
		i++;
	}
}
