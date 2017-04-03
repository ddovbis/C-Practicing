#include "includes.h"

int		*null_row(int size)
{
	int *row;
	int i;

	row = (int *)malloc(sizeof(int *) * size + 1);
	i = 0;
	while (i <= size)
		row[i++] = 0;
	return (row);
}

int		**create_map(int size)
{
	int		**map;
	int		i;

	map = (int **)malloc(sizeof(int **) * size + 1);
	i = 0;
	while (i < size)
		map[i++] = null_row(size);
	put_in_map(map, size);
	put_in_map(map, size);
	return (map);
}

void set_colors()
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	attron(COLOR_PAIR(1));
}

void	put_map(int **map, int size)
{
	int		i;
	int		j;
	int		pad;
	int		row;
	int		col;
	// int 	won;

	getmaxyx(stdscr, row, col);
	pad = get_max_lenght(map, size);
	// won = 0;

	// if (check_win(map, size) || won == 1)
	// {
	// 	mvwprintw(stdscr, 1, col / 2, "You have WON!!!");
	// 	won = 1;
	// }
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			set_colors();
			mvwprintw(stdscr, ((row - (1 + pad) * size) / 2 + i *
				(pad + 1)), ((col - (4 + pad) * size) / 2 + j *
				(4 + pad)), "| %-*d |", pad, map[i][j]);
		}
		printw("\n");
	}
}

int		put_in_map(int **map, int size)
{
	int *pos;

	if (is_map_full(map, size))
		return (0);
	pos = find_rand_empty(map, size);
	*pos = rand_number();
	return (1);
}
