#include "../includes/fillit.h"

void 	check_tetriminos(t_env *e)
{
	X = -1;
	while (TETRI_TAB[++X] != NULL)
	{
		Y = -1;
		while (TETRI_TAB[++X][++Y] != '\0')
		{
			if (TETRI_TAB[X][Y] != '.' &&
				TETRI_TAB[X][Y] != '#')
				ft_error("error");
		}
		if (Y != 4)
			ft_error("error");
	}
	if (X % 4 != 0 || X == 0)
		ft_error("error");
	NB_TETRI = e->x / 4;
	if (NB_TETRI > 26 || NB_TETRI < 0)
		ft_error("error");
	if (NB_TETRI == 0)
		ft_error(NULL);
	env->map_width = NB_TETRI * 4 + 1;
	env->map_width_saved = env->map_width;
}

void	get_tetriminos(t_env *e, char *file)
{
	int	i;

	if ((e->fd = open(f, O_RDONLY)) == -1)
		ft_error("error");
	if ((e->rd = read(e->fd, e->buf, BUFF_SIZE)) == -1 ||
		e->rd == 546)
		ft_error("error");
	if (close(e->fd) == -1)
		ft_error("error");
	if ((e->rd + 1) % 21 != 0 || ft_strstr(e->buf, "\n\n\n") == NULL)
		ft_error("error");
	if ((e->tetri_tab = ft_strsplit(e->buf, '\n')) == NULL)
		ft_error("error");
	// check tetriminos
	//
	// convertir strtab vers tetri
	// check chaque composition de tetri
	i = -1;
	while (++i < e->nb_tetri - 1)
	{
		if (e->buf[((i + 1) * 20 + i - 1)] != '\n' ||
			e->buf[((i + 1) * 20 + i)] != '\n')
			ft_error("error");
	}
	printf("%s\n", e->tetri_tab[0]);
}