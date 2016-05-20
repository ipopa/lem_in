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
typedef struct s_path t_path;
typedef struct s_listpath t_listpath;

# define INT_MAX 0x7FFFFFFF

struct s_map
{
  t_vert *vertices;
  t_vert *start;
  t_vert *end;
  int maxpath;
  int ants;
  int nbpath;
  int **tabpath;
  char **map;
  bool startB;
  bool endB;
  bool error;
  struct s_listpath *listpath;
};

struct s_listpath
{
  int nbelem;
  int maxants;
  struct s_path *path;
  struct s_path *cur;
  struct s_listpath *next;
};

struct s_edge
{

  struct s_vert *connectTo;
  struct s_edge *next;
};

struct s_path
{
  struct s_vert *vertices;
  struct s_path *next;
};

struct s_vert
{
  bool start;
  bool end;
  bool occ;
  int *wt;
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
t_vert	*init_vert(void);
t_edge	*init_edge(t_vert *new);
t_map	*init_map(void);
int error(void);
int check_vert(t_vert *vert, t_vert *new);
void destroy_map(t_map *graph);
int ft_algo(t_map *graph);
t_vert *find_small_vertice(t_vert *vertice);
void print_path(t_path *path);
void reset_vertices(t_vert *vertices);
int create_path(t_map *graph, t_vert *vert);
void set_path(int **tab, t_map *graph);
int test_nbelem(int **tab, int total, t_map *graph);
void print_graph(t_map *graph);
int count_edge(t_vert *vert);
int add_vert_to_map(t_vert **vert, t_vert *new);
int add_edge_to_map(t_edge **edge, t_vert *new);
int add_vert(t_map *graph, char *line, bool start, bool end);
int add_edge(t_map *graph, char *line);
t_vert *find_vert(t_vert *vert, char *name);
int my_isline(char c);

#endif
