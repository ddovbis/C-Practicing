/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:31:17 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/27 22:20:40 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swag.h"

int		check_connect(char **pcs, int x, int y)
{
	int connect;

	connect = 0;
	if (y - 1 >= 0)
		if (pcs[x][y - 1] == '#')
			connect++;
	if (x - 1 >= 0)
		if (pcs[x - 1][y] == '#')
			connect++;
	if (pcs[x + 1][y] == '#')
		connect++;
	if (pcs[x][y + 1] == '#')
		connect++;
	if (connect == 0)
		error();
	return (connect);
}

int		*check_one_pcs(char **pcs, int x, int connect)
{
	int ind;
	int y;
	int tab[2];
	int *res;

	ind = 0;
	while (ind < 4)
	{
		y = 0;
		while (pcs[x][y] != '\0')
		{
			if (pcs[x][y] == '#')
				connect = check_connect(pcs, x, y) + connect;
			y++;
		}
		x++;
		ind++;
	}
	tab[0] = connect;
	tab[1] = x;
	res = tab;
	return (res);
}

void	check_pcs(char **pcs)
{
	int connect;
	int x;
	int *temp;

	x = 0;
	while (pcs[x] != '\0')
	{
		connect = 0;
		temp = check_one_pcs(pcs, x, connect);
		connect = temp[0];
		x = temp[1];
		if (connect < 6)
			error();
		x++;
	}
}
