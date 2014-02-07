/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:46:28 by mfaye             #+#    #+#             */
/*   Updated: 2013/11/23 13:23:01 by mfaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int			ft_isdigit(int);
int			ft_isalpha(int);
int			ft_isascii(int);

static int	is_operator(char c)
{
	int	out;

	out = (c == '-');
	out = (out || (c == '+'));
	return (out);
}

static int	power(char c, int pow)
{
	int	out;
	int	i;
	int	char_value;

	char_value = c - 48;
	out = 1;
	i = 1;
	if (pow == 0)
		return (char_value);
	while (i <= pow)
	{
		out = out * 10;
		i++;
	}
	return (out * char_value);
}

static int	powerize(const char *str, int start, int end)
{
	int	power_val;
	int	out;
	int	is_negative;

	power_val = 0;
	out = 0;
	is_negative = (str[start] == '-');
	while (end >= start)
	{
		if (!is_operator(str[end]))
		{
			out += power(str[end], power_val);
			power_val++;
		}
		end--;
	}
	if (is_negative)
		return (out * -1);
	return (out);
}

static int	is_authorized(char c)
{
	static char	authorized[6] = {'\n', '\v', '\t', '\r', '\f', ' '};
	int			i;
	int			valid;

	valid = 0;
	i = 0;
	while (i < 6)
	{
		if (c == authorized[i])
			valid++;
		i++;
	}
	if (!valid)
	{
		valid = (ft_isalpha(c) || !ft_isascii(c) || !is_operator(c));
		if (valid && !ft_isdigit(c))
			valid = 0;
		else
			valid = 1;
	}
	return (valid);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	out;

	i = 0;
	j = 0;
	out = 0;
	while (str[i])
	{
		if (!is_authorized(str[i]))
			return (0);
		if (is_operator(str[i]) || ft_isdigit(str[i]))
		{
			j = i + 1;
			while (ft_isdigit(str[j]))
				j++;
			break ;
		}
		i++;
	}
	return (powerize(str, i, (j - 1)));
}
