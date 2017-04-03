/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:34:26 by ddovbis           #+#    #+#             */
/*   Updated: 2017/02/15 01:41:19 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nr_words(char const *s, char c)
{
	int		nr_words;

	while (*s && *s == c)
		s++;
	if (*s)
		nr_words = 1;
	else
		nr_words = 0;
	while (*s)
	{
		if (s[1] && s[1] != c && *s == c)
			nr_words++;
		s++;
	}
	return (nr_words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nr_words;
	char	**tab;
	char	*start;

	if (!s || !c)
		return (NULL);
	nr_words = ft_nr_words((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (nr_words + 1));
	start = (char *)s;
	if (!tab)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(tab++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		s++;
	}
	if (start != s)
		*(tab++) = ft_strsub(start, 0, s - start);
	*tab = NULL;
	return (tab - nr_words);
}
