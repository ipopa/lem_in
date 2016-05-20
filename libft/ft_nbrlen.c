/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 13:17:53 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/06/04 13:17:56 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlen(int nbr)
{
	int		ret;

	ret = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		ret = 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		ret++;
	}
	return (ret);
}
