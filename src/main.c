/*
** main.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/gfx_raytracer2
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 14:47:32 2016 Desriac
** Last update Sun May 22 21:25:03 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "move.h"
#include "my.h"

static t_bunny_response key(t_bunny_event_state state,
			    t_bunny_keysym      key,
			    void                *data)
{
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  itali_core(data, key);
  return (GO_ON);
}

static t_bunny_response mainloop(void *my_data)
{
  t_data                *data;
  t_bunny_position      pos_array;

  data = my_data;
  pos_array.x = 0;
  pos_array.y = 0;
  rt_thread(data);
  bunny_blit(&data->win->buffer, &data->array->clipable, &pos_array);
  bunny_display(data->win);
  return (GO_ON);
}

int                     main(int ac, char **av)
{
  t_data         data;

  if (ac != 2)
    return (errstr("too few arg\n"));
  if (set_data(&data, av) != 0)
    return (EXIT_FAILURE);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "RT2")) == NULL)
    return (EXIT_FAILURE);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, FPS, &data);
  bunny_delete_clipable(&data.array->clipable);
  bunny_stop(data.win);
  return (EXIT_SUCCESS);
}
