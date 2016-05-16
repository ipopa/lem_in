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
#include <stdio.h>
int	ft_atoi(const char *str)
{
  int	result;
  int sign;

  result = 0;
  while (((*str > 8 && *str < 14) || *str == ' ') && *str)
    str++;
  sign = (*str == '-') ? -1 : 1;
  if (*str == '-' || *str == '+')
    str++;
  if ((ft_strcmp(str, INT_MAX_STR) > 0 && ft_strlen(str) == 10) || ft_strlen(str) > 10)
    return 0;
  while (*str && ft_isdigit(*str) == 1)
    {
      result = (result * 10) + (*str - '0');
      str++;
    }
  if (*str)
    return 0;
  return sign * result;
}
