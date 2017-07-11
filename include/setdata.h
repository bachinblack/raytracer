/*
** setdata.h for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 17:33:20 2016 Desriac
** Last update Sun May 22 21:47:14 2016 Desriac
*/

#ifndef SETDATA_H_
# define SETDATA_H_

# include <lapin.h>
# include "rt.h"

typedef int(*t_set_obj)(t_data*, t_bunny_ini_scope*);

typedef struct  s_func
{
  t_set_obj     func;
  char          *name;
}               t_func;

/*
** setobj
*/

int	set_sphere(t_data *data, t_bunny_ini_scope *scope);
int	set_cylinder(t_data *data, t_bunny_ini_scope *scope);
int	set_cone(t_data *data, t_bunny_ini_scope *scope);
int	set_light(t_data *data, t_bunny_ini_scope *scope);
int	set_plan(t_data *data, t_bunny_ini_scope *scope);
int     set_square(t_data *data, t_bunny_ini_scope *scope);

/*
** scope
*/

int     get_color(t_color *color, t_bunny_ini_scope *scope, const char *type);
int     get_centre(t_point *c, t_bunny_ini_scope *scope, const char *type);

#endif /* !SETDATA_H_ */
