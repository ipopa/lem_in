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

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s2);
	if (len == 0)
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0' && (len + i - 1) < n)
	{
		if (s1[i] == *s2)
		{
			if (ft_strncmp(&s1[i], s2, len) == 0)
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
