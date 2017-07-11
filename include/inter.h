/*
** inter.h for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri May 20 00:16:19 2016 Desriac
** Last update Sun May 22 21:46:40 2016 Desriac
*/

#ifndef INTER_H_
# define INTER_H_

# include "rt.h"

# define RE color.argb[RED_CMP]
# define GR color.argb[GREEN_CMP]
# define BL color.argb[BLUE_CMP]

typedef int(*t_fill_obj)(t_hit*, void*, t_vect*, double);
typedef int(*t_fill_plan)(t_hit*, t_plan*, double);

int     hit_light(t_data *data, t_hit *hit);
int	hit_obj(t_data *data, t_hit *hit, t_vect *ray);

/*
** inter fct
*/

int     ground(t_hit *hit, t_vect *r, t_fill_plan fct);
int     inter_sphere(t_sphere *sph, t_hit *hit, t_vect *r, t_fill_obj fct);
int     inter_cylinder(t_cylinder *cy, t_hit *hit, t_vect *r, t_fill_obj fct);
int     inter_cone(t_cone *co, t_hit *hit, t_vect *r, t_fill_obj fct);
void    inter_square(t_hit *hit, t_square *square);
void	guitar(t_hit *hit, t_square *square);
void    find_plany(t_vect *r, t_plan *plan, t_hit *hit, t_fill_plan fct);
void    find_planz(t_vect *r, t_plan *plan, t_hit *hit, t_fill_plan fct);
void    find_planx(t_vect *r, t_plan *plan, t_hit *hit, t_fill_plan fct);

/*
** fill
*/

int	fill_sphere(t_hit *hit, void *sph, t_vect *r, double t);
int     fill_cylinder(t_hit *hit, void *obj, t_vect *r, double t);
int     fill_cone(t_hit *hit, void *obj, t_vect *r, double t);
int     fill_planx(t_hit *hit, t_plan *plan, double k);
int     fill_plany(t_hit *hit, t_plan *plan, double k);
int     fill_planz(t_hit *hit, t_plan *plan, double k);
int     fill_plang(t_hit *hit, t_plan *plan, double k);

/*
** light
*/

int     light_sphere(t_hit *hit, void *sph, t_vect *r, double t);
int     light_cylinder(t_hit *hit, void *obj, t_vect *r, double t);
int     light_cone(t_hit *hit, void *obj, t_vect *r, double t);
int     light_plan(t_hit *hit, t_plan *plan, double k);
int     light_plang(t_hit *hit, t_plan *plan, double k);

/*
** math fct
*/

float   det(float a, float b, float c);
int     eq_para(t_vect *v, double k, t_point *p);
int     vect_u(t_vect *vect);
int     produit_scalaire(t_vect *vect1, t_vect *vect2);
void    rotatx(t_vect *vect, float alpha);
void    rotaty(t_vect *vect, float alpha);
void    rotatz(t_vect *vect, float alpha);

int     move_it(t_data *data, t_hit *hit);
void    warp_me(t_data *data, t_cone *co);

#endif /* !INTER_H_ */
