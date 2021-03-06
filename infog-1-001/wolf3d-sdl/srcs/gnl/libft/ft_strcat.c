/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:03:13 by rgary             #+#    #+#             */
/*   Updated: 2013/11/19 17:14:19 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcat(char *str, const char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (str2[j] != '\0')
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
