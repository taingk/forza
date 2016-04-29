/*
** menu.c for  in /Users/taing_k/Desktop/Forza/Git/forza
** 
** Made by TAING Kevin
** Login   <taing_k@etna-alternance.net>
** 
** Started on  Mon Apr 25 15:53:51 2016 TAING Kevin
** Last update Mon Apr 25 15:53:52 2016 TAING Kevin
*/

#include "libmy.h"
#include "struct.h"

void menu(void)
{
	char c;

	c = '\0';
	printmenu();
	choice(c);
}

void printmenu(void)
{
	my_putstr("\033c");
	my_putstr(" __________________: Forza :____________________ \n");
	my_putstr("|                                               |\n");
	my_putstr("|                                               |\n");
	my_putstr("|                                               |\n");
	my_putstr("|                  a : Jouer                    |\n");
	my_putstr("|                 b : Quitter                   |\n");
	my_putstr("|                                               |\n");
	my_putstr("|                                               |\n");
	my_putstr("|                                               |\n");
	my_putstr("|__________________: Forza :____________________|\n\n");
	my_putstr("Que voulez-vous faire? (a/b) > ");
}

int choice(char c)
{
	t_map map;

	while (1)
	{
		nobuff(c = getchar());
		if (c == 'b' || c == 'B')
		{
			my_putstr("\nA bientot!\n\n");
			return (0);
		}
		else if (c == 'a' || c == 'A')
		{
			my_putstr("\nAllons-y! Preparation du circuit!\n");
			sleep(2);
			course();
			map.tab = tab("include/map.txt");
		 	map.width = width("include/map.txt");
		  	map.height = height("include/map.txt");
		  	gogo(map);
			return (0);
		}
		else
		{
			my_putstr("\nCette commande n'existe pas.\n");
			my_putstr("\nQue voulez-vous faire? (a/b) > ");
		}
	}
	return (0);
}

void course()
{
	my_putstr("\033c");
	my_putstr("~~~~~~~~~~~~~~~~~~~ ( 3 ) ~~~~~~~~~~~~~~~~~~~\n");
	sleep(1);
	my_putstr("~~~~~~~~~~~~~~~~~~~ ( 2 ) ~~~~~~~~~~~~~~~~~~~\n");
	sleep(1);
	my_putstr("~~~~~~~~~~~~~~~~~~~ ( 1 ) ~~~~~~~~~~~~~~~~~~~\n");
	sleep(1);
	my_putstr("~~~~~~~~~~~~~~~~~~ Partez! ~~~~~~~~~~~~~~~~~~\n");
	my_putchar('\n');
}

void nobuff(char c)
{
	while (c != '\n' && c != EOF)
		c = getchar();
}
