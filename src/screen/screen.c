/*
** screen.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 20:36:57 2016 Desriac
** Last update Sun May 22 14:35:53 2016 Desriac
*/

#include <math.h>
#include "rt.h"
#include "inter.h"

void    rotatx(t_vect *vect, float alpha)
{
  float store;

  store = vect->vy;
  vect->vy = store * cos(alpha) + vect->vz * -sin(alpha);
  vect->vz = store * sin(alpha) + vect->vz * cos(alpha);
}

void    rotaty(t_vect *vect, float alpha)
{
  float store;

  store = vect->vx;
  vect->vx = store * cos(alpha) + vect->vz * -sin(alpha);
  vect->vz = store * sin(alpha) + vect->vz * cos(alpha);
}

void    rotatz(t_vect *vect, float alpha)
{
  float store;

  store = vect->vx;
  vect->vx = store * cos(alpha) + vect->vy * -sin(alpha);
  vect->vy = store * sin(alpha) + vect->vy * cos(alpha);
}

int  screen(t_data *data, t_hit *hit)
{
  hit->color.full = BLACK;
  hit->type = NULL;
  hit->k = 0;
  hit->ray.x = data->cam.x;
  hit->ray.y = data->cam.y;
  hit->ray.z = data->cam.z;
  hit->ray.vx = W / 2 - hit->pos.x;
  hit->ray.vx = data->cam.x - hit->ray.vx;
  hit->ray.vy = H / 2 - hit->pos.y;
  hit->ray.vy = data->cam.y - hit->ray.vy;
  hit->ray.vz = pow(W, 2) + pow(H, 2);
  hit->ray.vz = sqrt(hit->ray.vz) + data->cam.zoom;
  rotatx(&hit->ray, data->cam.xalpha);
  rotaty(&hit->ray, data->cam.yalpha);
  rotatz(&hit->ray, data->cam.zalpha);
  return (0);
}
