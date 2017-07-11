/*
** inter_sq.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May 22 18:34:15 2016 Desriac
** Last update Sun May 22 21:38:06 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "inter.h"
#include "my.h"

t_color define_pos(t_bunny_pixelarray *pix, float x, float y, t_square *square)
{
  t_bunny_position      pos;
  t_color               color;

  color.full = BLACK;
  if (pix == NULL)
    return (color);
  x += square->size - 1;
  x *= pix->clipable.clip_height / square->size;
  y -= square->size - 1;
  y *= pix->clipable.clip_width / square->size;
  pos.y = (int)x;
  pos.x = (int)y;
  color.full = getpixel(pix, &pos);
  return (color);
}

void    plan_one(t_plan *plan, t_hit *hit, t_square *square)
{
  double        k;
  double        x;
  double        z;

  if (hit->ray.vy == 0)
    return ;
  k = ((-hit->ray.y + plan->add) / -hit->ray.vy);
  if ((k < hit->k || hit->k == 0.0) && k > 0.0)
    {
      x = (hit->ray.vx) * k + hit->ray.x;
      z = (hit->ray.vz) * k + hit->ray.z;
      if (x < (square->c.x - square->size) || x > square->c.x)
	return ;
      if (z < square->c.z - square->size || z > square->c.z)
	return ;
      hit->color.full = ((((int)x + (int)z) % 2) == 1 ? plan->color.full : \
			 plan->color2.full);
      hit->k = k;
    }
}

void    plan_two(t_plan *plan, t_hit *hit, t_square *square)
{
  double        k;
  double        y;
  double        z;

  if (hit->ray.vz == 0)
    return;
  k = ((-hit->ray.z + plan->add) / hit->ray.vz);
  if ((k < hit->k || hit->k == 0.0) && k > 0.0)
    {
      y = (hit->ray.vy) * k + hit->ray.y;
      z = (hit->ray.vx) * k + hit->ray.x;
      if (y < square->c.y - square->size || y > square->c.y)
	return ;
      if (z < square->c.z - square->size || z > square->c.z)
	return ;
      hit->color = define_pos(square->pix, y, z, square);
      hit->k = k;
    }
}

void    plan_three(t_plan *plan, t_hit *hit, t_square *square)
{
  double        k;
  double        y;
  double        z;

  if (hit->ray.vx == 0)
    return;
  k = ((-hit->ray.x + plan->add) / hit->ray.vx);
  if ((k < hit->k || hit->k == 0.0) && k > 0.0)
    {
      y = (hit->ray.vy) * k + hit->ray.y;
      z = (hit->ray.vz) * k + hit->ray.z;
      if (y < square->c.y - square->size || y > square->c.y)
	return ;
      if (z < square->c.z - square->size || z > square->c.z)
	return ;
      hit->color = define_pos(square->pix, y, z, square);
      hit->k = k;
    }
}

void    inter_square(t_hit *hit, t_square *square)
{
  t_plan	plan;

  if (square->obj == 1)
    {
      guitar(hit, square);
      return ;
    }
  plan.alpha = 0;
  plan.color.full = BLUE;
  plan.color2.full = BLACK;
  plan.add = square->c.y - square->size;
  plan_one(&plan, hit, square);
  plan.add = square->c.y;
  plan_one(&plan, hit, square);
  plan.add = square->c.x - square->size;
  plan_two(&plan, hit, square);
  plan.add = square->c.x;
  plan_two(&plan, hit, square);
  plan.add = square->c.z - square->size;
  plan_three(&plan, hit, square);
  plan.add = square->c.z;
  plan_three(&plan, hit, square);
}
