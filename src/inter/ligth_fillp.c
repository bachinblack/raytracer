/*
** ligth_fill_plan.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Sun May 22 15:59:40 2016 Desriac
** Last update Sun May 22 16:06:28 2016 Desriac
*/

#include <lapin.h>
#include "rt.h"
#include "inter.h"

int     light_plan(t_hit *hit, t_plan *plan, double k)
{
  hit->lobj = plan;
  hit->k = k;
  return (0);
}

int     light_plang(t_hit *hit, t_plan *plan, double k)
{
  hit->lobj = plan;
  hit->k = k;
  return (0);
}
