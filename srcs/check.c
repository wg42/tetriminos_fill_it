#include "../includes/fillit.h"

void	check_limit_tetri(int nb_tetri)
{
	if (nb_tetri > 26 || nb_tetri < 0)
		ft_error("error");
	if (nb_tetri == 0)
		ft_error(NULL);
}

int		check_tetri_length(int rd)
{
	return ((rd + 1) % 21 != 0);
}

void	check_coord(int coord)
{
	if (coord % 4 != 0 || coord == 0)
		ft_error("error");
}

void	check_double_line(int nb_tetri, char *buff)
{
	int i;

	i = -1;
	while (++i < nb_tetri - 1)
	{
		if (buff[((i + 1) * 20 + i - 1)] != '\n' ||
			buff[((i + 1) * 20 + i)] != '\n')
			ft_error("error");
	}
}

int		is_sharp(char c)
{
	return (c == '#');
}
