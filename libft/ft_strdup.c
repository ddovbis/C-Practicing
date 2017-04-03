/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:34:26 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/21 17:10:14 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = 0;
	while (s[len] != '\0')
		len++;
	dup = (char*)malloc(sizeof(*dup) * (len + 1));
	if (!dup)
		return (0);
	ft_strcpy(dup, s);
	if (dup)
		return (dup);
	else
		return (0);
}
