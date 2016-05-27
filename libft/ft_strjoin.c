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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(join = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) *\
			sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		join[i] = s2[y];
		i++;
		y++;
	}
	join[i] = '\0';
	return (join);
}
