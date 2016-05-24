#include "lem_in.h"

int		count_edge(t_vert *vert)
{
	int		i;
	t_edge	*tmp;

	i = 0;
	tmp = vert->edges;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_vert	*find_vert(t_vert *vert, char *name)
{
	t_vert *tmp;

	tmp = vert;
	while (tmp != NULL)
	{
		if (ft_strequ(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	free_vertices(t_vert *vertices)
{
	t_vert *tmp_v;
	t_edge *tmp_e;

	while (vertices)
	{
		while (vertices->edges)
		{
			tmp_e = vertices->edges;
			vertices->edges = vertices->edges->next;
			free(tmp_e);
		}
		free(vertices->name);
		free(vertices->wt);
		tmp_v = vertices;
		vertices = vertices->next;
		free(tmp_v);
	}
}

void	free_tabpath(t_map *graph)
{
	int i;

	if (graph->tabpath)
	{
		i = 0;
		while (i < graph->maxpath)
		{
			free(graph->tabpath[i]);
			i++;
		}
		free(graph->tabpath);
	}
}

void	destroy_map(t_map *graph)
{
	int			i;
	t_listpath	*tmp_l;
	t_path		*tmp_p;

	free_vertices(graph->vertices);
	while (graph->listpath)
	{
		while (graph->listpath->path)
		{
			tmp_p = graph->listpath->path;
			graph->listpath->path = graph->listpath->path->next;
			free(tmp_p);
		}
		tmp_l = graph->listpath;
		graph->listpath = graph->listpath->next;
		free(tmp_l);
	}
	ft_free_tab(graph->map);
	free(graph);
}
