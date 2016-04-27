/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:48:48 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/12 16:53:55 by sbeaufil         ###   ########.fr       */
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
