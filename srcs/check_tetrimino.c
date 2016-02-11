#include "../includes/fillit.h"

void		valid_piece(t_env *e)
{
	X = 0;
	while (TETRI_TAB[X] != NULL)
	{
		Y = 0;
		while (TETRI_TAB[X][Y] != '\0')
		{
			if (TETRI_TAB[X][Y] != '.' && TETRI_TAB[X][Y] != '#')
			{
				if (Y == 4)
					break;
				ft_error("error");
			}
			Y++;
		}
		if (Y != 4)
			ft_error("error");
		X++;
	}
}

void 	check_tetriminos(t_env *e)
{
	valid_piece(e);
	check_coord(X);
	add_nb_tetri(&NB_TETRI, X);
	check_limit_tetri(NB_TETRI);
	add_width_and_save(NB_TETRI, &MAP_WIDTH, &MAP_WIDTH_SAVED);
	check_tetriminos_sharp(e);
}

void		check_tetriminos_sharp(t_env *e)
{
	int		count;

	count = 0;
	X = 0;
	Y = 0;
	while (TETRI_TAB[X] != NULL)
	{
		while (TETRI_TAB[X][Y] != '\0')
		{
			if (TETRI_TAB[X][Y] == '#')
				count++;
			Y++;
		}
		check_coord(count);
		X++;
	}
}