/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:32:05 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/27 22:30:48 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swag.h"

int		defplace(char **map, char **pcs, int *ofsxy, int **coords)
{
	int	xmap;
	int	ymap;
	int	xpcs;
	int	ypcs;

	xmap = ofsxy[0];
	xpcs = coords[0][0];
	while (xpcs <= coords[1][0])
	{
		ypcs = coords[0][1];
		ymap = ofsxy[1];
		while (ypcs <= coords[1][1])
		{
			if (pcs[xpcs][ypcs] == '#')
				map[xmap][ymap] = 'A' + ofsxy[2] - 1;
			ypcs++;
			ymap++;
		}
		xpcs++;
		xmap++;
	}
	return (1);
}

int		place(char **map, char **pcs, int *ofsxy, int **coords)
{
	int	xmap;
	int	ymap;
	int	xpcs;
	int	ypcs;

	xmap = ofsxy[0];
	xpcs = coords[0][0];
	while (xpcs <= coords[1][0])
	{
		ypcs = coords[0][1];
		ymap = ofsxy[1];
		while (ypcs <= coords[1][1])
		{
			if (map[xmap][ymap] != '.' && pcs[xpcs][ypcs] == '#')
				return (0);
			ypcs++;
			ymap++;
		}
		xpcs++;
		xmap++;
	}
	return (defplace(map, pcs, ofsxy, coords));
}
