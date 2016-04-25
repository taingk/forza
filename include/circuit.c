#include "libmy.h"

void course()
{
	my_putstr("\033c");
	my_putstr("~~~~ 3 ~~~~\n");
	sleep(1);
	my_putstr("~~~~ 2 ~~~~\n");
	sleep(1);
	my_putstr("~~~~ 1 ~~~~\n");
	sleep(1);
	my_putstr("~ Partez! ~\n");
}