#include "lem_in.h"

int		add_to_listpath(t_map *graph, t_path *newpath, int nbelem)
{
	t_listpath	*path;
	t_listpath	*tmp;

	path = (t_listpath *)malloc(sizeof(t_listpath));
	path->path = newpath;
	path->next = NULL;
	path->maxants = 0;
	path->nbelem = nbelem;
	tmp = graph->listpath;
	if (graph->listpath == NULL)
		graph->listpath = path;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = path;
	}
	return (1);
}

t_path	*add_newnode(t_path *path, t_vert *vert)
{
	t_path	*newnode;

	newnode = (t_path *)malloc(sizeof(t_path));	
	newnode->vertices = vert;
	newnode->next = path;
	return (newnode);
}

int		create_path(t_map *graph, t_vert *vert)
{
	int		nbelem;
	t_path	*newnode;

	newnode = (t_path *)malloc(sizeof(t_path));
	newnode->vertices = NULL;
	newnode->next = NULL;
	nbelem = 1;
	while (!vert->start)
	{
		if (newnode->vertices == NULL)
			newnode->vertices = vert;
		else
			newnode = add_newnode(newnode, vert);
		if (!vert->end)
			vert->occ = true;
		nbelem++;
		vert = vert->orig;
	}
	if (newnode->vertices == NULL)
		newnode->vertices = vert;
	else
		newnode = add_newnode(newnode, vert);
	add_to_listpath(graph, newnode, nbelem);
	return (nbelem);
}
