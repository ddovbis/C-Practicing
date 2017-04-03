/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:34:26 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/21 19:53:38 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;

	temp = (void*)malloc(n);
	if (temp)
	{
		ft_memcpy(temp, src, n);
		ft_memcpy(dest, temp, n);
		free(temp);
	}
	return (dest);
}
