/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:34:26 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/15 01:49:08 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenl;

	lenl = ft_strlen(little);
	if (lenl == 0)
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && ((i + j) < len && big[i + j] != '\0'))
		{
			if (j == lenl - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
