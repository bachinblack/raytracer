/*
** fct_thread.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 23:00:28 2016 Desriac
** Last update Sun May 22 17:11:29 2016 Desriac
*/

#include <pthread.h>
#include "rt.h"
#include "inter.h"
#include "my.h"

void    *first_screen(void *my_data)
{
  t_data        *data;
  t_hit         hit;

  data = my_data;
  hit.pos.x = 0;
  hit.pos.y = 0;
  hit.color.full = BLACK;
  while (hit.pos.x != W / 4)
    {
      while (hit.pos.y != H)
	{
	  screen(data, &hit);
	  hit_obj(data, &hit, &hit.ray);
	  hit_light(data, &hit);
	  tekpixel(data->array, &hit.pos, hit.color.full);
	  hit.pos.y++;
	}
      hit.pos.y = 0;
      hit.pos.x++;
    }
  return (NULL);
}

void    *sec_screen(void *my_data)
{
  t_data        *data;
  t_hit         hit;

  data = my_data;
  hit.pos.x = W / 4;
  hit.pos.y = 0;
  hit.color.full = BLACK;
  while (hit.pos.x != W / 2)
    {
      while (hit.pos.y != H)
	{
	  screen(data, &hit);
	  hit_obj(data, &hit, &hit.ray);
	  hit_light(data, &hit);
	  tekpixel(data->array, &hit.pos, hit.color.full);
	  hit.pos.y++;
	}
      hit.pos.y = 0;
      hit.pos.x++;
    }
  return (NULL);
}

void    *third_screen(void *my_data)
{
  t_data        *data;
  t_hit         hit;

  data = my_data;
  hit.pos.x = W / 2;
  hit.pos.y = 0;
  hit.color.full = BLACK;
  while (hit.pos.x != 3 * W / 4)
    {
      while (hit.pos.y != H)
	{
	  screen(data, &hit);
	  hit_obj(data, &hit, &hit.ray);
	  hit_light(data, &hit);
	  tekpixel(data->array, &hit.pos, hit.color.full);
	  hit.pos.y++;
	}
      hit.pos.y = 0;
      hit.pos.x++;
    }
  return (NULL);
}

void    *last_screen(void *my_data)
{
  t_data        *data;
  t_hit         hit;

  data = my_data;
  hit.pos.x = 3 * W / 4;
  hit.pos.y = 0;
  hit.color.full = BLACK;
  while (hit.pos.x != W)
    {
      while (hit.pos.y != H)
	{
	  screen(data, &hit);
	  hit_obj(data, &hit, &hit.ray);
	  hit_light(data, &hit);
	  tekpixel(data->array, &hit.pos, hit.color.full);
	  hit.pos.y++;
	}
      hit.pos.y = 0;
      hit.pos.x++;
    }
  return (NULL);
}
