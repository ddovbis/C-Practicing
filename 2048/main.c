#include "includes.h"

int	main(int argc, char **argv)
{
	int **map;
	int size;

	size = 4;
	if (argc == 2)
		size = ft_atoi(argv[1]);
	if (size == 0)
		size = 4;
	init_pair(1, COLOR_RED, COLOR_BLACK);
	map = create_map(size);
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	put_map(map, size);
	start_game(map, size);
	endwin();
}
