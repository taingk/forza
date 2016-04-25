#ifndef __LIBMY_H__
#define __LIBMY_H__

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
void my_put_nbr(int n);
void menu(void);
int choice(char c);
void printmenu(void);
void nobuff(char c);
void course();

#endif
