/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:31:36 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/27 22:25:24 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swag.h"

char		**get_map_init(int i)
{
	int		j;
	char	**map;

	map = (char**)malloc(sizeof(char*) * (i + 2));
	j = 0;
	while (j < i)
	{
		map[j] = (char*)malloc(sizeof(char) * (i + 2));
		j++;
	}
	return (map);
}

char		**get_map(int i)
{
	int		j;
	int		k;
	char	**map;

	map = get_map_init(i);
	j = 0;
	while (j < i)
	{
		k = 0;
		while (k < i)
		{
			map[j][k] = '.';
			k++;
		}
		map[j][k] = '\n';
		map[j][k + 1] = '\0';
		j++;
	}
	return (map);
}
