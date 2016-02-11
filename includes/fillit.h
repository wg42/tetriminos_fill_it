#ifndef __FILLIT_H__
# define __FILLIT_H__
# include "../libft/libft.h"
# include <fcntl.h>

# define PIECE 21
# define MAX_PIECE 26
# define BUFF_SIZE 546

# define TETRI_TAB e->tetri_tab
# define NB_TETRI e->nb_tetri
# define FD e->fd
# define RD e->rd
# define BUFF e->buff
# define BUFF_SIZE 546
# define X e->x
# define Y e->y

# define MAP e->map
# define MAP_SIZE e->map_size
# define MAP_SIZE_SAVED e->map_size_saved
# define MAP_WIDTH e->map_width
# define MAP_WIDTH_SAVED e->map_width_saved

# define TETRI e->tetri
# define TETRI_CONTENT(i) e->tetri[i]->content
# define TETRI_X(i) e->tetri[i]->x
# define TETRI_Y(i) e->tetri[i]->y
# define TETRI_XS(i) e->tetri[i]->x_start
# define TETRI_YS(i) e->tetri[i]->y_start
# define TETRI_SAVED e->tetri_saved
# define TETRI_SCONTENT(i) e->tetri_saved[i]->content

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
void 	ft_read(int *fd, int *rd, char *buff, char *file);

/* FUNCTION.C */
void	replace_tetri_in_map(t_env *e, int nb_tetri, char c);
void	sharp_to_letter(t_env *e, int nb_tetri, char c);
int		ft_max(int x, int y);
void	save_map(t_env *e);
int		add_tetri_in_map(t_env *e, int nb_tetri);

/* CHECK.C */
void	check_limit_tetri(int nb_tetri);
void	check_coord(int coord);
void	check_double_line(int nb_tetri, char *buff);
int		check_tetri_length(int rd);
int		is_sharp(char c);

/* CHECK2.C */
void	check_create_tetri(t_env *e, int i, int tetri_save);

/* ADD.C */
void	add_nb_tetri(int *nb_tetri, int x);
void	add_width_and_save(int nb_tetri, int *mapw, int *mapws);
void	add_tetri_coord_zero(int *x, int *y);
void	add_swap_tetri(char **a, char **b);
void	swap_coor_tetri(t_piece *a, t_piece *b);

/* SEARCH.C */
void	first_sharp(t_piece *tetri);

/* CHECK_TETRIMINO.C */
void	check_tetri(t_env *e, int i, int nb_col, int nb_lines);
void 	check_tetriminos(t_env *e);
void	check_tetriminos_sharp(t_env *e);
void	valid_piece(t_env *e);

/* GET_TETRIMINOS.C */
void	get_tetriminos(t_env *e, char *file);

/* RESOLVER.C */
void	resolver(t_env *e);

/* PRINT_MAP.C */
void	print_map(t_env *e);

/* ERROR.C */
void	ft_error(char *str);

#endif
