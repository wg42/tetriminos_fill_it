#include "../includes/fillit.h"

static void		init_tabs(int *lines, int *col)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		lines[i] = 0;
		col[i] = 0;
	}
}

static void		fill_tabs(t_env *e, int tetri, int *lines, int *col)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (is_sharp(TETRI_CONTENT(tetri)[i][j]))
			{
				col[j] = 1;
				lines[i] = 1;
			}
		}
	}
}

static int		search_first(int *tab)
{
	if (tab[0])
		return (0);
	if (tab[1])
		return (1);
	if (tab[2])
		return (2);
	return (3);
}

void			check_tetri(t_env *e, int i, int nb_col, int nb_lines)
{
	int		lines[4];
	int		col[4];
	int		first;

	init_tabs(&lines[0], &col[0]);
	fill_tabs(e, i, &lines[0], &col[0]);
	first = search_first(&col[0]);
	if (nb_col == 2 && (first > 2 || !col[first]))
		ft_error("error");
	if (nb_col == 3 && (first > 1 || !col[first + 1] || !col[first + 2]))
		ft_error("error");
	first = search_first(&lines[0]);
	if (nb_lines == 2 && (first > 2 || !lines[first + 1]))
		ft_error("error");
	if (nb_lines == 3 && (first > 1 || !lines[first + 1] || !lines[first + 2]))
		ft_error("error");
}