#include "includes.h"

int		rand_number(void)
{
	int	num;

	srand(time(NULL));
	num = rand();
	if (num % 2 == 0)
		return (2);
	else
		return (4);
}

int		*find_rand_empty(int **map, int size)
{
	int i;
	int j;

	srand(time(NULL));
	i = rand() % (size);
	j = rand() % (size);
	while (map[i][j] != 0)
	{
		i = rand() % (size);
		j = rand() % (size);
	}
	return (&map[i][j]);
}

int		is_map_full(int **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		get_max_lenght(int **map, int size)
{
	int i;
	int	j;
	int max;
	int len;

	max = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] > max)
				max = map[i][j];
			j++;
		}
		i++;
	}
	len = 0;
	while (max != 0)
	{
		len++;
		max /= 10;
	}
	return (len);
}
