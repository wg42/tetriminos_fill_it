#include "../includes/fillit.h"

void		first_sharp(t_piece *tetri)
{
	tetri->y_start = 0;
	tetri->x_start = 0;
	while (tetri->content[tetri->y_start][tetri->x_start] != '#')
	{
		if (tetri->x_start == 4)
		{
			tetri->x_start = 0;
			tetri->y_start++;
		}
		tetri->x_start++;
	}
}