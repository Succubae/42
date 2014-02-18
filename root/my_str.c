/*
** my_str.c for  in /home/ceccat_j/c/projs/lemin
** 
** Made by jerome ceccato
** Login   <ceccat_j@epitech.net>
** 
** Started on  Wed Apr  7 16:37:02 2010 jerome ceccato
** Last update Mon Apr 12 13:34:05 2010 jerome ceccato
*/

#include <stdlib.h>
#include "graph.h"
#include "lemin.h"

char		*my_strchr(char *s, char c)
{
  if (s)
    while (*s)
      {
	if (*s == c)
	  return (s);
	s++;
      }
  return (NULL);
}

char		*my_strpbrk(char *s, char *charset)
{
  if (s)
    while (*s)
      {
	if (my_strchr(charset, *s))
	  return (s);
	s++;
      }
  return (NULL);
}
