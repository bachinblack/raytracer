/*
** ligth_fill.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May 22 15:30:09 2016 Desriac
** Last update Sun May 22 20:03:48 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "inter.h"

int     light_sphere(t_hit *hit, void *sph, t_vect *r, double t)
{
  eq_para(r, t, &hit->lpt);
  hit->k = t;
  hit->lobj = sph;
  return (0);
}

int	light_cylinder(t_hit *hit, void *cy, t_vect *r, double t)
{
  eq_para(r, t, &hit->lpt);
  hit->k = t;
    hit->lobj = cy;
  return (0);
}

int     light_cone(t_hit *hit, void *co, t_vect *r, double t)
{
  eq_para(r, t, &hit->lpt);
  hit->k = t;
  hit->lobj = co;
  return (0);
}
