#include "../includes/fillit.h"

int		check_tetri_length(int rd)
{
	return ((RD + 1) % 21 != 0);
}

void 	check_tetriminos(t_env *e)
{
	valid_tetri(TETRI_TAB, X, Y);
	check_x(X);
	add_nb_tetri(&NB_TETRI, X);
	check_limit_tetri(NB_TETRI);
	add_width_and_save(NB_TETRI, &MAP_WIDTH, &MAP_WIDTH_SAVED);
}

void		check_tetriminos_bis(t_env *e)
{
	int		i;
	int		count;

	count = 0;
	X = 0;
	Y = -1;
	while (TETRI_STRTAB[X] != NULL)
	{
		i = -1;
		while (++i < 16)
		{
			if (TETRI_STRTAB[X][++Y] == '#')
				count++;
			if (((i + 1) % 4) == 0)
			{
				X++;
				Y = -1;
			}
		}
		check_x(count);
	}
}