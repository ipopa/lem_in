/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:04:43 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/14 17:35:17 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	cp;
	unsigned char	*pos;

	pos = (unsigned char*)s;
	cp = 0;
	while (n-- > 0)
	{
		if (pos[cp] == (unsigned char)c)
			return (&(pos[cp]));
		cp++;
	}
	return (NULL);
}
