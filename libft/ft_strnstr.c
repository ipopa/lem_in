/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:10:37 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/13 14:38:34 by sbeaufil         ###   ########.fr       */
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
