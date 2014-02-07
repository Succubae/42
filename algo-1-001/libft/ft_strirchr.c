/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strirchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 13:44:17 by rgary             #+#    #+#             */
/*   Updated: 2013/12/08 13:44:51 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		ft_strirchr(const char *str, int l)
{
	int		i;
	char	c;

	i = 0;
	c = (unsigned char)l;
	while (((char*)str)[i] != '\0')
		i++;
	while (((char*)str)[i] != c)
	{
		if (i < 0)
			return (0);
		i--;
	}
	return (i);
}
