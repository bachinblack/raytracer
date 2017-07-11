/*
** rt.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 20:12:40 2016 Desriac
** Last update Sat May 21 14:03:55 2016 Desriac
*/

#include <pthread.h>
#include "rt.h"

int	rt_thread(t_data *data)
{
  pthread_t     th[4];
  void		*ret;

  pthread_create(&th[0], NULL, first_screen, data);
  pthread_create(&th[1], NULL, sec_screen, data);
  pthread_create(&th[2], NULL, third_screen, data);
  pthread_create(&th[3], NULL, last_screen, data);
  (void)pthread_join(th[0], &ret);
  (void)pthread_join(th[1], &ret);
  (void)pthread_join(th[2], &ret);
  (void)pthread_join(th[3], &ret);
  return (0);
}

int	rt(t_data *data)
{
  first_screen(data);
  sec_screen(data);
  third_screen(data);
  last_screen(data);
  return (0);
}
