/*
** my_cmp.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Wed Apr  7 16:42:22 2010 jerome ceccato
** Last update Wed Apr  7 17:00:52 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"
#include "lemin.h"

int		my_strcmp(const char *s1, const char *s2)
{
  if (!s1)
    return (-1);
  if (!s2)
    return (1);
  while (*s1 && (*s1 == *s2))
    {
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}

int		my_linecmp(char *line, char *s)
{
  if (!line || !s)
    return (1);
  while (my_isspace(*line))
    line++;
  while (*line && (*line == *s))
    {
      line++;
      s++;
    }
  while (my_isspace(*line))
    line++;
  return (*line - *s);
}
