/*
** getnbr.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Wed Apr  7 16:40:32 2010 jerome ceccato
** Last update Wed Apr  7 17:00:45 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"
#include "lemin.h"

int		getnbr(char *s)
{
  int		res;

  res = 0;
  while ((*s >= '0') && (*s <= '9'))
    res = (res * 10) + *s++ - '0';
  return (res);
}
