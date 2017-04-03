/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:40:56 by ddovbis           #+#    #+#             */
/*   Updated: 2017/04/03 18:40:58 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd,sz;
	char *line;
	if (argc < 2)
	{
		ft_putendl("usage: insert_file_name.");
		return (0);
	}
	else if (argc > 2)
	{
		ft_putendl("too many parameters.");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((sz = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n",line);
		free(line);
	}
	return (0);
}
