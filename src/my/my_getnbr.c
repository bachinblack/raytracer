/*
** my_getnbr.c for rt2 in /home/desria-m/rendu/Infographie/in_progress/rt_test
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Thu May 19 17:45:39 2016 Desriac
** Last update Sat May 21 13:59:41 2016 Desriac
*/

static unsigned int    my_negnbr(const char *str,
				 unsigned int i,
				 unsigned int nbr,
				 unsigned int mult)
{
  mult = 1;
  i = 1;
  nbr = 0;
  while (str[i] != '\0')
    {
      mult = mult * 10;
      i = i + 1;
    }
  i = 1;
  while (str[i] != '\0')
    {
      mult = mult / 10;
      nbr = nbr + ((str[i] - '0') * mult);
      i = i + 1;
    }
  return (-nbr);
}

int	get_intnbr(const char *str)
{
  int	nbr;
  int   i;
  int   mult;

  (1 ? mult = 1, i = 0, nbr = 0 : 0);
  while (str[i] != '\0')
    {
      if ((str[++i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	return (0);
    }
  i = 0;
  while (str[i] != '\0')
    {
      mult = mult * 10;
      i = i + 1;
    }
  i = 0;
  while (str[i] != '\0')
    {
      mult = mult / 10;
      nbr = nbr + ((str[i] - '0') * mult);
      i = i + 1;
    }
  return (str[0] == '-' ? (int)my_negnbr(str, i, nbr, mult) : (nbr));
}

unsigned int	get_unsnbr(const char *str)
{
  unsigned int  nbr;
  unsigned int  i;
  unsigned int  mult;

  (1 ? mult = 1, i = 0, nbr = 0 : 0);
  while (str[i] != '\0')
    {
      if ((str[++i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	return (0);
    }
  i = 0;
  while (str[i] != '\0')
    {
      mult = mult * 10;
      i = i + 1;
    }
  i = 0;
  while (str[i] != '\0')
    {
      mult = mult / 10;
      nbr = nbr + ((str[i] - '0') * mult);
      i = i + 1;
    }
  return (str[0] == '-' ? my_negnbr(str, i, nbr, mult) : nbr);
}
