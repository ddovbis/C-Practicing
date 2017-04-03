/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:34:26 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/15 00:24:33 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	len;
	long	nbr;

	len = 1;
	nbr = n;
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (nbr < 0)
		{
			nbr = nbr * -1;
			ft_putchar_fd('-', fd);
		}
		while (nbr / len >= 10)
			len = len * 10;
		while (len > 0)
		{
			ft_putchar_fd(nbr / len + '0', fd);
			nbr = nbr % len;
			len = len / 10;
		}
	}
}
