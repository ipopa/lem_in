#include "lem_in.h"

int add_to_listpath(t_map *graph, t_path *newpath, int nbelem)
{
  t_listpath *path;
  t_listpath *tmp;

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
	{
	  tmp = tmp->next;
	}
      tmp->next = newpath;
    }
}

int create_path(t_map *graph, t_vert *vert)
{
  int nbelem;
  t_path *newnode;
  t_path *newnode2;
  
  newnode = (t_path *)malloc(sizeof(t_path));
  newnode->vertices = NULL;
  newnode->next = NULL;
  
  nbelem = 1;
  while (!vert->start)
    {
      if (newnode->vertices == NULL)
	newnode->vertices = vert;
      else
	{
	  newnode2 = (t_path *)malloc(sizeof(t_path));	
	  newnode2->vertices = vert;
	  newnode2->next = newnode;
	  newnode = newnode2;
	}
      if (!vert->end)
	  vert->occ = true;
      nbelem++;
      vert = vert->orig;
    }
  if (newnode->vertices == NULL)
    newnode->vertices = vert;
  else
    {
      newnode2 = (t_path *)malloc(sizeof(t_path));	
      newnode2->vertices = vert;
      newnode2->next = newnode;
      newnode = newnode2;
    }
  //  print_path(newnode);
  add_to_listpath(graph, newnode, nbelem);
  return nbelem;
}
