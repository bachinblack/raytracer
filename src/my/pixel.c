/*
** pixel.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 22:56:10 2016 Desriac
** Last update Thu May 19 23:15:13 2016 Desriac
*/

#include <lapin.h>

int     tekpixel(t_bunny_pixelarray     *pix,
		 t_bunny_position       *pos,
		 unsigned int           color)
{
  unsigned long y_width;

  if (pos->x < 0 || pos->y < 0)
    return (-1);
  if (pos->x > pix->clipable.clip_width || pos->y >= pix->clipable.clip_height)
    return (-1);
  y_width = pos->y * pix->clipable.clip_width;
  ((unsigned int *)pix->pixels)[y_width + pos->x] = color;
  return (0);
}

unsigned int    getpixel(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color       color;
  unsigned long width;

  if (pos->x < 0 || pos->y < 0)
    return (BLACK);
  if (pos->x >= pix->clipable.clip_width || pos->y >= \
      pix->clipable.clip_height)
    return (GREEN);
  width = pos[0].y * pix->clipable.clip_width;
  color.full = ((unsigned int *)pix->pixels)[width + pos[0].x];
  return (color.full);
}
