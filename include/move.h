/*
** move.h for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri May 20 00:55:50 2016 Desriac
** Last update Sun May 22 21:46:14 2016 Desriac
*/

#ifndef MOVE_H_
# define MOVE_H_

# define YCOS cos(-data->cam.yalpha)
# define YSIN sin(-data->cam.yalpha)
# define YCOSS cos(-data->cam.yalpha + M_PI / 2)
# define YSINS sin(-data->cam.yalpha + M_PI / 2)
# define MV 0.4
# define SIX sph->c.x
# define SIY sph->c.y
# define SIZ sph->c.z

void    itali_core(t_data *data, t_bunny_keysym key);
void    itali_move(t_data *data, t_bunny_keysym key);
void    block_plan(t_data *data);

#endif /* !MOVE_H_ */
