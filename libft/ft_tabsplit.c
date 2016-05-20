/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:00:27 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/05/29 15:26:09 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tabwords(char const *s)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i])
		{
			while (s[i] && !(ft_isspace(s[i])))
				i++;
			size++;
		}
	}
	return (size);
}

char			**ft_tabsplit(char const *s)
{
	char	**tab;
	size_t	size;
	int		i;
	int		start;

	if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_tabwords(s) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			i++;
		else
		{
			start = i;
			while (s[i] && !(ft_isspace(s[i])))
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
	}
	tab[size] = NULL;
	return (tab);
}
