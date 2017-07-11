/*
** plan_inter.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri May 20 13:28:14 2016 Desriac
** Last update Sun May 22 13:15:53 2016 Desriac
*/

#include "rt.h"
#include "inter.h"
#include "move.h"

void    find_plany(t_vect *r, t_plan *plan, t_hit *hit,  t_fill_plan fct)
{
  double        k;

  if (r->vy == 0)
    return;
  k = (((-(r->y + plan->add))) / r->vy);
  if ((k < hit->k || hit->k == 0.0) && k > 0.0)
    {
      fct(hit, plan, k);
    }
}

void    find_planz(t_vect *r, t_plan *plan, t_hit *hit, t_fill_plan fct)
{
  double        k;

  if (r->vz == 0)
    return;
  k = (((-(r->z + plan->add))) / r->vz);
  if ((k < hit->k || hit->k == 0.0) && k > 0.0)
    {
      fct(hit, plan, k);
    }
}

void    find_planx(t_vect *r, t_plan *plan, t_hit *hit, t_fill_plan fct)
{
  double        k;

  if (r->vx == 0)
    return;
  k = (((-(r->x + plan->add))) / r->vx);
  if ((k < hit->k || hit->k == 0.0) && k > 0.0)
    {
      fct(hit, plan, k);
    }
}
