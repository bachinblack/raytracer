/*
** hit_obj.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri May 20 00:28:56 2016 Desriac
** Last update Sun May 22 21:42:05 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "inter.h"
#include "my.h"

int	hit_plan(t_data *data, t_hit *hit, t_vect *ray)
{
  int	i;

  i = 0;
  while (i != data->obj.nb_p)
    {
      if (data->obj.plan[i].axis == 'x')
      	find_planx(ray, &data->obj.plan[i], hit, &fill_planx);
      if (data->obj.plan[i].axis == 'y')
      	find_plany(ray, &data->obj.plan[i], hit, &fill_plany);
      if (data->obj.plan[i].axis == 'z')
      	find_planz(ray, &data->obj.plan[i], hit, &fill_planz);
      i++;
    }
  return (0);
}

int     hit_obj(t_data *data, t_hit *hit, t_vect *ray)
{
  int   i;

  i = 0;
  while (i != data->obj.nb_s)
    inter_sphere(&data->obj.sphere[i++], hit, ray, &fill_sphere);
  i = 0;
  while (i != data->obj.nb_cy)
    inter_cylinder(&data->obj.cylinder[i++], hit, ray, &fill_cylinder);
  i = 0;
  while (i != data->obj.nb_co)
    inter_cone(&data->obj.cone[i++], hit, ray, &fill_cone);
  i = 0;
  while (i != data->obj.nb_sq)
    inter_square(hit, &data->obj.square[i++]);
  hit_plan(data, hit, ray);
  if (hit->k < 0.004 && hit->type != NULL
      && 0 == my_strcmp(hit->type, "sphere"))
    move_it(data, hit);
  if (hit->k < 0.004 && hit->type != NULL
      && 0 == my_strcmp(hit->type, "cone"))
    warp_me(data, hit->obj);
  return (0);
}
