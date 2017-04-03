/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:34:26 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/15 00:29:57 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	long	len;
	long	nbr;

	len = 1;
	nbr = n;
	if (nbr == 0)
		ft_putchar('0');
	else
	{
		if (nbr < 0)
		{
			nbr = nbr * -1;
			ft_putchar('-');
		}
		while (nbr / len >= 10)
			len = len * 10;
		while (len > 0)
		{
			ft_putchar(nbr / len + '0');
			nbr = nbr % len;
			len = len / 10;
		}
	}
}
