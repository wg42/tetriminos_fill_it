#include "../includes/fillit.h"

void		convert_strtab_to_tetri(t_env *e)
{
	int		i;

	if (!(e->tetri = (t_piece**)ft_memalloc(sizeof(t_piece*) * NB_TETRI)))
		ft_error("error");
	i = -1;
	while (++i < NB_TETRI)
	{		
		check_create_tetri(e, i, 0);
		add_tetri_coord_zero(&TETRI_X(i), &TETRI_Y(i));
		first_sharp(TETRI[i]);
	}
}

static int		nb_sharp(t_env *e, int tetri)
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

static void		check_lines_col(t_env *e, int i)
{
	const int		nb_lines = nb_sharp(e, i);
	const int		nb_col = nb_sharp(e, i);

	if ((nb_lines == 1 && nb_col != 4)
	|| (nb_lines == 2 && nb_col != 2 && nb_col != 3)
	|| (nb_lines == 3 && nb_col != 2)
	|| (nb_lines == 4 && nb_col != 1))
		ft_error("error");
	check_tetri(e, i, nb_col, nb_lines);
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

	i = 0;
	while (i < NB_TETRI)
	{
		Y = -1;
		count = 0;
		while (++Y < 4)
		{
			X = -1;
			while (++X < 4)
				if (TETRI_CONTENT(i)[Y][X] == '#')
					check_cur_pos_tetri(e, i, &count);
		}
		i++;
	}
}

char		**tetriminos(char *str)
{
	int		i;
	int		len;
	char	**tetriminos;

	i = 0;
	len = (ft_strlen(str) + 1) / 21;
	tetriminos = (char **)malloc((len + 1) * sizeof (char *));
	while (i < len)
	{
		if (ft_strequ(str, "\n\n") && str != '\0')
			str++;
		if ((tetriminos[i] = ft_strsub(str, 0, 20)))
			str += 21;
		i++;
	}
	tetriminos[i] = NULL;
	return tetriminos;
}

void	get_tetriminos(t_env *e, char *file)
{
	ft_read(&FD, &RD, BUFF, file);
	if (check_tetri_length(RD) || ft_strstr(BUFF, "\n\n\n") != NULL)
		ft_error("error");
	if (!(TETRI_TAB = tetriminos(BUFF)))
		ft_error("error");
	check_tetriminos(e);
	convert_strtab_to_tetri(e);
	check_each_tetri_composition(e);
	check_double_line(NB_TETRI, BUFF);
}
