#include "../includes/fillit.h"

void		valid_tetri(char **tetri_tab, int x, int y)
{
	x = -1;
	while (tetri_tab[++x] != NULL)
	{
		y = -1;
		while (tetri_tab[++x][++y] != '\0')
		{
			if (tetri_tab[x][y] != '.' &&
				tetri_tab[x][y] != '#')
				ft_error("error");
		}
		if (y != 4)
			ft_error("error");
	}
}


static void		convert_strtab_to_tetri(t_env *e)
{
	int		i;

	if (!(e->tetri = (t_piece**)ft_memalloc(sizeof(t_piece*) * NB_TETRI)))
		ft_exit("error");
	i = -1;
	while (++i < NB_TETRI)
	{
		if (!(TETRI[i] = (t_piece*)ft_memalloc(sizeof(t_piece)))
		|| !(TETRI_CONTENT(i) = (char**)ft_memalloc(sizeof(char*) * 4))
		|| !(TETRI_CONTENT(i)[0] = ft_strsub(TETRI_STRTAB[i * 4], 0, 4))
		|| !(TETRI_CONTENT(i)[1] = ft_strsub(TETRI_STRTAB[i * 4 + 1], 0, 4))
		|| !(TETRI_CONTENT(i)[2] = ft_strsub(TETRI_STRTAB[i * 4 + 2], 0, 4))
		|| !(TETRI_CONTENT(i)[3] = ft_strsub(TETRI_STRTAB[i * 4 + 3], 0, 4)))
			ft_exit("error");
		add_tetri_coord_zero(&TETRI_X(i), &TETRI_Y(i));
		first_sharp(TETRI[i], 0, 0);
	}
}

void	get_tetriminos(t_env *e, char *file)
{
	ft_read(FD, RD, BUFF, file);

	if (check_tetri_length(RD) || ft_strstr(BUFF, "\n\n\n") == NULL)
		ft_error("error");
	if ((TETRI_TAB = ft_strsplit(BUFF, '\n')) == NULL)
		ft_error("error");

	// check_tetriminos(e);
	// check_tetriminos_bis(e);
	// convert_strtab_to_tetri(e);
	// check_each_tetri_composition(e);
	check_double_line(NB_TETRI, BUFF);
}