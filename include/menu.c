#include "libmy.h"

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
	while (1)
	{
		nobuff(c = getchar());
		if (c == 'b')
		{
			my_putstr("\nA bientot!\n\n");
			return (0);
		}
		else if (c == 'a')
		{
			my_putstr("\nAllons-y! Preparation du circuit!\n");
			sleep(2);
			course();
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

void nobuff(char c)
{
	while (c != '\n' && c != EOF)
		c = getchar();
}