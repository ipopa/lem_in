#include "lem_in.h"

int create_path(t_map *graph, t_vert *vert)
{
  int nbelem;
  t_listpath *newpath;
  t_path *newnode;
  t_listpath *tmp;

  nbelem = 1;
  newpath = (t_listpath *)malloc(sizeof(t_listpath));
  newpath->path = NULL;
  newpath->next = NULL;
  newpath->maxants = 0;

  newnode = (t_path *)malloc(sizeof(t_path));
  while (!vert->start)
    {

      newnode->vertices = vert;
      newnode->next = newpath->path;
      newpath->path = newnode;
      if (!vert->end)
	{
	  vert->occ = true;
	}
      nbelem++;
      vert = vert->orig;
    }
  newnode->vertices = vert;
  newnode->next = newpath->path;
  newpath->path = newnode;

  print_path(newpath->path);
  
  newpath->nbelem = nbelem;

  tmp = graph->listpath;
  if (graph->listpath == NULL)
    graph->listpath = newpath;
  else
    {
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}
      tmp->next = newpath;
    }
  return nbelem;
}
