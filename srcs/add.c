#include "../includes/fillit.h"

void	add_nb_tetri(int *nb_tetri, int x)
{
	*nb_tetri = x / 4;
}

void	add_width_and_save(int nb_tetri, int *mapw, int *mapws)
{
	*mapw = nb_tetri * 4 + 1;
	*mapws = *mapw;
}

void	add_tetri_coord_zero(int *x, int *y)
{
	*x = 0;
	*y = 0;
}