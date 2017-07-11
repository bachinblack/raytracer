/*
** get_color.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/gfx_raytracer2
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 15:37:03 2016 Desriac
** Last update Sat May 21 15:02:15 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "my.h"

int	get_color(t_color *color, t_bunny_ini_scope *scope, const char *type)
{
  const char    *tmp;

  color->full = BLACK;
  if ((tmp = bunny_ini_scope_get_field(scope, type, 0)) == NULL)
    return (errstr("0 "));
  color->argb[RED_CMP] = get_intnbr(tmp);
  if ((tmp = bunny_ini_scope_get_field(scope, type, 1)) == NULL)
    return (errstr("1 "));
  color->argb[GREEN_CMP]= get_intnbr(tmp);
  if ((tmp = bunny_ini_scope_get_field(scope, type, 2)) == NULL)
    return (errstr("2 "));
  color->argb[BLUE_CMP]= get_intnbr(tmp);
  return (0);
}

int	get_centre(t_point *c, t_bunny_ini_scope *scope, const char *type)
{
  const char	*tmp;

  if ((tmp = bunny_ini_scope_get_field(scope, type, 0)) == NULL)
    return (errstr("0 "));
  c->x = (double)get_intnbr(tmp);
  if ((tmp = bunny_ini_scope_get_field(scope, type, 1)) == NULL)
    return (errstr("1 "));
  c->y = (double)get_intnbr(tmp);
  if ((tmp = bunny_ini_scope_get_field(scope, type, 2)) == NULL)
    return (errstr("2 "));
  c->z = (double)get_intnbr(tmp);
  return (0);
}
