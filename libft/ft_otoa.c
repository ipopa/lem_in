/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:00:06 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/06/02 15:29:46 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_otoa(unsigned long long int c)
{
	char	octa[30];
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (c > 7)
	{
		octa[i++] = (char)((c % 8) + '0');
		c = c / 8;
	}
	octa[i++] = (char)(c + '0');
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
		ret[j++] = octa[i];
	ret[j] = '\0';
	return (ret);
}
