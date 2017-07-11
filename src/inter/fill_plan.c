/*
** fill_plan.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May 22 01:31:17 2016 Desriac
** Last update Sun May 22 15:20:17 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "inter.h"

int	fill_planx(t_hit *hit, t_plan *plan, double k)
{
  hit->type = "planx";
  hit->obj = plan;
  hit->k = k;
  eq_para(&hit->ray, k, &hit->pt);
  if (hit->pt.x * hit->pt.y > 0)
    ((((int)hit->pt.y) + ((int)hit->pt.z)) % 2) ?
      (hit->color.full = plan->color2.full) :
      (hit->color.full = plan->color.full);
  else
    ((((int)hit->pt.y) + ((int)hit->pt.z)) % 2) ?
      (hit->color.full = plan->color.full) :
      (hit->color.full = plan->color2.full);
  return (0);
}

int     fill_plany(t_hit *hit, t_plan *plan, double k)
{
  hit->k = k;
  hit->type = "plany";
  hit->obj = plan;
  eq_para(&hit->ray, k, &hit->pt);
  if (hit->pt.z * hit->pt.x > 0)
    ((((int)hit->pt.x) + ((int)hit->pt.z)) % 2) ?
      (hit->color.full = plan->color2.full) :
      (hit->color.full = plan->color.full);
  else
    ((((int)hit->pt.x) + ((int)hit->pt.z)) % 2) ?
      (hit->color.full = plan->color.full) :
      (hit->color.full = plan->color2.full);
  return (0);
}

int     fill_planz(t_hit *hit, t_plan *plan, double k)
{
  hit->type = "planz";
  hit->obj = plan;
  eq_para(&hit->ray, k, &hit->pt);
  hit->k = k;
  if (hit->pt.x * hit->pt.y > 0)
    ((((int)hit->pt.x) + ((int)hit->pt.y)) % 2) ?
      (hit->color.full = plan->color2.full) :
      (hit->color.full = plan->color.full);
  else
    ((((int)hit->pt.x) + ((int)hit->pt.y)) % 2) ?
      (hit->color.full = plan->color.full) :
      (hit->color.full = plan->color2.full);
  return (0);
}

int     fill_plang(t_hit *hit, t_plan *plan, double k)
{
  (void)plan;
  hit->k = k;
  hit->obj = NULL;
  hit->type = "ground";
  eq_para(&hit->ray, k, &hit->pt);
  if (hit->pt.x * hit->pt.z > 0)
    ((((int)hit->pt.x) + ((int)hit->pt.z)) % 2) ?
      (hit->color.full = BLUE) : (hit->color.full = WHITE);
  else
    ((((int)hit->pt.x) + ((int)hit->pt.z)) % 2) ?
      (hit->color.full = YELLOW) : (hit->color.full = GREEN);
  return (0);
}
