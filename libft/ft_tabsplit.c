/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:42:05 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/27 11:42:06 by ipopa            ###   ########.fr       */
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
