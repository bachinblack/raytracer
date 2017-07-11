/*
** effects.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri May 20 16:34:26 2016 Desriac
** Last update Sun May 22 21:17:24 2016 Desriac
*/

#include "rt.h"
#include "move.h"
#include "my.h"

void    warp_me(t_data *data, t_cone *co)
{
  data->cam.x = co->tp.x;
  data->cam.y = co->tp.y;
  data->cam.z = co->tp.z;
  my_putstr("\033[31;1mwarped at the position: \033[0m");
  my_putnbr(co->tp.x);
  my_putchar(':');
  my_putnbr(co->tp.y);
  my_putchar(':');
  my_putnbr(co->tp.z);
  my_putchar('\n');
}

void    block_plan(t_data *data)
{
  (data->lastkey == BKS_RIGHT ? itali_move(data, BKS_LEFT) : 0);
  (data->lastkey == BKS_LEFT ? itali_move(data, BKS_RIGHT) : 0);
  (data->lastkey == BKS_UP ? itali_move(data, BKS_DOWN) : 0);
  (data->lastkey == BKS_DOWN ? itali_move(data, BKS_UP) : 0);
  (data->lastkey == BKS_PAGEUP ? itali_move(data, BKS_PAGEDOWN) : 0);
  (data->lastkey == BKS_PAGEDOWN ? itali_move(data, BKS_PAGEUP) : 0);
}
