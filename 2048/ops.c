#include "includes.h"

int		find_target(int *row, int i, int stop)
{
	int t;

	if (i == 0)
		return (0);
	t = i - 1;
	while (t >= 0)
	{
		if (row[t] != 0)
		{
			if (row[t] != row[i])
				return (t + 1);
			return (t);
		}
		else
		{
			if (t == stop)
				return (t);
		}
		t--;
	}
	return (t);
}

void	slide_row(int *row, int size, int *change)
{
	int	i;
	int t;
	int	stop;

	stop = 0;
	i = -1;
	while (i++ < size)
	{
		if (row[i] != 0)
		{
			t = find_target(row, i, stop);
			if (t != i)
			{
				if (row[t] == 0)
					row[t] = row[i];
				else if (row[i] == row[t])
				{
					row[t] += row[i];
					stop = t + 1;
				}
				row[i] = 0;
				*change = 1;
			}
		}
	}
}

void	rotate_map(int **map, int size)
{
	int i;
	int j;
	int aux;

	i = 0;
	while (i < size / 2)
	{
		j = i;
		while (j < size - i - 1)
		{
			aux = map[i][j];
			map[i][j] = map[j][size - i - 1];
			map[j][size - i - 1] = map[size - i - 1][size - j - 1];
			map[size - i - 1][size - j - 1] = map[size - j - 1][i];
			map[size - j - 1][i] = aux;
			j++;
		}
		i++;
	}
}

int		find_pair(int **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (map[i][j] == map[i][j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_game_ended(int **map, int size)
{
	if (!is_map_full(map, size))
		return (0);
	if (find_pair(map, size))
		return (0);
	rotate_map(map, size);
	if (find_pair(map, size))
		return (0);
	rotate_map(map, size);
	rotate_map(map, size);
	rotate_map(map, size);
	return (1);
}
