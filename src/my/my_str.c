/*
** my_strcmp.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 17:50:09 2016 Desriac
** Last update Thu May 19 18:47:50 2016 Desriac
*/

#include <stdlib.h>

int     my_strlen(const char *str)
{
  int   i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

int     my_strcmp(const char *str, const char *comp)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != comp[j])
	return (-1);
      i++;
      j++;
    }
  return (0);
}

char    *my_strdup(const char *src)
{
  int   i;
  char  *dest;

  i = 0;
  if (src == NULL)
    return (NULL);
  if ((dest = malloc((my_strlen(src) + 1) * sizeof(char))) ==  NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  if (my_strlen(dest) != my_strlen(src))
    return (NULL);
  return (dest);
}
