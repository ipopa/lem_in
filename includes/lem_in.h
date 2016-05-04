#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <stdbool.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_map t_map;
typedef struct s_vert t_vert;
typedef struct s_env t_env;
typedef struct s_edge t_edge;

# define INT_MAX 0x7FFFFFFF

struct s_map
{
  t_vert *vertices;
  int ants;
  char **edges;
};

struct s_edge
{

  struct s_vert *connectTo;
  struct s_edge *next;
};

struct s_vert
{
  bool start;
  bool end;
  bool occ;
  int wt;
  char *name;
  struct s_edge *edges;
  struct s_vert *orig;
  struct s_vert *next;
  int x;
  int y;
  bool visited;
};

struct s_env
{

  bool start;
  bool end;
  bool err;
};



int parse_map(t_map *graph);
int init_vert(t_vert *vert);
void print_vertice(t_vert *vert);
int error(char *err);
int check_vert(t_vert *vert, t_vert *new);
size_t	ft_words(char const *s, char c);
void destroy_map(t_map *graph);
int isRe(char *dest, t_vert *startP);

#endif
