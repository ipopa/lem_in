#include "lem_in.h"

void	reset_vertices(t_vert *vertices)
{
	t_vert *tmp;

	tmp = vertices;
	while (tmp != NULL)
	{
		tmp->visited = false;
		if (!tmp->start)
		{
			*(tmp->wt) = INT_MAX;
		}
		tmp = tmp->next;
	}
}

void	set_path(int **tab, t_map *graph, int maxpath)
{
	int		i;
	int		total;
	int		tmp_total;
	float	tmp;

	graph->maxpath = maxpath;
	i = 0;
	total = graph->ants;
	while (i < graph->nbpath)
	{
		total += tab[i][0];
		i++;
	}
	i = 0;
	tmp_total = 0;
	while (i < graph->nbpath)
	{
		tmp = (float)(total - (graph->nbpath * tab[i][0])) / graph->nbpath;
		tab[i][1] = (int)tmp;
		tmp_total += tab[i][1];
		i++;
	}
	tab[0][1] = graph->ants - tmp_total + tab[0][1];
}

int		test_nbelem(int **tab, int total, t_map *graph)
{
	int		i;
	float	tmp;
	int		tmp_first;
	int		cof;

	i = 1;
	tmp_first = graph->ants - tab[0][0];
	while (i <= total && total > 0)
	{
		tmp_first += tab[i][0];
		i++;
	}
	tmp = (float)tmp_first / (total + 1);
	if ((int)tmp < (int)(tmp + 0.5))
		tmp++;
	tmp_first = (int)tmp;
	if (tmp_first < tab[total][0] - 1)
		return (-1);
	return (1);
}

int		ft_algo(t_map *graph)
{
	int i;

	i = 0;
	graph->maxpath = count_edge(graph->end);
	graph->tabpath = (int **)malloc(sizeof(int *) * graph->maxpath);
	while (ft_dijkstra(graph->vertices, graph->start, 1) != 0\
				&& i < graph->maxpath)
	{
		graph->tabpath[i] = (int *)malloc(sizeof(int) * 2);
		graph->tabpath[i][0] = create_path(graph, graph->end);
		if ((i != 0) && (test_nbelem(graph->tabpath, i, graph) == -1))
		{
			reset_vertices(graph->vertices);
			break ;
		}
		graph->nbpath++;
		reset_vertices(graph->vertices);
		if (graph->tabpath[i++][0] <= 2)
			break ;
	}
	if (i == 0)
		return (-1);
	set_path(graph->tabpath, graph, i);
	print_graph(graph);
	return (1);
}
