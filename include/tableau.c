/*
** tableau.c for  in /Users/taing_k/Desktop/Forza/Git/forza
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Wed Apr 27 09:36:22 2016 TAING Kevin
** Last update Wed Apr 27 09:36:25 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

int	width(char *file)
{
  int	f;
  int	j;
  char	c;
  
  j = 0;
  f = open(file, O_RDONLY, S_IRUSR);
  while (read(f, &c, 1))
    {
      if (c == '\n')
	return (j);
      j++;
    }
  close(f);
  return (j);
}

int	height(char *file)
{
  int  	f;
  int  	i;
  char	c;

  i = 0;
	f = open(file, O_RDONLY, S_IRUSR);
	while (read(f, &c, 1))
		{
		  if (c == '\n')
		    i++;
		}
	close(f);
	return (i);
}

char	**alloctab(int i, int j)
{
  char **tab;
  int	k;
  
  tab = malloc(sizeof(char*) * (i + 1));
  for (k = 0; k < i; k++)
    {
      tab[k] = malloc(sizeof(char) * (j + 1));
	  tab[k][j + 1] = '\0';
    }
  tab[i + 1] = NULL;
  return (tab);
}

char	**tab(char *file)
{
  int c;
  int	f;
  int i;
  int j;
  t_map map;

  c = 0;
  f = open(file, O_RDONLY, S_IRUSR);
  if (f != -1)
    {
      map.tab = alloctab(height(file), width(file));
      i = 0;
      j = 0;
      while (read(f, &c, 1))
	{
	  map.tab[i][j] = c;
	      if (c == '\n')
		{
		  j = 0;
		  i++;
		}
	      j++;
	}
	close(f);
	return(map.tab);
    }
  else
    my_putstr("Ce fichier n'existe pas.\n");
  return (map.tab);
}