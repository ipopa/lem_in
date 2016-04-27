/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:13:30 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/12 17:10:07 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count1;
	int		count2;
	char	*dest;

	dest = 0;
	if (s1 != '\0')
	{
		count1 = 0;
		while (s1[count1] != '\0')
			count1++;
		dest = malloc ((count1 + 1) * sizeof(*dest));
		if (dest != '\0')
		{
			count2 = -1;
			while (s1[++count2] != 0)
				dest[count2] = s1[count2];
			dest[count2] = 0;
			return (dest);
		}
	}
	return (dest);
}
