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

char			**ft_strsplit(char const *s, int (*f)(char))
{
	char	**tab;
	size_t	size;
	int		i;
	int		start;

	if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_words(s, f) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if ((*f)(s[i]))
			i++;
		else
		{
			start = i;
			while (s[i] && !(*f)(s[i]))
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
	}
	tab[size] = NULL;
	return (tab);
}
