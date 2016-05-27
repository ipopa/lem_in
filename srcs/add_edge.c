#include "lem_in.h"

static int		add_edge_to_map(t_edge **edge, t_vert *new)
{
	int			i;
	t_edge		*tmpedge;
	t_edge		*newedge;

	i = 0;
	tmpedge = *edge;
	newedge = init_edge(new);
	if (*edge == NULL)
	{
		*edge = newedge;
		return (1);
	}
	while (tmpedge->next)
	{
		if (ft_strequ(tmpedge->bounds->name, new->name))
			return (-1);
		tmpedge = tmpedge->next;
		i++;
	}
	if (tmpedge && tmpedge->bounds && ft_strequ(tmpedge->bounds->name, new->name))
		return (-1);
	tmpedge->next = newedge;
	return (1);
}

int				my_isline(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int				add_edge(t_map *graph, char *line)
{
	char		**tab;
	t_vert		*v1;
	t_vert		*v2;

	tab = ft_strsplit(line, &my_isline);
	v1 = find_vert(graph->vertices, tab[0]);
	v2 = find_vert(graph->vertices, tab[1]);
	ft_free_tab(tab);
	if (!v1 || !v2)
		return (-1);
	if (add_edge_to_map(&(v1->edges), v2) == -1)
		return (-1);
	if (add_edge_to_map(&(v2->edges), v1) == -1)
		return (-1);
	return (1);
}
