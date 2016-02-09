#include "../includes/fillit.h"

static void		cp_tetrisaved_to_tetri(t_env *e)
{
	int		i;

	i = -1;
	while (++i < NB_TETRI)
	{
		TETRI[i]->x = TETRI_SAVED[i]->x;
		TETRI[i]->y = TETRI_SAVED[i]->y;
		add_swap_tetri(TETRI[i]->content, TETRI_SAVED[i]->content);
	}
	MAP_SIZE = MAP_SIZE_SAVED;
}

static void		clear_map(t_env *e)
{
	int		i;

	i = -1;
	while (++i < MAP_WIDTH)
		ft_bzero(MAP[i], MAP_WIDTH);
}

static void		fill_map(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < NB_TETRI)
		add_tetri_in_map(e, i);
	i = -1;
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
		{
			if (MAP[i][j])
				MAP[i][j] += 17;
			else
				MAP[i][j] = '.';
		}
	}
}

void			print_map(t_env *e)
{
	int		i;
	int		j;

	cp_tetrisaved_to_tetri(e);
	clear_map(e);
	fill_map(e);
	i = -1;
	while (++i < MAP_SIZE)
	{
		j = -1;
		while (++j < MAP_SIZE)
			ft_putchar((MAP[i][j]) ? MAP[i][j] : '.');
		ft_putchar('\n');
	}
}