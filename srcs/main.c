#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("error");
	ft_bzero(&e, sizeof(e));
	get_tetriminos(&e, av[1]);
	resolver(&e);
	print_map(&e);
	return (0);
}
