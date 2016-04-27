/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:49:03 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/19 14:33:57 by sbeaufil         ###   ########.fr       */
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
	join = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char*));
	if (join == NULL)
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
