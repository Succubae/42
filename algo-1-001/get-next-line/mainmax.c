#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{
    char    *str;
    int        fd;
    char    **file_list;
    int        res = 0;
    int        i, max, start;

    str = NULL;
    if (argc > 1)
    {
        start = 1;
        max = argc;
        file_list = argv;
    }
    else
    {
		file_list = (char**)malloc(sizeof(char*) * 3);
		file_list[0] = ft_strdup("test_1.txt");
		file_list[1] = ft_strdup("test_2.txt");
		file_list[2] = ft_strdup("test_3.txt");
		start = 0;
		max = 3;
	}
	for (i = start; i < max; i++)
	{
		if ((fd = open(file_list[i], O_RDONLY)) > 0)
		{
			ft_putstr("Openning file [");
			ft_putstr(file_list[i]);
			ft_putstr("]\n");
			ft_putendl("----------------------------");
			while ((res = get_next_line(fd, &str)) > 0)
				ft_putendl(str);
			if (res == -1)
				ft_putstr_fd("An error occured when reading file\n", 2);
			else
				free(str);
			ft_putendl("----------------------------");
			close(fd);
		}
		else
			printf("Unable to open file [%s]\n", file_list[i]);
	}
	return 0;
}
