/*
** set_obj.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/gfx_raytracer2
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 15:09:13 2016 Desriac
** Last update Sun May 22 21:12:25 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "setdata.h"
#include "my.h"

int             set_sphere(t_data *data, t_bunny_ini_scope *scope)
{
  const char    *tmp;

  if ((data->obj.sphere =
       bunny_realloc(data->obj.sphere,
		     ((data->obj.nb_s + 1) * sizeof(t_sphere)))) == NULL)
    return (errstr("realloc sphere failed\n"));
  if ((tmp = bunny_ini_scope_get_field(scope, "r", 0)) == NULL)
    return (errstr("sphere rayon failed\n"));
  data->obj.sphere[data->obj.nb_s].r = (double)get_intnbr(tmp);
  if (get_centre(&data->obj.sphere[data->obj.nb_s].c, scope, "centre") != 0)
    return (errstr("sphere center failed\n"));
  if (get_color(&data->obj.sphere[data->obj.nb_s].color, scope, "color") != 0)
    return (errstr("sphere color failed\n"));
  data->obj.nb_s += 1;
  return (0);
}

int             set_cylinder(t_data *data, t_bunny_ini_scope *scope)
{
  const char    *tmp;

  if ((data->obj.cylinder
       = bunny_realloc(data->obj.cylinder, (data->obj.nb_cy + 1) *
		       sizeof(t_cylinder))) == NULL)
    return (errstr("realloc cylinder failed\n"));
  if ((tmp = bunny_ini_scope_get_field(scope, "r", 0)) == NULL)
    return (errstr("cylinder rayon failed\n"));
  data->obj.cylinder[data->obj.nb_cy].r = (double)get_unsnbr(tmp);
  if (get_centre(&data->obj.cylinder[data->obj.nb_cy].c, scope, "centre") != 0)
    return (errstr("cylinder centre failed\n"));
  if (get_color(&(data->obj.cylinder[data->obj.nb_cy].color),
		scope, "color") != 0)
    return (errstr("cylinder color failed\n"));
  data->obj.nb_cy += 1;
  return (0);
}

int             set_cone(t_data *data, t_bunny_ini_scope *scope)
{
  const char    *tmp;

  if ((data->obj.cone = bunny_realloc(data->obj.cone,
				      (data->obj.nb_co + 1) * sizeof(t_cone))) == NULL)
    return (errstr("realloc cone failed\n"));
  if ((tmp = bunny_ini_scope_get_field(scope, "alpha", 0)) == NULL)
    return (errstr("cone alpha failed\n"));
  data->obj.cone[data->obj.nb_co].a =  M_PI * ((double)get_intnbr(tmp) / 180);
  if (get_centre(&data->obj.cone[data->obj.nb_co].c, scope, "centre") != 0)
    return (errstr("cone centre failed\n"));
  if (get_centre(&data->obj.cone[data->obj.nb_co].tp, scope, "tpos") != 0)
    return (errstr("cone tpos failed\n"));
  if (get_color(&data->obj.cone[data->obj.nb_co].color, scope, "color") != 0)
    return (errstr("cone color failed\n"));
  data->obj.nb_co += 1;
  return (0);
}

int     set_light(t_data *data, t_bunny_ini_scope *scope)
{
  if ((data->light = bunny_realloc(data->light,
				   (data->nb_l + 1) * sizeof(t_light))) == NULL)
    return (errstr("realloc light failed\n"));
  if (get_centre(&data->light[data->nb_l].c, scope, "pos") != 0)
    return (errstr("light pos failed\n"));
  data->nb_l += 1;
  return (0);
}

int	set_plan(t_data *data, t_bunny_ini_scope *scope)
{
  const char    *tmp;

  if ((data->obj.plan = bunny_realloc(data->obj.plan,
				      (data->obj.nb_p + 1) * sizeof(t_plan))) == NULL)
    return (errstr("realloc plan failed\n"));
  if ((tmp = bunny_ini_scope_get_field(scope, "cad", 0)) == NULL)
    return (errstr("plan cad failed\n"));
  data->obj.plan[data->obj.nb_p].cad = get_intnbr(tmp);
  if ((tmp = bunny_ini_scope_get_field(scope, "pos", 0)) == NULL)
    return (errstr("plan pos failed\n"));
  data->obj.plan[data->obj.nb_p].add = get_intnbr(tmp);
  if ((tmp = bunny_ini_scope_get_field(scope, "axis", 0)) == NULL)
    return (errstr("plan axis failed\n"));
  data->obj.plan[data->obj.nb_p].axis = *tmp;
  if ((get_color(&data->obj.plan[data->obj.nb_p].color, scope, "color")) != 0)
    return (errstr("plan color failed\n"));
  data->obj.nb_p += 1;
  return (0);
}
