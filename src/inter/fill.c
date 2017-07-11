/*
** fill.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May 22 00:41:37 2016 Desriac
** Last update Sun May 22 20:49:12 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "inter.h"

int     fill_sphere(t_hit *hit, void *obj, t_vect *r, double t)
{
  t_sphere	*sph;

  sph = obj;
  hit->k = t;
  eq_para(r, t, &hit->pt);
  hit->color.full = sph->color.full;
  hit->obj = sph;
  hit->type = "sphere";
  return (0);
}

int     fill_cylinder(t_hit *hit, void *obj, t_vect *r, double t)
{
  t_cylinder	*cy;

  cy = obj;
  hit->k = t;
  eq_para(r, t, &hit->pt);
  hit->color.full = cy->color.full;
  hit->obj = cy;
  return (0);
}

int     fill_cone(t_hit *hit, void *obj, t_vect *r, double t)
{
  t_cone	*co;

  co = obj;
  eq_para(r, t, &hit->pt);
  hit->color.full = co->color.full;
  hit->k = t;
  hit->obj = co;
  hit->type = "cone";
  return (0);
}
