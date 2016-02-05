#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_exit("error");
	ft_bzero(&e, sizeof(e));
	get_tetriminos(&e, av[1]);
	launch_recursive_solver(&e);
	print_solved_map(&e);
	return (0);
}