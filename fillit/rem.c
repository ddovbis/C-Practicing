/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:32:10 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/27 22:31:16 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swag.h"

void	rem(char **map, char **pcs, int *ofsxy, int **coords)
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
				map[xmap][ymap] = '.';
			ypcs++;
			ymap++;
		}
		xpcs++;
		xmap++;
	}
}
