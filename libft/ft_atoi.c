/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:52:18 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/14 17:46:22 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int signe;
	int i;

	i = 0;
	result = 0;
	while (((str[i] > 8 && str[i] < 14) || str[i] == ' ') && str[i] != '\0')
		i++;
	signe = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result = signe * result;
	return (result);
}
