/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:09:57 by rgary             #+#    #+#             */
/*   Updated: 2013/12/13 20:38:03 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		main(void)
{
	char	*str;
	int		fd;

	fd = open("test_1.txt", O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		ft_putendl(str);
	}
	if (get_next_line(fd, &str) < 0)
		ft_putendl("Prout");
	ft_putendl("Crounch");
	close(fd);
	return (0);
}

/*
int        get_next_line(int const fd, char **line);

int        main()
{
    int        fd;
    char    **line;
    int        i = 0;
    int        ret;

	line = (char**)malloc(sizeof(*line));
	fd = open("test_1.txt", O_RDONLY);
    while (get_next_line(fd, line) > 0)
    {
		printf("ligne\n");
		printf("%s\n", *line);
        printf("-- ret = [%d] --\n", ret);
    }
    printf("\n\nlecture fichier1\n");
    i = 0;
    fd = open("test.txt", O_RDONLY);
    while (i < 11)
    {
        ret = get_next_line(fd, line);
        printf("-- line = |%s| --\n", *line);
        printf("-- ret = [%d] --\n", ret);
        i++;
    }
    close(fd);
    printf("\n\nlecture fichier2\n");
    i = 0;
    fd = open("fichier2", O_RDONLY);
    while (i < 10)
    {
        ret = get_next_line(fd, line);
        printf("-- line = |%s| --\n", *line);
        printf("-- ret = [%d] --\n", ret);
        i++;
    }
    close(fd);
    return (0);
}
*/
