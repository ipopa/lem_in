/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 13:22:22 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/06/05 13:56:45 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ftoa_acc(double n, char *s, size_t acc, int neg)
{
	int	index;
	int	i;

	if (ft_strlen(s) - ft_nbrlen(ft_ftoi(n)) > acc)
		s[ft_strlen(s) - 1] = '\0';
	if (n > ft_atof(s))
		s[ft_strlen(s) - 1] += 1;
	if (n < ft_atof(s))
		s[ft_strlen(s) - 1] -= 1;
	index = 0;
	while (s[index] && s[index] != '.')
		index++;
	i = 0;
	while (s[i + index])
		i++;
	while (i++ <= (int)acc)
		ft_addchar(&s, '0');
	if (neg)
		ft_addfirstchar(&s, '-');
	return (s);
}

static char		*ft_ftoa_float(double n, char *s, size_t acc, int neg)
{
	int		f;
	int		p;
	char	*str;
	char	*tmp;

	ft_addchar(&s, '.');
	p = ft_ftoi((n - ft_ftoi(n)) * MAX_FTOA);
	if (p == 0)
		return (ft_ftoa_acc(n, s, acc, neg));
	f = ft_nbrlen(p);
	while (f++ < (int)acc)
		ft_addchar(&s, '0');
	str = ft_itoa(p);
	tmp = ft_strjoin(s, str);
	ft_strdel(&s);
	s = ft_strdup(tmp);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (ft_ftoa_acc(n, s, acc, neg));
}

char			*ft_ftoa(double n, size_t acc)
{
	char	*s;
	int		neg;

	neg = (n < 0) ? 1 : 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n < 1 && n > 0)
		return (ft_ftoa_float(n, ft_strdup("0"), acc, neg));
	else if (n > -1 && n < 0)
		return (ft_ftoa_float(n, ft_strdup("0"), acc, neg));
	else if (n <= -1)
		s = ft_itoa(ft_ftoi(n));
	else
		s = ft_itoa(ft_ftoi(n));
	if (s == NULL)
		return (NULL);
	return (ft_ftoa_float(n, s, acc, neg));
}
