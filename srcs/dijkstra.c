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

t_vert	*find_small_vertice(t_vert *vertice)
{
	t_vert	*tmp;
	t_vert	*ret;
	int		nb;

	ret = NULL;
	nb = INT_MAX;
	tmp = vertice;
	while (tmp != NULL)
	{
		if (!tmp->visited && *(tmp->wt) < nb && !tmp->occ)
		{
			nb = *(tmp->wt);
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

int		ft_dijkstra(t_vert *vertices, t_vert *start_p, int nb)
{
	t_edge	*edge_p;
	int		tmp_nb;

	if (start_p == NULL)
		return (0);
	start_p->visited = true;
	if (start_p->end)
		return (1);
	edge_p = start_p->edges;
	while (edge_p != NULL)
	{
		if (!edge_p->bounds->occ && !edge_p->bounds->visited\
			&& (*(edge_p->bounds->wt) > (nb + *(start_p->wt))))
		{
			*(edge_p->bounds->wt) = *(start_p->wt) + nb;
			edge_p->bounds->orig = start_p;
		}
		edge_p = edge_p->next;
	}
	if (ft_dijkstra(vertices, find_small_vertice(vertices), nb))
		return (1);
	return (0);
}
