/*
** hit_light.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May 22 21:39:05 2016 Desriac
** Last update Sun May 22 21:39:54 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "inter.h"
#include "my.h"

int     get_light(t_light *light, t_hit *hit, t_vect *ray)
{
  hit->lobj = NULL;
  hit->k = 0;
  ray->x = light->c.x;
  ray->y = light->c.y;
  ray->z = light->c.z;
  ray->vx = hit->pt.x;
  ray->vy = hit->pt.y;
  ray->vz = hit->pt.z;
  vect_u(ray);
  return (0);
}

int     hit_lplan(t_data *data, t_hit *hit, t_vect *ray)
{
  int   i;

  i = 0;
  while (i != data->obj.nb_p)
    {
      if (data->obj.plan[i].axis == 'x')
	find_planx(ray, &data->obj.plan[i], hit, &light_plan);
      if (data->obj.plan[i].axis == 'y')
	find_plany(ray, &data->obj.plan[i], hit, &light_plan);
      if (data->obj.plan[i].axis == 'z')
	find_planz(ray, &data->obj.plan[i], hit, &light_plan);
      i++;
    }
  if (i == 0)
    ground(hit, &hit->ray, &light_plang);
  return (0);
}

int     hit_wlight(t_data *data, t_hit *hit, t_vect *ray)
{
  int   i;

  i = 0;
  while (i != data->obj.nb_s)
    inter_sphere(&data->obj.sphere[i++], hit, ray, &light_sphere);
  i = 0;
  while (i != data->obj.nb_cy)
    inter_cylinder(&data->obj.cylinder[i++], hit, ray, &light_cylinder);
  i = 0;
  while (i != data->obj.nb_co)
    inter_cone(&data->obj.cone[i++], hit, ray, &light_cone);
  hit_lplan(data, hit, ray);
  return (0);
}

int     hit_light(t_data *data, t_hit *hit)
{
  int   i;

  i = 0;
  while (i != data->nb_l)
    {
      get_light(&data->light[i], hit, &hit->ray);
      hit_wlight(data, hit, &hit->ray);
      i++;
      if (hit->obj != hit->lobj)
	{
	  hit->color.argb[RED_CMP] =  hit->color.argb[RED_CMP] * AMB;
	  hit->color.argb[GREEN_CMP] =  hit->color.argb[GREEN_CMP] * AMB;
	  hit->color.argb[GREEN_CMP] =  hit->color.argb[GREEN_CMP] * AMB;
	}
    }
  return (0);
}
