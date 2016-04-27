/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:13:06 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/14 18:59:33 by sbeaufil         ###   ########.fr       */
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
