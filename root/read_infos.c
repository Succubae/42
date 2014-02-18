/*
** read_infos.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Wed Apr  7 17:06:17 2010 jerome ceccato
** Last update Wed Apr 21 12:03:24 2010 jerome ceccato
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "get_next_line.h"
#include "lemin.h"

static void	parse_get_pipe(char *s, char *p, t_data *data)
{
  *p = 0;
  gr_add_link(data->g, s, p + 1);
}

static void	parse_get_room(char *s, t_data *data, int flags)
{
  char		*p;

  if ((p = my_strpbrk(s, " \t")))
    *p = 0;
  gr_add_node(data->g, s, flags);
}

static void	parse_line(char *s, t_data *data, int *expected)
{
  char		*p;

  if (!my_linecmp(s, STR_START1) || !my_linecmp(s, STR_START2))
    *expected = FLAGS_START;
  else if (!my_linecmp(s, STR_END))
    *expected = FLAGS_END;
  else if (*s != COMMENT_CHAR)
    {
      if ((p = my_strchr(s, '-')))
	parse_get_pipe(s, p, data);
      else
	parse_get_room(s, data, *expected);
      *expected = 0;
    }
}

static void	my_puts(char *s)
{
  write(1, s, my_strlen(s));
  write(1, "\n", 1);
}

void		read_infos(t_data *data)
{
  char		*s;
  char		*p;
  int		expected;

  if ((s = get_next_line(0)))
    {
      my_puts(s);
      data->nants = getnbr(s);
      free(s);
    }
  expected = 0;
  while ((s = get_next_line(0)))
    {
      my_puts(s);
      p = s;
      while (my_isspace(*p))
	p++;
      if (*p)
	parse_line(p, data, &expected);
      free(s);
    }
}
