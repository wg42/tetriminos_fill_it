#include "../includes/fillit.h"

void	check_create_tetri(t_env *e, int i, int tetri_save)
{
	if (tetri_save == 1)
	{
		if (!(TETRI_SAVED[i] = (t_piece*)ft_memalloc(sizeof(t_piece)))
			|| !(TETRI_SCONTENT(i) = (char**)ft_memalloc(sizeof(char*) * 20))
			|| !(TETRI_SCONTENT(i)[0] = ft_strsub(TETRI_TAB[i], 0, 20))
			|| !(TETRI_SCONTENT(i)[1] = ft_strsub(TETRI_TAB[i + 1], 0, 20))
			|| !(TETRI_SCONTENT(i)[2] = ft_strsub(TETRI_TAB[i + 2], 0, 20))
			|| !(TETRI_SCONTENT(i)[3] = ft_strsub(TETRI_TAB[i + 3], 0, 20)))
				ft_error("error");
	}
	if (!(TETRI[i] = (t_piece*)ft_memalloc(sizeof(t_piece)))
		|| !(TETRI_CONTENT(i) = (char**)malloc(sizeof(char*) * NB_TETRI))
		|| !(TETRI_CONTENT(i)[0] = ft_strsub(TETRI_TAB[i], 0, 20))
		|| !(TETRI_CONTENT(i)[1] = ft_strsub(TETRI_TAB[i + 1], 0, 20))
		|| !(TETRI_CONTENT(i)[2] = ft_strsub(TETRI_TAB[i + 2], 0, 20))
		|| !(TETRI_CONTENT(i)[3] = ft_strsub(TETRI_TAB[i + 3], 0, 20)))
			ft_error("error");
}