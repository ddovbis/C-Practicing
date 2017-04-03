/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:34:26 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/21 18:10:58 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_start(char const *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	get_end(char const *s)
{
	int	len;

	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	len = ft_strlen(s) - 1;
	i = get_start(s);
	start = i;
	len = get_end(s);
	if (len < 0)
		new = (char *)malloc(sizeof(char) + 1);
	else
		new = (char *)malloc(sizeof(char) * (len - start) + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && start <= len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
