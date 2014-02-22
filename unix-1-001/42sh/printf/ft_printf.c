/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 09:42:12 by mfaye             #+#    #+#             */
/*   Updated: 2014/02/02 13:25:12 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "ftprintf.h"
#include "libft.h"

t_format	*get_format(const char *);
void		init_format(t_format **format, int start);
int			print_format(const char **, va_list *, t_format **);

int			ft_printf(const char *format, ...)
{
	t_format	*list;
	int			nb_printed;
	va_list		ap;
	t_format	*save;

	va_start(ap, format);
	nb_printed = 0;
	list = get_format(format);
	save = list;
	while (*format)
	{
		if (*format != START)
		{
			ft_putchar_fd(*format, FD_OUT);
			nb_printed++;
			format++;
		}
		else
			nb_printed += print_format(&format, &ap, &list);
	}
	va_end(ap);
	free_format(save);
	return (nb_printed);
}

void		parse_format(int start, char *s, t_format **list)
{
	t_format	*format;
	int			i;
	int			j;

	if ((format = (t_format *) malloc(sizeof(t_format))) == NULL)
		impossible_malloc("t_format");
	i = j = 1;
	init_format(&format, start);
	format->format = ft_strdup(s);
	format->length = ft_strlen(s);
	format->conv = s[(format->length - 1)];
	format->has_star = (ft_strchr(s, '*') != NULL ? 1 : 0);
	if (ft_isdigit(s[i]))
		i = set_argnb(&format, i, s);
	if (ft_strchr(FLAG, s[i]))
		i = set_flags(&format, i, s);
	if (ft_isdigit(s[i]))
		i = set_minwidth(&format, i, s);
	else if (s[i] == '.')
		i = set_precision(&format, i, s);
	else if (ft_strchr(MOD, s[i]))
		set_lenmod(&format, i, s);
	list_pushback(list, &format);
}

int			print_format(const char **format, va_list *ap, t_format **list)
{
	int	printed;

	printed = 0;
	if (*(*format + 1) == START)
	{
		ft_putchar_fd(START, FD_OUT);
		printed++;
		(*format) += 2;
	}
	else
	{
		if (!(*list))
			kill_me("found an unparsed format ???");
		printed = print_arg(ap, *list);
		*format += (*list)->length;
		*list = (*list)->next;
	}
	return (printed);
}

t_format	*get_format(const char *format)
{
	int			i;
	int			j;
	t_format	*list;
	char		*found;

	i = 0;
	j = 0;
	list = NULL;
	while (format[i])
	{
		if ((format[i] == START) && (format[i + 1] != START))
		{
			j = i + 1;
			while (format[j] && !ft_isalpha(format[j]))
				j++;
			found = ft_strsub(format, i, (j - i) + 1);
			parse_format(i, found, &list);
			free(found);
		}
		i++;
	}
	check_for_arg_nb(list);
	return (list);
}

void		init_format(t_format **format, int start)
{
	(*format)->arg_nb = -1;
	(*format)->start = start;
	(*format)->f_list = NULL;
	(*format)->m_width = 0;
	(*format)->preci = -1;
	(*format)->l_mod = NULL;
	(*format)->conv = 0;
	(*format)->length = 0;
	(*format)->next = NULL;
}
