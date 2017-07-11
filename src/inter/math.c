/*
** math.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri May 20 00:03:29 2016 Desriac
** Last update Sun May 22 17:09:18 2016 Desriac
*/

#include <math.h>
#include <lapin.h>
#include "rt.h"

float   det(float a, float b, float c)
{
  return (pow(b, 2) - (4 * a * c));
}

int	eq_para(t_vect *v, double k, t_point *p)
{
  p->x = (v->vx * k) + v->x;
  p->y = (v->vy * k) + v->y;
  p->z = (v->vz * k) + v->z;
  return (0);
}

int	vect_u(t_vect *vect)
{
  t_vect        tmp;
  double	norme;

  tmp = *vect;
  norme = sqrt(pow(vect->vx - vect->x, 2) +
	       pow(vect->vy - vect->y, 2) +
	       pow(vect->vz - vect->z, 2));
  if (norme != 0)
    {
      tmp.vx = ((vect->vx - vect->x)/ norme);
      tmp.vy = ((vect->vy - vect->y) / norme);
      tmp.vz = ((vect->vz - vect->z)/ norme);
    }
  *vect = tmp;
  return (0);
}

int     produit_scalaire(t_vect *vect1, t_vect *vect2)
{
  double   u;
  double   v;

  u = sqrt(pow(vect1->x, 2) + pow(vect1->y, 2) + pow(vect1->z, 2));
  v = sqrt(pow(vect2->x, 2) + pow(vect2->y, 2) + pow(vect2->z, 2));
  return ((pow(u, 2) + pow(v, 2) - pow((u - v), 2)) / 2);
}
