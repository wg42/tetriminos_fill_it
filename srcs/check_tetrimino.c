#include "../includes/fillit.h"

void 	check_tetriminos(t_env *e)
{
	valid_tetri(TETRI_TAB, &X, &Y);
	check_x(X);
	add_nb_tetri(&NB_TETRI, X);
	check_limit_tetri(NB_TETRI);
	add_width_and_save(NB_TETRI, &MAP_WIDTH, &MAP_WIDTH_SAVED);
	check_tetriminos2(e, -1, 0);
	ft_putendl("ok");
}

void		check_tetriminos2(t_env *e, int i, int count)
{
	X = 0;
	Y = -1;
	while (TETRI_TAB[X] != NULL)
	{
		while (++i < 16)
		{
			if (is_sharp(TETRI_TAB[X][++Y]))
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