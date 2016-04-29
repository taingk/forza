#ifndef __LIBMY_H__
#define __LIBMY_H__

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
void my_put_nbr(int n);
void menu(void);
int choice(char c);
void printmenu(void);
void nobuff(char c);
void course();
int	width(char *file);
int	height(char *file);
char **alloctab(int i, int j);
char **tab(char *file);
void display(t_map map);
void gogo(t_map map);
int move(t_map map, char c);
void moveUp(t_map map);
void moveDown(t_map map);
void moveLeft(t_map map);
void moveRight(t_map map);
void changePos(char **tab, t_coor largeur, t_coor longueur);
void ennemiePos(char **tab, t_coor axe, t_coor ennemie);
int crash(t_map map);
int ennemie(t_map map);
int descente(t_map map);

#endif
