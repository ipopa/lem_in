#include "lem_in.h"





void create_path(t_map *graph, t_vert *vert)
{
  int nbelem;
  t_path *newnode;
  t_listpath *newpath;
  
  nbelem = 1;
  newpath = (t_listpath *)malloc(sizeof(t_listpath));
  newnode = (t_path *)malloc(sizeof(t_path));
  graph->path = NULL;
  
  while (!vert->start)
    {
	new = (t_path *)malloc(sizeof(t_path));
	new->vertices = vert;
	new->next = graph->path;
	new->nbelem = nbelem;
	graph->path = new;
	if (!vert->end)
	  {
	    vert->occ = true;
	  }
      nbelem++;
      vert = vert->orig;
    }
  new = (t_path *)malloc(sizeof(t_path));
  new->vertices = vert;
  new->next = graph->path;
  graph->path = new;
  graph->listpath->nbelem = nbelem;
}
