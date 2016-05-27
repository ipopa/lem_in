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

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;

	if (s2 == NULL || *s2 == '\0')
		return ((char*)s1);
	if (s1 == NULL || *s1 == '\0')
		return (NULL);
	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (ft_strstr(&s1[1], s2));
		else
			i++;
	}
	return ((char*)s1);
}
