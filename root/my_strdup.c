/*
** my_strdup.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Wed Apr  7 16:40:04 2010 jerome ceccato
** Last update Wed Apr  7 17:01:02 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"
#include "lemin.h"

char		*my_strdup(const char *s)
{
  char		*new;
  int		sz;
  int		i;

  if (!(sz = my_strlen(s)))
    return (NULL);
  new = gr_malloc((sz + 1) * sizeof(*new));
  i = -1;
  while (s[++i])
    new[i] = s[i];
  new[i] = 0;
  return (new);
}
