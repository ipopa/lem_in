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

static float	atoi_float(char *str, float ret, int signe)
{
	float	index;
	float	tmp;

	index = 10;
	if (*str == '.' || *str == ',')
		str++;
	while ((*str >= '0' && *str <= '9'))
	{
		tmp = (*str++ - '0');
		tmp /= index;
		ret += tmp;
		index *= 10;
	}
	return (ret * signe);
}

float			ft_atof(const char *str)
{
	float	ret;
	int		signe;

	ret = 0;
	if (!str)
		return (ret);
	signe = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'\
			|| *str == '\r' || *str == '\v' || *str == '0')
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0' && *str <= '9'))
		ret = ret * 10 + (*str++ - '0');
	if (*str == '.' || *str == ',')
		return (atoi_float((char*)str, ret, signe));
	return (ret * signe);
}
