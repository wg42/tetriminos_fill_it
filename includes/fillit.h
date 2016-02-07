#ifndef __FILLIT_H__
# define __FILLIT_H__
//# include "../libft/libft.h"
# include <fcntl.h>

# define PIECE 21
# define MAX_PIECE 26
# define BUFF_SIZE 546

# define TETRI_TAB env->tetri_tab
# define NB_TETRI env->nb_tetri
# define FD env->fd
# define RD env->rd
# define BUFF env->buff
# define BUFF_SIZE 546
# define X env->x
# define Y env->y

# define MAP env->map
# define MAP_SIZE env->map_size
# define MAP_SIZE_SAVED env->map_size_saved
# define MAP_WIDTH env->map_width
# define MAP_WIDTH_SAVED env->map_width_saved

# define TETRI env->tetri
# define TETRI_CONTENT(i) env->tetri[i]->content
# define TETRI_X(i) env->tetri[i]->x
# define TETRI_Y(i) env->tetri[i]->y
# define TETRI_XS(i) env->tetri[i]->x_start
# define TETRI_YS(i) env->tetri[i]->y_start
# define TETRI_SAVED env->tetri_saved
# define TETRI_SCONTENT(i) env->tetri_saved[i]->content

typedef struct		s_piece
{
	char			**content;
	int				x;
	int				y;
	int				x_start;
	int				y_start;
}					t_piece;

typedef struct		s_env
{
	char			**tetri_tab;
	int				nb_tetri;
	int				fd;
	int				rd;
	char			buff[BUFF_SIZE + 1];
	int				x;
	int				y;

	char			**map;
	int				map_size;
	int				map_size_saved;
	int				map_width;
	int				map_width_saved;

	t_piece			**tetri;
	t_piece			**tetri_saved;
}					t_env;

/* READ_FILE.C */
void 	ft_read(int fd, int rd, char **buff);

/* CHECK.C */
void	check_limit_tetri(int nb_tetri);
void	check_x(int x);
void	check_double_line(int nb_tetri, char **buff);

/* ADD.C */
void	add_nb_tetri(int *nb_tetri, int x);
void	add_width_and_save(int nb_tetri, int *mapw, int *mapws);
void	add_tetri_coord_zero(int *x, int *y);

/* SEARCH.C */
void	first_sharp(t_piece *tetri, int x, int y);

/* CHECK_TETRIMINO.C */
void 	check_tetriminos(t_env *e);
void	check_tetriminos_bis(t_env *e);

/* GET_TETRIMINOS.C */
void	get_tetriminos(t_env *e, char *file);

/* RESOLVER.C */
void	resolver(t_env *e);

/* PRINT_MAP.C */
void	print_map(t_env *e);

/* ERROR.C */
void	ft_error(char *str);

#endif
