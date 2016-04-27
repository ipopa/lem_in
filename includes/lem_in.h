#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include "get_next_line.h"

typedef struct s_map t_map;
typedef struct s_vert t_vert;

struct s_map
{
  t_vert *vertices;
  int ants;
};

<<<<<<< HEAD
struct s_vert
{
  struct s_vert *edges;
  int wt;
  struct s_vert *orig;
  int x;
  int y;
  bool start;
  bool end;
  bool occ;
}

int	get_next_line(int const fd, char **line);

=======
>>>>>>> d01cfc53d42f1f75e0ea2c66e0901d026e3ef0e1
#endif
