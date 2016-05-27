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

int			ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] > 64 && s1[i] < 91)
		{
			if (s1[i] != s2[i] && (s1[i] + 32) != s2[i])
				break ;
		}
		else if (s1[i] > 96 && s1[i] < 123)
		{
			if (s1[i] != s2[i] && (s1[i] - 32) != s2[i])
				break ;
		}
		else
		{
			if (s1[i] != s2[i])
				break ;
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
