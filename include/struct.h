#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct	s_coor
{
	int			x;
	int			y;
}				t_coor;

typedef struct  s_map
{
	char		**tab;
	int			width;
	int			height;
}				t_map;

#endif