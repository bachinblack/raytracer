/*
** my.h for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 17:51:19 2016 Desriac
** Last update Sun May 22 21:46:00 2016 Desriac
*/

#ifndef MY_H_
# define MY_H_

# include <lapin.h>

int		my_strlen(const char *str);
int		errstr(const char *str);
int		my_strcmp(const char *str, const char *comp);
char		*my_strdup(const char *src);
int		get_intnbr(const char *str);
void		my_putchar(char c);
void		my_putstr(const char *str);
void		my_putnbr(int nb);
unsigned int    get_unsnbr(const char *str);
unsigned int    getpixel(t_bunny_pixelarray *pix, t_bunny_position *pos);
int		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color);
#endif /* !MY_H_ */
