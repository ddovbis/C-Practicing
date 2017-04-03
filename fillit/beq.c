/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:38:43 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/24 20:31:03 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swag.h"

void	verifs(char **map, char **pcs, int *sizpcn)
{
	int i;

	i = 0;
	while (map[i] != '\0')
		i++;
	if (sizpcn[1] == sizpcn[2])
		finish(map, sizpcn);
	else if (sizpcn[1] > 0)
	{
		i = 0;
		while (map[i] != '\0')
			i++;
		sizpcn[1]++;
		beq(map, pcs, sizpcn);
		sizpcn[1]--;
	}
}

void	get_xy(int i, char **pcs, int **coords)
{
	int	tempc;
	int	j;

	tempc = i;
	while (i < tempc + 4)
	{
		j = 0;
		while (j < 4)
		{
			if (pcs[i][j] == '#')
			{
				if (coords[0][0] == -1)
					coords[0][0] = i;
				if (coords[0][1] > j)
					coords[0][1] = j;
				if (coords[1][0] < i)
					coords[1][0] = i;
				if (coords[1][1] < j)
					coords[1][1] = j;
			}
			j++;
		}
		i++;
	}
}

void	get_coords(char **pcs, int *sizpcn, int **coords)
{
	int		i;
	int		tempc;

	coords[0][0] = -1;
	coords[0][1] = 3;
	coords[1][0] = 0;
	coords[1][1] = 0;
	i = 0;
	tempc = 1;
	while (tempc < sizpcn[1])
		if (pcs[i++][0] == '\n')
			tempc++;
	get_xy(i, pcs, coords);
}

int		border(int *sizpcn, int **coords, int *ofsxy)
{
	if (coords[1][1] - coords[0][1] + 1 + ofsxy[1] > sizpcn[0])
		return (0);
	if (coords[1][0] - coords[0][0] + 1 + ofsxy[0] > sizpcn[0])
		return (0);
	return (1);
}

void	beq(char **map, char **pcs, int *sizpcn)
{
	int	*ofsxy;
	int	**coords;

	ofsxy = (int*)malloc(sizeof(int) * 3);
	coords = (int**)malloc(sizeof(int*) * 2);
	coords[0] = (int*)malloc(sizeof(int) * 2);
	coords[1] = (int*)malloc(sizeof(int) * 2);
	ofsxy[0] = 0;
	get_coords(pcs, sizpcn, coords);
	while (ofsxy[0] < sizpcn[0] && sizpcn[1] > 0)
	{
		ofsxy[1] = 0;
		while (ofsxy[1] < sizpcn[0] && sizpcn[1] > 0)
		{
			ofsxy[2] = sizpcn[1];
			if (border(sizpcn, coords, ofsxy))
				if (place(map, pcs, ofsxy, coords))
				{
					verifs(map, pcs, sizpcn);
					rem(map, pcs, ofsxy, coords);
				}
			ofsxy[1]++;
		}
		ofsxy[0]++;
	}
}
