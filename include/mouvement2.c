#include "libmy.h"
#include "struct.h"

void		moveUp(t_map map)
{
	t_coor	largeur;
	t_coor	longueur;

	for (largeur.x = 0; largeur.x < map.width; largeur.x++)
	{
		for (largeur.y = 0; largeur.y < map.height; largeur.y++)
		{
			if (map.tab[largeur.y][largeur.x] == '^')
			{
				longueur.x = largeur.x;
				longueur.y = largeur.y - 1;
				if (longueur.x >= 0 && longueur.y >= 0 &&
					longueur.x < map.width && longueur.y < map.height)
						changePos(map.tab, largeur, longueur);
				largeur.x = map.width;
				largeur.y = map.height;
			}
		}
	}
}

void		moveDown(t_map map)
{
	t_coor	largeur;
	t_coor	longueur;

	for (largeur.x = 0; largeur.x < map.width; largeur.x++)
	{
		for (largeur.y = 0; largeur.y < map.height; largeur.y++)
		{
			if (map.tab[largeur.y][largeur.x] == '^')
			{
				longueur.x = largeur.x;
				longueur.y = largeur.y + 1;
				if (longueur.x >= 0 && longueur.y >= 0 &&
					longueur.x < map.width && longueur.y < map.height)
						changePos(map.tab, largeur, longueur);
				largeur.x = map.width;
				largeur.y = map.height;
			}
		}
	}
}

void		moveLeft(t_map map)
{
	t_coor	largeur;
	t_coor	longueur;

	for (largeur.x = 0; largeur.x < map.width; largeur.x++)
	{
		for (largeur.y = 0; largeur.y < map.height; largeur.y++)
		{
			if (map.tab[largeur.y][largeur.x] == '^')
			{
				longueur.x = largeur.x - 4;
				longueur.y = largeur.y;
				if (longueur.x >= 0 && longueur.y >= 0 &&
					longueur.x < map.width && longueur.y < map.height)
						changePos(map.tab, largeur, longueur);
				largeur.x = map.width;
				largeur.y = map.height;
			}
		}
	}
}


void		moveRight(t_map map)
{
	t_coor	largeur;
	t_coor	longueur;

	for (largeur.x = 0; largeur.x < map.width; largeur.x++)
	{
		for (largeur.y = 0; largeur.y < map.height; largeur.y++)
		{
			if (map.tab[largeur.y][largeur.x] == '^')
			{
				longueur.x = largeur.x + 4;
				longueur.y = largeur.y;
				if (longueur.x >= 0 && longueur.y >= 0 &&
					longueur.x < map.width && longueur.y < map.height)
						changePos(map.tab, largeur, longueur);
				largeur.x = map.width;
				largeur.y = map.height;
			}
		}
	}
}

void	changePos(char **tab, t_coor largeur, t_coor longueur)
{
	if (tab[largeur.y][largeur.x] == '^')
	{
		if (tab[longueur.y][longueur.x] == ' ')
		{
			tab[largeur.y][largeur.x] = ' ';
			tab[longueur.y][longueur.x] = '^';
		}
		if (tab[longueur.y][longueur.x] == 'o')
		{
			tab[largeur.y][largeur.x] = ' ';
			tab[longueur.y][longueur.x] = 'X';
		}
	}

}