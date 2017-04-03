#ifndef INCLUDES_H
# define INCLUDES_H
# include <ncurses.h>
# include <stdlib.h>
# include <time.h>
# include <stdlib.h>
# include <signal.h>

// enum	e_const
// {
// 	WIN_VALUE = 4
// };

int		**create_map(int n);
void	put_map(int **map, int n);
int		rand_number();
int		*find_rand_empty(int **map, int size);
int		is_map_full(int **map, int size);
int		put_in_map(int **map, int size);
int		read_key();
void	start_game(int **map, int size);
void	slide_row(int *row, int size, int *change);
void	rotate_map(int **map, int size);
int		move_left(int **map, int size);
int		move_up(int **map, int size);
int		move_right(int **map, int size);
int		move_down(int **map, int size);
int		is_game_ended(int **map, int size);
int		get_max_lenght(int **map, int size);
int		find_pair(int **map, int size);
// int		check_win(int **map, int size);
int		ft_atoi(const char *str);

#endif
