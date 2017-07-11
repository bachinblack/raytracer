/*
** set_obj2.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May 22 17:49:35 2016 Desriac
** Last update Sun May 22 20:11:01 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "setdata.h"
#include "my.h"

void	get_pix(t_square *square, const char *path)
{
  if ((square->pix = bunny_load_pixelarray(path)) == NULL)
    square->pix = NULL;
  return ;
}

int	set_square(t_data *data, t_bunny_ini_scope *scope)
{
  const char    *tmp;

  if ((data->obj.square
       = bunny_realloc(data->obj.square, (data->obj.nb_sq + 1) *
		       sizeof(t_square))) == NULL)
    return (errstr("realloc square failed\n"));
  data->obj.square[data->obj.nb_sq].pix = NULL;
  if ((tmp = bunny_ini_scope_get_field(scope, "size", 0)) == NULL)
    return (errstr("square size failed\n"));
  data->obj.square[data->obj.nb_sq].size = (int)get_unsnbr(tmp);
  if ((tmp = bunny_ini_scope_get_field(scope, "obj", 0)) == NULL)
    return (errstr("square obj failed\n"));
  data->obj.square[data->obj.nb_sq].obj = (char)get_unsnbr(tmp);
  if (get_centre(&data->obj.square[data->obj.nb_sq].c, scope, "pos") != 0)
    return (errstr("square pos failed\n"));
  if ((tmp = bunny_ini_scope_get_field(scope, "pix", 0)) != NULL)
    get_pix(&data->obj.square[data->obj.nb_sq], tmp);
  data->obj.square[data->obj.nb_sq].color.full = BLACK;
  data->obj.nb_sq += 1;
  return (0);
}
