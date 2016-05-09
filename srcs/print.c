#include "lem_in.h"

void print_vertice(t_vert *vert)
{
  if (vert->end)
    printf("- vertice end -\n");
  if (vert->start)
    printf("- vertice start -\n");
  printf("name = %s; wt = %d; x = %d; y = %d\n", vert->name, *(vert->wt), vert->x, vert->y);
  if (vert->occ)
    printf("- vertice occuped -\n");
}

void print_path(t_path *path)
{
  t_path *tmp;

  tmp = path->next;
  while (tmp != NULL)
    {
      ft_putstr(tmp->vertices->name);
      tmp = tmp->next;
    }
}

void print_mypath(int *i, char **ants, t_path *path)
{
  int j;
  t_path *tmp;
  int tmpBool;

  tmpBool = 1;
  j = *i;
  tmp = path->next;
  while(tmpBool != 0)
    {
      if (ants[j])
	{
	  while (tmp != NULL)
	    {
	      if (ft_strequ(tmp->vertices->name, ants[j]))
		{
		  tmp = tmp->next;
		  break ;
		}
	      tmp = tmp->next;
	    }
	}
      else
	{
	  ants[j] = ft_strdup(tmp->vertices->name);
	  tmpBool = 0;
	}
      if (!tmp)
	break ;
      ft_putstr("L");
      ft_putnbr(j + 1);
      ft_putstr("-");
      ft_putstr(tmp->vertices->name);
      ft_putstr(" ");
      tmp = path->next;
      j++;
    }
}

void print_print(int i, char *str)
{
  ft_putstr("L");
  ft_putnbr(i);
  ft_putstr("-");
  ft_putstr(str);
  ft_putstr(" ");
}

int print_ant(int i, char **ants, t_path *path)
{
  int j;
  t_path *tmp;
  int tmpBool;

  tmpBool = 1;
  j = i;
  tmp = path->next;
  if (ants[j])
    {
      while (tmp != NULL)
	{
	  if (ft_strequ(tmp->vertices->name, ants[j]))
	    {
	      tmp = tmp->next;
	      break ;
	    }
	  j++;
	  tmp = tmp->next;
	}
      if (tmp)
	{
	  ants[j] = ft_strdup(tmp->vertices->name);
	  print_print(j + 1, ants[j]);
	}
    }
  else
    {
      ants[j] = ft_strdup(tmp->vertices->name);
      print_print(j + 1, ants[j]);
    }
  if (j > i)
    i++;
  return i;
}

void print_graph(t_map *graph, int **tab)
{
  int i;
  int nb;
  t_listpath *tmpLP;
  char **tabAnts;
  int *nbPath;
  int tmpJ;
  
  i = 1;
  nb = 0;
  tmpLP = graph->listpath;
  tabAnts = (char **)malloc(sizeof(char *) * (graph->ants));
  nbPath = (int *)malloc(sizeof(int) * (graph->nbpath));

  // initialise la position de chaques fourmies dans la salle start
  while(nb < graph->ants)
    {
      tabAnts[nb] = 0;
      nb++;
    }

  nb = 0;  
  while(42)
    {

      // sauvegarde le numero de la fourmie
      //tmpJ = nb;

      // on affecte un chemin a la fourmie nb
      if (!nbPath[nb])
	  nbPath[nb] = i;
      
      nb = print_ant(nb, tabAnts, tmpLP->path);

      // on explore le chemin suivant
      tmpLP = tmpLP->next;

      // on arrete l'affichage lorque toutes les fourmies ont atteint la salle end
      if (nb == graph->ants && i == graph->nbpath - 1)
	break ;
      
      // tous les chemins ont ete explore
      if (!tmpLP)
	{
          i = 0;
	  if (nb == tmpJ)
	    nb = 0;
	  ft_putstr("\n");

	  // on reinitialise le pointeur sur le premier chemin
	  tmpLP = graph->listpath;
	}
      // on passe a la fourmie suivante
      else
	nb++;
      i++;
    }
}
