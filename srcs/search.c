#include "../includes/fillit.h"

void		first_sharp(t_piece *tetri, int x, int y)
{
	while (tetri->content[y][x] != '#')
	{
		if (x == 4)
		{
			tetri->x = 0;
			tetri->y++;
		}
		tetri->x++;
	}
}