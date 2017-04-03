/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   att_pcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:35:55 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/27 22:15:52 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swag.h"

char	**pcs_init(char *buf, int len)
{
	int		totalline;
	int		line;
	char	**pcs;

	totalline = nr_retur_line(buf);
	if (len)
		;
	pcs = (char**)malloc(sizeof(char*) * totalline + 1);
	line = 0;
	while (line < totalline)
	{
		pcs[line] = (char*)malloc(sizeof(char) * 6);
		line++;
	}
	return (pcs);
}

void	pcs_make(char **pcs, char *buf)
{
	int line;
	int i;
	int j;
	int ind;

	j = 0;
	line = 0;
	while (buf[j] != '\0')
	{
		ind = 0;
		while (ind <= 3)
		{
			i = 0;
			while (i <= 4)
				pcs[line][i++] = buf[j++];
			pcs[line][i + 1] = '\0';
			line++;
			ind++;
		}
		pcs[line][0] = buf[j++];
		pcs[line][1] = '\0';
		line++;
	}
}

char	**att_pcs(char *buf, int len)
{
	char **pcs;

	pcs = pcs_init(buf, len);
	pcs_make(pcs, buf);
	return (pcs);
}
