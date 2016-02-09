#include "../includes/fillit.h"

void	check_create_tetri(t_piece *tetri, char **content, char **tetri_tab, int *i)
{
	if (!(tetri[*i] = (t_piece*)ft_memalloc(sizeof(t_piece)))
		|| !(content = (char**)ft_memalloc(sizeof(char*) * 4))
		|| !(content[0] = ft_strsub(tetri_tab[*i * 4], 0, 4))
		|| !(content[1] = ft_strsub(tetri_tab[*i * 4 + 1], 0, 4))
		|| !(content[2] = ft_strsub(tetri_tab[*i * 4 + 2], 0, 4))
		|| !(content[3] = ft_strsub(tetri_tab[*i * 4 + 3], 0, 4)))
			ft_error("error");
}