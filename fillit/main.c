/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:31:46 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/27 22:34:02 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swag.h"

char		*make_buf(char *argc)
{
	int		fd;
	char	*buf;
	int		len;

	fd = open(argc, O_RDONLY);
	if (fd == -1)
		error();
	buf = (char*)malloc(700);
	len = read(fd, buf, 700);
	buf[len + 1] = '\0';
	(void)close(fd);
	return (buf);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void		call_beq(char **pcs, int nrpcs)
{
	int		i;
	int		*sizpcn;
	char	**map;

	i = min_square(nrpcs);
	sizpcn = (int*)malloc(sizeof(int) * 4);
	sizpcn[2] = nrpcs;
	sizpcn[1] = 1;
	while (sizpcn[1] > 0)
	{
		sizpcn[1] = 1;
		map = get_map(i);
		sizpcn[0] = i;
		beq(map, pcs, sizpcn);
		i++;
		free(map);
	}
}

int			main(int argv, char **argc)
{
	int		nrpcs;
	char	*buf;
	char	**pcs;

	if (argv != 2)
		error();
	buf = make_buf(argc[1]);
	nrpcs = 0;
	nrpcs = nr_retur_line(buf) / 5;
	if (nrpcs < 1 || nrpcs > 26)
		error();
	check_buf(buf);
	pcs = att_pcs(buf, ft_strlen(buf));
	free(buf);
	check_pcs(pcs);
	call_beq(pcs, nrpcs);
	return (0);
}
