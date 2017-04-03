#include "includes.h"

int	move_left(int **map, int size)
{
	int i;
	int change;

	change = 0;
	i = 0;
	while (i < size)
		slide_row(map[i++], size, &change);
	return (change);
}

int	move_up(int **map, int size)
{
	int change;

	rotate_map(map, size);
	change = move_left(map, size);
	rotate_map(map, size);
	rotate_map(map, size);
	rotate_map(map, size);
	return (change);
}

int	move_right(int **map, int size)
{
	int change;

	rotate_map(map, size);
	rotate_map(map, size);
	change = move_left(map, size);
	rotate_map(map, size);
	rotate_map(map, size);
	return (change);
}

int	move_down(int **map, int size)
{
	int change;

	rotate_map(map, size);
	rotate_map(map, size);
	rotate_map(map, size);
	change = move_left(map, size);
	rotate_map(map, size);
	return (change);
}
