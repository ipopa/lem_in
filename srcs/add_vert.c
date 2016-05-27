/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:42:05 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/27 11:43:30 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_vert_to_map(t_vert **vert, t_vert *new)
{
	int		i;
	t_vert	*tmpvert;

	i = 0;
	tmpvert = *vert;
	if (*vert == NULL)
	{
		*vert = new;
		return (1);
	}
	while (tmpvert->next)
	{
		if (ft_strequ(tmpvert->name, new->name))
			return (-1);
		tmpvert = tmpvert->next;
		i++;
	}
	if (tmpvert && ft_strequ(tmpvert->name, new->name))
		return (-1);
	tmpvert->next = new;
	return (1);
}

int		add_vert_coord(char **tab, t_vert *new)
{
	char	*tmp;
	int		ret;

	if (tab[1])
	{
		tmp = ft_strtrim(tab[1]);
		ret = ft_strequ(tmp, "0");
		if ((new->x = ft_atoi(tab[1])) == 0 && ret == 0)
			return (0);
		free(tmp);
		if (tab[2])
		{
			tmp = ft_strtrim(tab[2]);
			ret = ft_strequ(tmp, "0");
			if ((new->y = ft_atoi(tab[2])) == 0 && ret == 0)
				return (0);
			free(tmp);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

void	start_or_end(bool start, bool end, t_map *graph, t_vert *new)
{
	if (start)
	{
		new->start = true;
		*(new->wt) = 0;
		graph->start = new;
	}
	if (end)
	{
		graph->end = new;
		new->end = true;
	}
}

int		add_vert(t_map *graph, char *line, bool start, bool end)
{
	t_vert	*new;
	char	**tab;

	new = init_vert();
	if ((tab = ft_strsplit(line, &ft_isspace)) == NULL)
		return (-1);
	if (tab[0])
		new->name = ft_strdup(tab[0]);
	if (add_vert_coord(tab, new) == 0)
		return (0);
	ft_free_tab(tab);
	start_or_end(start, end, graph, new);
	if (add_vert_to_map(&(graph->vertices), new) == -1)
		return (-1);
	return (1);
}
