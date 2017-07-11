/*
** move.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri May 20 00:54:14 2016 Desriac
** Last update Sun May 22 21:30:12 2016 Desriac
*/

#include <math.h>
#include <lapin.h>
#include "rt.h"
#include "move.h"

void    itali_move(t_data *data, t_bunny_keysym key)
{
  if (key == BKS_UP || key == BKS_DOWN)
    {
      data->cam.z += (key == BKS_UP ? YCOS * MV : -YCOS * MV);
      data->cam.x += (key == BKS_UP ? YSIN * MV : -YSIN * MV);
    }
  else if (key == BKS_LEFT || key == BKS_RIGHT)
    {
      data->cam.z += (key == BKS_RIGHT ? YCOSS * MV : -YCOSS * MV);
      data->cam.x += (key == BKS_RIGHT ? YSINS * MV : -YSINS * MV);
    }
  else if (key == BKS_PAGEUP || key == BKS_PAGEDOWN)
    data->cam.y += (key == BKS_PAGEDOWN ? MV / 2.0 : -(MV / 2.0));
}

void    itali_turn(t_data *data, t_bunny_keysym key)
{
  if (key == BKS_Q || key == BKS_D)
    data->cam.yalpha += (key == BKS_Q ? M_PI / 64 : (-(M_PI / 64)));
  else if (key == BKS_S || key == BKS_Z)
    data->cam.xalpha += (key == BKS_Z ? M_PI / 64 : (-(M_PI / 64)));
  else if (key == BKS_A || key == BKS_E)
    data->cam.zalpha += (key == BKS_E ? M_PI / 64 : (-(M_PI / 64)));
}

void    itali_core(t_data *data, t_bunny_keysym key)
{
  if (key == BKS_W)
    {
      itali_move(data, BKS_LEFT);
      itali_turn(data, BKS_D);
    }
  else if (key == BKS_X)
    {
      itali_move(data, BKS_RIGHT);
      itali_turn(data, BKS_Q);
    }
  else if (key == BKS_P)
    data->cam.zoom += (data->cam.zoom < 1000 ? 50 : 0);
  else if (key == BKS_M)
    data->cam.zoom -= (data->cam.zoom > -1000 ? 50 : 0);
  else
    itali_move(data, key);
  itali_turn(data, key);
  data->lastkey = key;
}

int	move_it(t_data *data, t_hit *hit)
{
  t_sphere	*sph;

  sph = hit->obj;
  (data->lastkey == BKS_UP ? SIZ += YCOS * MV, SIX += YSIN * MV : 0);
  (data->lastkey == BKS_DOWN ? SIZ -= -YCOS * MV, SIX += -YSIN * MV : 0);
  (data->lastkey == BKS_LEFT ? SIX -=  YCOSS * MV, SIX += YSINS * MV: 0);
  (data->lastkey == BKS_RIGHT ? SIX += YCOSS * MV, SIX += YSINS * MV : 0);
  (data->lastkey == BKS_PAGEUP ? SIY += MV / 2.0 : 0);
  (data->lastkey == BKS_PAGEDOWN ? SIY -= MV / 2.0 : 0);
  return (0);
}
