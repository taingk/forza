#include "libmy.h"
#include "struct.h"
#include <time.h>

int ennemie(t_map map)
{
	int n;
	int i;

	srand(time(NULL));
	for (i = 0; i < map.width; i++);
	n = (rand() % (4 - 1 + 1)) + 1;
	if (n == 1 && map.tab[0][5] == ' ' && map.tab[1][5] == ' ')
		map.tab[0][5] = 'o';
	else if (n == 2 && map.tab[0][9] == ' ' && map.tab[1][9] == ' ')
		map.tab[0][9] = 'o';
	else if (n == 3 && map.tab[0][13] == ' ' && map.tab[1][13] == ' ')
		map.tab[0][13] = 'o';
	descente(map);
	// if (descente(map) == 1)
		// return (1);
	return (0);
}

int descente(t_map map)
{
	t_coor	axe;
	t_coor	ennemie;

	for (axe.x = 0; axe.x < map.width; axe.x++)
	{
		for (axe.y = 0; axe.y < map.height; axe.y++)
		{
			if (map.tab[axe.y][axe.x] == 'o')
			{
				ennemie.x = axe.x;
				ennemie.y = axe.y + 1;
				if (ennemie.x >= 0 && ennemie.y >= 0 &&
					ennemie.x < map.width && ennemie.y < map.height)
					ennemiePos(map.tab, ennemie, axe);
				else
				// {
					map.tab[axe.y][axe.x] = ' ';
					// return (1);
				// }
				axe.x = map.width;
				axe.y = map.height;
				axe.x = ennemie.x;
				axe.y = ennemie.y;
			}
		}
	}
	return (0);
}

void ennemiePos(char **tab, t_coor axe, t_coor ennemie)
{
	if (tab[ennemie.y][ennemie.x] == 'o')
	{
		if (tab[axe.y][axe.x] == ' ')
		{
			tab[ennemie.y][ennemie.x] = ' ';
			tab[axe.y][axe.x] = 'o';
		}
		if (tab[axe.y][axe.x] == '^')
		{
			tab[ennemie.y][ennemie.x] = ' ';
			tab[axe.y][axe.x] = 'X';
		}
	}
}

void display(t_map map)
{
	t_coor coor;

	for (coor.y = 0; coor.y < map.height; coor.y++)
	{
		for (coor.x = 0; coor.x < (map.width + 1); coor.x++)
		{
			if (map.tab[coor.y][coor.x] == '^')
				my_putchar('^');
			else if (map.tab[coor.y][coor.x] == '|')
				my_putchar('|');
			else if (map.tab[coor.y][coor.x] == 'o')
				my_putchar('o');
			else if (map.tab[coor.y][coor.x] == 'X')
				my_putchar('X');
			else if (map.tab[coor.y][coor.x] == '-')
				my_putchar('-');
			else 
				my_putchar(' ');
		}
		my_putchar('\n');
	}
}

void gogo(t_map map)
{
	char c;
	int etat;
	int nb;
	// int score;

	// score = 0;
	nb = -1;
	etat = 1;
	while (!(etat = crash(map)))
	{
		if (move(map, c) == 1)
			nb++;
		if ((nb % 2) == 0)
			ennemie(map);
		display(map);
		// my_putstr("Score >");
		// if (ennemie(map) == 1)
			// score++;
		// my_put_nbr(score);
		my_putstr("\nOù voulez-vous aller ? (w/s/a/d) > ");
		nobuff(c = getchar());
		my_putchar('\n');
	}
	display(map);
	if (etat == -1)
	{
		my_putstr("\nVous vous etes crasher contre une voiture!\n");
		my_putstr("C'est perdu...\n");
	}
}

int move(t_map map, char c)
{
	if (c == 'w' || c == 'W')
		moveUp(map);
	else if (c == 's' || c == 'S')
		moveDown(map);
	else if (c == 'a' || c == 'A')
		moveLeft(map);
	else if (c == 'd' || c == 'D')
		moveRight(map);
	return (1);
}

int crash(t_map map)
{
	int	i;
	int	j;

	for (i = 0; i < map.width; i++)
		for (j = 0; j < map.height; j++)
			if (map.tab[j][i] == '^')
				return (0);
	for (i = 0; i < map.width; i++)
		for (j = 0; j < map.height; j++)
			if (map.tab[j][i] == 'X')
				return (-1);
	return (1);
}