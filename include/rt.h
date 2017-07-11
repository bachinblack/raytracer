/*
** inter.h for rt2 in /home/desria-m/rendu/Infographie/in_progress/gfx_raytracer2
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 14:08:44 2016 Desriac
** Last update Sun May 22 21:43:48 2016 Desriac
*/

#ifndef RT_H_
# define RT_H_

# include <lapin.h>

# define WIDTH (1024)
# define HEIGHT (768)
# define W (WIDTH)
# define H (HEIGHT)
# define FPS (30)
# define DIST (1)
# define FOV_X (WIDTH / 1.0)
# define FOV_Y (HEIGHT / 1.0)
# define AMB (0.3)

/*
** macro
*/

# define ABS(x) (x > 0) ? (x) : (-(x))

/*
** struc
*/

typedef struct          s_point
{
  double                 x;
  double                 y;
  double                 z;
}                       t_point;

typedef struct          s_vect
{
  double                 x;
  double                 y;
  double                 z;
  double                 vx;
  double                 vy;
  double                 vz;
}                       t_vect;

typedef struct		s_plan
{
  t_color		color;
  t_color		color2;
  int			cad;
  char			axis;
  int			add;
  double		y;
  float			alpha;
}			t_plan;

typedef struct          s_guitar
{
  t_color               color;
  double		add;
}                       t_guitar;

typedef struct		s_square
{
  char			obj;
  t_color		color;
  int			size;
  t_point		c;
  t_bunny_pixelarray	*pix;
}			t_square;

typedef struct          s_sphere
{
  t_point               c;
  double                r;
  t_color               color;
}                       t_sphere;

typedef struct          s_cylinder
{
  t_point              c;
  double               r;
  t_color              color;
}                       t_cylinder;

typedef struct          s_cone
{
  t_point		c;
  t_point		tp;
  double		a;
  t_color		color;
}                       t_cone;

typedef struct          s_obj
{
  int			nb_p;
  t_plan		*plan;
  int			nb_s;
  t_sphere		*sphere;
  int			nb_cy;
  t_cylinder		*cylinder;
  int			nb_co;
  t_cone		*cone;
  int			nb_sq;
  t_square		*square;
}                       t_obj;

typedef struct          s_light
{
  t_point               c;
}                       t_light;

typedef struct          s_cam
{
  double                x;
  double                y;
  double                z;
  double                xalpha;
  double                yalpha;
  double                zalpha;
  double		zoom;
}                       t_cam;

typedef struct          s_data
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *array;
  t_obj                 obj;
  int                   nb_l;
  t_light               *light;
  t_cam			cam;
  t_bunny_keysym        lastkey;
}                       t_data;

typedef struct          s_hit
{
  t_vect		ray;
  double                k;
  t_color               color;
  t_bunny_position      pos;
  t_point               pt;
  char                  *type;
  void                  *obj;
  void			*lobj;
  t_point		lpt;
  t_vect                nv;
}                       t_hit;

/*
** fct
*/

int	set_data(t_data *data, char **av);
int	rt(t_data *data);
int     rt_thread(t_data *data);

/*
** thread
*/

void    *first_screen(void *my_data);
void    *sec_screen(void *my_data);
void    *third_screen(void *my_data);
void	*last_screen(void *data);
int	screen(t_data *data, t_hit *hit);

#endif /* !RT_H_ */
