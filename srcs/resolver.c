#include "../includes/fillit.h"

static int		calc_size_start_value(t_env *e)
{
	int		n;
	float	r;
	float	s;
	int		i;

	n = (NB_TETRI) ? NB_TETRI : 1;
	r = 1;
	i = 0;
	while (++i <= n)
		r = 0.5 * (r + n / r);
	s = r - (int)r;
	return ((s > 0) ? (int)r + 1 : r);
}

static void		init_before_recursive(t_env *e)
{
	int			i;

	if (!(TETRI_SAVED = (t_piece**)ft_memalloc(sizeof(t_piece*) * NB_TETRI)))
		ft_error("error");
	i = -1;
	while (++i <= NB_TETRI)
	{
		check_create_tetri(e, i, 1);
		add_tetri_coord_zero(&TETRI_SAVED[i]->x, &TETRI_SAVED[i]->y);
	}
	MAP = (char**)ft_memalloc(sizeof(char*) * MAP_WIDTH);
	i = -1;
	while (++i <= MAP_WIDTH)
		MAP[i] = (char*)ft_strnew(MAP_WIDTH);
	MAP_SIZE = calc_size_start_value(e) ;
	MAP_SIZE_SAVED = calc_size_start_value(e);
	MAP_WIDTH = calc_size_start_value(e);
}

static void		recursive_solver(t_env *e, int cur_tetri)
{
	TETRI_Y(cur_tetri) = -1;
	while (MAP_SIZE_SAVED != 0 && ++TETRI_Y(cur_tetri) < MAP_WIDTH)
	{
		TETRI_X(cur_tetri) = -1;
		while (MAP_SIZE_SAVED != 0 && ++TETRI_X(cur_tetri) < MAP_WIDTH)
		{
			if (add_tetri_in_map(e, cur_tetri))
				continue ;
			if (cur_tetri + 1 == NB_TETRI)
			{
				save_map(e);
				return ;
			}
			else
				recursive_solver(e, cur_tetri + 1);
			sharp_to_letter(e, cur_tetri, 0);
		}
	}
}

void			resolver(t_env *e)
{
	init_before_recursive(e);
	while (++MAP_WIDTH < MAP_WIDTH_SAVED && MAP_SIZE_SAVED != 0)
		recursive_solver(e, 0);
}
