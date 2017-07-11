/*
** inter.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 23:52:04 2016 Desriac
** Last update Sun May 22 15:25:15 2016 Desriac
*/

#include <math.h>
#include <lapin.h>
#include "rt.h"
#include "inter.h"

int     ground(t_hit *hit, t_vect *r, t_fill_plan fct)
{
  double t;

  if (r->vy == 0)
    return (0);
  t = ((-r->y) / r->vy) * 2;
  if ((t < hit->k || hit->k == 0.0) && t > 0.0)
    {
      fct(hit, NULL, t);
    }
  return (0);
}

int     inter_sphere(t_sphere *sph, t_hit *hit, t_vect *r, t_fill_obj fct)
{
  double        d;
  double        t1;
  double        t2;
  t_point       eq;

  eq.x = (pow(r->vx, 2) + pow(r->vy, 2) + pow(r->vz, 2));
  eq.y = 2 * ((r->x * r->vx + r->y * r->vy + r->z * r->vz) -
	      ((r->vx * sph->c.x) + (r->vy * sph->c.y) + (r->vz * sph->c.z)));
  eq.z = (pow(r->x, 2) + pow(r->y, 2) + pow(r->z, 2) - pow(sph->r, 2)) +
    (pow(sph->c.x, 2) + pow(sph->c.y, 2) + pow(sph->c.z, 2)) -
    (2 * (r->x * sph->c.x + r->y * sph->c.y + r->z * sph->c.z));
  d = det(eq.x, eq.y, eq.z);
  if (d >= 0)
    {
      t1 = (-eq.y + sqrt(d)) / (2 * eq.x);
      t2 = (-eq.y - sqrt(d)) / (2 * eq.x);
      (t1 >= t2 && t2 > 0) ? (t1 = t2) : (t2 = t1);
      if ((t1 < hit->k || hit->k == 0.0) && t1 > 0)
	{
	  fct(hit, sph, r, t1);
	}
    }
  return (0);
}

int     inter_cylinder(t_cylinder *cy, t_hit *hit, t_vect *r, t_fill_obj fct)
{
  double        d;
  double        t1;
  double        t2;
  t_point       eq;

  eq.x = (pow(r->vx, 2) + pow(r->vy, 2));
  eq.y = 2 * ((r->x * r->vx + r->y * r->vy)
	      - (r->vx * cy->c.x + r->vy * cy->c.y));
  eq.z = pow(r->x, 2) + pow(r->y, 2) - pow(cy->r, 2) +
    (pow(cy->c.x, 2) + pow(cy->c.y, 2)) - 2 * (r->x * cy->c.x + r->y * cy->c.y);
  d = det(eq.x, eq.y, eq.z);
  if (d >= 0)
    {
      t1 = (-eq.y + sqrt(d)) / (2 * eq.x);
      t2 = (-eq.y - sqrt(d)) / (2 * eq.x);
      (t1 >= t2 && t2 > 0) ? (t1 = t2) : (t2 = t1);
      if ((t1 < hit->k || hit->k == 0.0) && t1 > 0)
	{
	  fct(hit, cy, r, t1);
	}
    }
  return (0);
}

int     inter_cone(t_cone *co, t_hit *hit, t_vect *r, t_fill_obj fct)
{
  double        d;
  double        t1;
  double        t2;
  t_point       eq;

  eq.x = (pow(r->vx, 2) + pow(r->vy, 2) - pow(r->vz, 2) * pow(tan(co->a), 2));
  eq.y = 2 * ((r->x * r->vx + r->y * r->vy
	       - r->z * r->vz * pow(tan(co->a), 2)) -
	      (r->vx * co->c.x + r->vy * co->c.y
	       - r->vz * co->c.z * pow(tan(co->a), 2)));
  eq.z = pow(r->x, 2) + pow(r->y, 2) - pow(r->z, 2) * pow(tan(co->a), 2) +
    (pow(co->c.x, 2) + pow(co->c.y, 2) - pow(co->c.z, 2) * pow(tan(co->a), 2)) -
    2 * (r->x * co->c.x + r->y * co->c.y - r->z * co->c.z * pow(tan(co->a), 2));
  d = det(eq.x, eq.y, eq.z);
  if (d >= 0)
    {
      t1 = (-eq.y + sqrt(d)) / (2 * eq.x);
      t2 = (-eq.y - sqrt(d)) / (2 * eq.x);
      (t1 >= t2 && t2 > 0) ? (t1 = t2) : (t2 = t1);
      if ((t1 < hit->k || hit->k == 0.0) && t1 > 0)
	{
	  fct(hit, co, r, t1);
	}
    }
  return (0);
}
