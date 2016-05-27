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
