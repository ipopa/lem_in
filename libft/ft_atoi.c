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

int		ft_atoi(const char *str)
{
	int				result;
	int				sign;
	unsigned int	i;
	char			*tmpstr;

	result = 0;
	tmpstr = ft_strtrim(str);
	i = 0;
	sign = (tmpstr[i] == '-') ? -1 : 1;
	if (tmpstr[i] == '-' || tmpstr[i] == '+')
		i++;
	if ((ft_strcmp(tmpstr, INT_MAX_STR) > 0 && ft_strlen(tmpstr) == (10 + i))\
				|| ft_strlen(tmpstr) > (10 + i))
		sign = 0;
	while ((ft_isdigit(tmpstr[i]) == 1) && tmpstr[i])
	{
		result = (result * 10) + (tmpstr[i] - '0');
		i++;
	}
	if (tmpstr[i])
		sign = 0;
	free(tmpstr);
	return (sign * result);
}
