/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:31:10 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/27 22:19:17 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swag.h"

int		check_slash(char *buf, int j)
{
	if (buf[j] == '\n')
		j++;
	else
		error();
	return (j);
}

int		*check_hashtags_and_points(char *buf, int j, int h)
{
	int tab[2];
	int *res;

	if (buf[j] == '#' || buf[j] == '.')
	{
		if (buf[j] == '#')
			h++;
		j++;
	}
	else
		error();
	tab[0] = j;
	tab[1] = h;
	res = tab;
	return (res);
}

int		check_one_piece_of_buf(char *buf, int j)
{
	int	ind;
	int h;
	int i;
	int *tab;

	ind = 0;
	h = 0;
	while (ind <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			tab = check_hashtags_and_points(buf, j, h);
			j = tab[0];
			h = tab[1];
			i++;
		}
		j = check_slash(buf, j);
		ind++;
	}
	if (h != 4)
		error();
	return (j);
}

void	check_buf(char *buf)
{
	int j;

	j = 0;
	while (buf[j] != '\0')
	{
		j = check_one_piece_of_buf(buf, j);
		if (buf[j] == '\n' && buf[j + 1] != '\0')
			j++;
		else if (buf[j] != '\0')
			error();
	}
}
