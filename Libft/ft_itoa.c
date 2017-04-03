/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 04:18:00 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/21 19:49:42 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_strrev(char *c)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = ft_strlen(c) - 1;
	while (i < j)
	{
		aux = c[i];
		c[i] = c[j];
		c[j] = aux;
		i++;
		j--;
	}
	return (c);
}

static int		ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = nbr * -1;
	return (nbr);
}

static size_t	get_nsize(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		i;
	char	sign;
	char	*new;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	new = ft_strnew(get_nsize(n));
	if (!new)
		return (NULL);
	if (n == 0)
		new[0] = '0';
	while (n != 0)
	{
		new[i] = ft_abs(n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (sign)
		new[i] = '-';
	new = ft_strrev(new);
	return (new);
}
