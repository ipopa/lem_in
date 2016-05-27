#include "lem_in.h"

t_path	*set_p(t_map *graph, int nbpath)
{
	t_listpath *tmp;

	tmp = graph->listpath;
	while (nbpath--)
		tmp = tmp->next;
	return (tmp->path);
}

void	next(t_path **tab, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		if (tab[i])
			tab[i] = tab[i]->next;
		i++;
	}
}

void	nb_path(int *nbpath, t_map *graph, t_path **tab, int ants)
{
	if (graph->tabpath[0][0] == 2)
	{
		if (ants == (graph->ants - 1))
		{
			next(tab, graph->ants);
			print_tab(tab, graph->ants);
			ft_putchar('\n');
		}
	}
	else
	{
		*nbpath = *nbpath + 1;
		if (*nbpath > graph->nbpath)
		{
			next(tab, graph->ants);
			print_tab(tab, graph->ants);
			ft_putchar('\n');
			*nbpath = 1;
		}
	}
}

void	print_graph2(t_map *graph, t_path **tab, int ants, int nbpath)
{
	while (42)
	{
		if (!tab[ants])
		{
			if (graph->tabpath[nbpath - 1][1])
			{
				tab[ants] = set_p(graph, nbpath - 1);
				graph->tabpath[nbpath - 1][1]--;
			}
			else
			{
				nb_path(&nbpath, graph, tab, ants);
				continue ;
			}
		}
		nb_path(&nbpath, graph, tab, ants);
		if (ants < (graph->ants - 1))
			ants++;
		if (ants == (graph->ants - 1) && tab[ants] &&\
			(tab[ants])->vertices->end)
			break ;
	}
}

void	print_graph(t_map *graph)
{
	t_path	**tab;
	int		ants;

	tab = (t_path **)malloc(sizeof(t_path *) * (graph->ants + 1));
	ants = 0;
	while (ants < graph->ants)
		tab[ants++] = NULL;
	ants = -1;
	while (graph->map[++ants])
		ft_putendl(graph->map[ants]);
	ft_putchar('\n');
	print_graph2(graph, tab, 0, 1);
	free(tab);
}
