/*
** my_puts.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri May 20 16:41:43 2016 Desriac
** Last update Fri May 20 18:09:25 2016 Desriac
*/

#include <unistd.h>

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void     my_putnbr(int nb)
{
  int   d;

  d = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  while ((nb / d) >= 10)
    d = d * 10;
  while (d > 0)
    {
      my_putchar((nb / d) % 10 + '0');
      d = d / 10;
    }
}

void    my_putstr(const char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}
