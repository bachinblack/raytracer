/*
** set_dat.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/gfx_raytracer2
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 14:53:34 2016 Desriac
** Last update Sun May 22 18:19:27 2016 Desriac
*/

#include <stdlib.h>
#include <lapin.h>
#include "rt.h"
#include "setdata.h"
#include "my.h"

static t_func tab[] = {
  {&set_plan, "plan"},
  {&set_sphere, "sphere"},
  {&set_cylinder, "cylinder"},
  {&set_cone, "cone"},
  {&set_light, "light"},
  {&set_square, "square"},
  {NULL, NULL}
};

t_bunny_pixelarray      *color_array(unsigned int width,
				     unsigned int height,
				     t_color *color)
{
  long                  i;
  t_bunny_pixelarray    *array;

  i = 0;
  array = bunny_new_pixelarray(width, height);
  while (i <= width * height)
    ((unsigned int *)array->pixels)[i++] = color->full;
  return (array);
}

int                     set_cam(t_data *data)
{
  data->cam.x = 1;
  data->cam.y = 2;
  data->cam.z = 1;
  data->cam.xalpha = 0;
  data->cam.yalpha = 0;
  data->cam.zalpha = 0;
  data->cam.zoom = 0;
  return (0);
}

int                     set_objtab(t_data *data)
{
  data->obj.plan = NULL;
  data->obj.nb_p = 0;
  data->obj.sphere = NULL;
  data->obj.nb_s = 0;
  data->obj.cylinder = NULL;
  data->obj.nb_cy = 0;
  data->obj.cone = NULL;
  data->obj.nb_co = 0;
  data->obj.square = NULL;
  data->obj.nb_sq = 0;
  data->light = NULL;
  data->nb_l= 0;
  return (0);
}

int                     set_obj(t_data *data, char **av)
{
  int                   i;
  t_bunny_ini           *ini;
  t_bunny_ini_scope     *scope;
  const char            *tmp;

  set_objtab(data);
  if (av[1] == NULL)
    return (errstr("bad path\n"));
  if ((ini = bunny_load_ini(av[1])) == NULL)
    return (errstr("bad ini\n"));
  scope = bunny_ini_first(ini);
  while ((scope = bunny_ini_next(ini, scope)) != NULL)
    {
      if ((tmp = bunny_ini_scope_get_field(scope, "type", 0)) == NULL)
	return (errstr("no type\n"));
      i = 0;
      while (tab[i].name != NULL)
	{
	  if (!my_strcmp(tab[i++].name, tmp))
	      if ((tab[(i - 1)].func(data, scope)) != 0)
		return (errstr("obj faild\n"));
	}
    }
  return (0);
}

int		set_data(t_data *data, char **av)
{
  t_color       color;

  color.full = BLACK;
  data->array = color_array(WIDTH, HEIGHT, &color);
  set_cam(data);
  if (0 != set_obj(data, av))
    return (1);
  return (0);
}
