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

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1cpy;
	unsigned char *s2cpy;

	s1cpy = (unsigned char*)s1;
	s2cpy = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (*s1cpy++ != *s2cpy++)
			return (*--s1cpy - *--s2cpy);
	}
	return (0);
}
