/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:32:15 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/27 22:32:21 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAG_H
# define SWAG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	finish(char **map, int *sizpcn);
void	rem(char **map, char **pcs, int *ofsxy, int **coords);
int		place(char **map, char **pcs, int *ofsxy, int **coords);
void	beq(char **map, char **pcs, int *sizpcn);
void	error(void);
int		nr_retur_line(char *s);
void	check_pcs(char **pcs);
char	**att_pcs(char *buf, int len);
int		min_square(int nrpcs);
char	**get_map(int i);
void	check_buf(char *buf);

#endif
