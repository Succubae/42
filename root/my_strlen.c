/*
** my_strlen.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Wed Apr  7 16:37:57 2010 jerome ceccato
** Last update Wed Apr  7 17:01:06 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"
#include "lemin.h"

int		my_strlen(const char *s)
{
  int		i;

  i = 0;
  if (s)
    while (s[i])
      i++;
  return (i);
}
