#include "lem_in.h"





void create_path(t_map *graph, t_vert *vert)
{
  int nbelem;
  t_listpath *newpath;
  t_path *newnode;

  nbelem = 1;
  newpath = (t_listpath *)malloc(sizeof(t_listpath));
  newpath->path = NULL;
  newpath->next = NULL;

  while (!vert->start)
    {
	newnode = (t_path *)malloc(sizeof(t_path));
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
  newnode = (t_path *)malloc(sizeof(t_path));
  newnode->vertices = vert;
  newnode->next = newpath->path;
  newpath->path = newnode;

  newpath->nbelem = nbelem;
  if (graph->listpath = NULL)
    graph->listpath = newpath;
}
