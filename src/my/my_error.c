/*
** my_error.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 19:08:38 2016 Desriac
** Last update Thu May 19 19:12:03 2016 Desriac
*/

#include <unistd.h>
#include "my.h"

int	errstr(const char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}
