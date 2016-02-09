#include "../includes/fillit.h"

void		valid_tetri(char **tetri_tab, int *x, int *y)
{
	*x = -1;
	while (tetri_tab[++(*x)] != NULL)
	{
		*y = -1;
		while (tetri_tab[++(*x)][++(*y)] != '\0')
		{
			if (tetri_tab[*x][*y] != '.' &&
				tetri_tab[*x][*y] != '#')
				ft_error("error");
		}
		if (*y != 4)
			ft_error("error");
	}
}

static void		convert_strtab_to_tetri(t_env *e)
{
	int		i;

	if (!(e->tetri = (t_piece**)ft_memalloc(sizeof(t_piece*) * NB_TETRI)))
		ft_error("error");
	i = -1;
	while (++i < NB_TETRI)
	{
		if (!(TETRI[i] = (t_piece*)ft_memalloc(sizeof(t_piece)))
		|| !(TETRI_CONTENT(i) = (char**)ft_memalloc(sizeof(char*) * 4))
		|| !(TETRI_CONTENT(i)[0] = ft_strsub(TETRI_TAB[i * 4], 0, 4))
		|| !(TETRI_CONTENT(i)[1] = ft_strsub(TETRI_TAB[i * 4 + 1], 0, 4))
		|| !(TETRI_CONTENT(i)[2] = ft_strsub(TETRI_TAB[i * 4 + 2], 0, 4))
		|| !(TETRI_CONTENT(i)[3] = ft_strsub(TETRI_TAB[i * 4 + 3], 0, 4)))
			ft_error("error");
		add_tetri_coord_zero(&TETRI_X(i), &TETRI_Y(i));
		first_sharp(TETRI[i]);
	}
}

static int		nb_line_with_sharp(t_env *e, int tetri)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (TETRI_CONTENT(tetri)[i][j] == '#')
			{
				count++;
				break ;
			}
		}
	}
	return (count);
}

static int		nb_col_with_sharp(t_env *e, int tetri)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (TETRI_CONTENT(tetri)[j][i] == '#')
			{
				count++;
				break ;
			}
		}
	}
	return (count);
}

static void		check_lines_col(t_env *e, int i)
{
	const int		nb_lines = nb_line_with_sharp(e, i);
	const int		nb_col = nb_col_with_sharp(e, i);

	if ((nb_lines == 1 && nb_col != 4)
	|| (nb_lines == 2 && nb_col != 2 && nb_col != 3)
	|| (nb_lines == 3 && nb_col != 2)
	|| (nb_lines == 4 && nb_col != 1))
		ft_error("error");
	check_tetri3(e, i, nb_col, nb_lines);
}

static void		check_cur_pos_tetri(t_env *e, int i, int *count)
{
	if (*count < 4 && ((X < 3 && TETRI_CONTENT(i)[Y][X + 1] == '#')
	|| (X > 0 && TETRI_CONTENT(i)[Y][X - 1] == '#')
	|| (Y < 3 && TETRI_CONTENT(i)[Y + 1][X] == '#')
	|| (Y > 0 && TETRI_CONTENT(i)[Y - 1][X] == '#')))
		*count = *count + 1;
	else
		ft_error("error");
	check_lines_col(e, i);
}

void			check_each_tetri_composition(t_env *e)
{
	int		i;
	int		count;

	i = -1;
	while (++i < NB_TETRI)
	{
		count = 0;
		Y = -1;
		while (++Y < 4)
		{
			X = -1;
			while (++X < 4)
				if (is_sharp(TETRI_CONTENT(i)[Y][X]))
					check_cur_pos_tetri(e, i, &count);
		}
	}
}

void	get_tetriminos(t_env *e, char *file)
{
	ft_read(&FD, &RD, BUFF, file);
	if (check_tetri_length(RD) || ft_strstr(BUFF, "\n") == NULL)
		ft_error("error");
	if ((TETRI_TAB = ft_strsplit(BUFF, '\n')) == NULL)
		ft_error("error");
	check_tetriminos(e);
	convert_strtab_to_tetri(e);
	check_each_tetri_composition(e);
	check_double_line(NB_TETRI, BUFF);
}
