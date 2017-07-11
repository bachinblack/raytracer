/*
** guitar.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May 22 20:15:19 2016 Desriac
** Last update Sun May 22 21:32:16 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "inter.h"
#include "my.h"

static t_color  define_pos(float x, float y, t_square *square)
{
  t_bunny_position      pos;
  t_color               color;

  color.full = BLACK;
  if (square->pix == NULL)
    return (color);
  x += square->size - square->c.y;
  x *= square->pix->clipable.clip_height / square->size;
  y *= square->pix->clipable.clip_width / square->size / 1.7;
  pos.y = (int)x;
  pos.x = (int)y;
  color.full = getpixel(square->pix, &pos);
  return (color);
}

static void     core_g(t_guitar *plan,
		       t_hit *hit,
		       t_square *square)
{
  t_color       color;
  double        k;
  double        y;
  double        z;

  if (hit->ray.vz == 0)
    return ;
  k = ((-hit->ray.z + plan->add) / hit->ray.vz);
  if ((k < hit->k || hit->k == 0.0) && k > 0.0)
    {
      y = (hit->ray.vy) * k + hit->ray.y;
      z = (hit->ray.vx) * k + hit->ray.x;
      if (y < square->c.y - square->size + 0.1 || y > square->c.y)
	return ;
      if (z < (square->c.x - square->size - 2) / 15 || z > square->c.x)
	return ;
      color = define_pos(y, z, square);
      if (color.argb[ALPHA_CMP] != 0 && color.argb[GREEN_CMP] < 250)
	{
	  hit->color = color;
	  hit->k = k;
	}
    }
}

void            guitar(t_hit *hit, t_square *square)
{
  t_guitar	plan;
  float         k;
  float         i;

  i = -0.2;
  k = hit->k;
  while (i < 0)
    {
      plan.add = square->c.z - i;
      core_g(&plan, hit, square);
      i += 0.01;
    }
}
