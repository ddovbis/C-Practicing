/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:52:39 by ddovbis           #+#    #+#             */
/*   Updated: 2017/04/03 14:52:56 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include "libft/libft.h"
# include <unistd.h>

typedef struct	s_get_next_line
{
	int		fd;
	char	*buff;
	int		size;
	int		i;
	int		new_ln;
}				t_data;

int				get_next_line(int const fd, char **line);
#endif
