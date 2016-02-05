#include "../includes/fillit.h"

void	ft_error(char *str)
{
	if (str)
		ft_putendl(str);
	else
		ft_putendl("error");
	exit(EXIT_FAILURE);
}