#include "includes.h"

int		read_key(void)
{
	int key;

	key = getch();
	if (key == KEY_UP)
		return (1);
	if (key == KEY_DOWN)
		return (2);
	if (key == KEY_LEFT)
		return (3);
	if (key == KEY_RIGHT)
		return (4);
	if (key == 27)
		return (0);
	return (-1);
}

// int		check_win(int **map, int size)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (map[i][j] == WIN_VALUE)
// 			{
// 				return (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int		handle_keypress(int **map, int size)
{
	int change;
	int key;

	change = 0;
	key = read_key();
	if (key == 0)
		return (0);
	if (key == 1)
		change = move_up(map, size);
	if (key == 2)
		change = move_down(map, size);
	if (key == 3)
		change = move_left(map, size);
	if (key == 4)
		change = move_right(map, size);
	if (key != -1 && change)
		put_in_map(map, size);
	return (1);
}

void	start_game(int **map, int size)
{
	int ok;

	ok = 1;
	while (ok == 1 && !is_game_ended(map, size))
	{
		clear();
		put_map(map, size);
		refresh();
		ok = handle_keypress(map, size);
	}
	clear();
	put_map(map, size);
	// printw("GAME OVER");
	refresh();
	getch();
}
