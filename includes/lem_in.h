/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:58:29 by sbeaufil          #+#    #+#             */
/*   Updated: 2016/05/24 15:58:23 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <stdbool.h>
# include <string.h>
# include "../libft/libft.h"

# define INT_MAX 0x7FFFFFFF

typedef struct s_map		t_map;
typedef struct s_vert		t_vert;
typedef struct s_env		t_env;
typedef struct s_edge		t_edge;
typedef struct s_path		t_path;
typedef struct s_listpath	t_listpath;

struct						s_map
{
	t_vert		*vertices;
	t_vert		*start;
	t_vert		*end;
	int			maxpath;
	int			ants;
	int			nbpath;
	int			**tabpath;
	char		**map;
	int			mapcount;
	bool		startB;
	bool		endB;
	bool		error;
	t_listpath	*listpath;
};

struct						s_listpath
{
	int			nbelem;
	int			maxants;
	t_path		*path;
	t_path		*cur;
	t_listpath	*next;
};

struct						s_edge
{
	t_vert	*bounds;
	t_edge	*next;
};

struct						s_path
{
	t_vert	*vertices;
	t_path	*next;
};

struct						s_vert
{
	bool	start;
	bool	end;
	bool	occ;
	bool	visited;
	int		*wt;
	int		x;
	int		y;
	char	*name;
	t_edge	*edges;
	t_vert	*orig;
	t_vert	*next;
};

struct						s_env
{
	bool	start;
	bool	end;
	bool	err;
};

int							parse_map(t_map *graph);
t_vert						*init_vert(void);
t_edge						*init_edge(t_vert *new);
t_map						*init_map(void);
int							error(void);
int							check_vert(t_vert *vert, t_vert *new);
void						destroy_map(t_map *graph);
int							ft_algo(t_map *graph);
t_vert						*find_small_vertice(t_vert *vertice);
void						print_path(t_path *path);
void						reset_vertices(t_vert *vertices);
int							create_path(t_map *graph, t_vert *vert);
void						set_path(int **tab, t_map *graph);
int							test_nbelem(int **tab, int total, t_map *graph);
void						print_graph(t_map *graph);
int							count_edge(t_vert *vert);
int							add_vert(t_map *graph, char *line, bool start,\
										bool end);
int							add_edge(t_map *graph, char *line);
t_vert						*find_vert(t_vert *vert, char *name);
int							my_isline(char c);
void						join_to_map(t_map *graph, char *line);
void						print_tab(t_path **tab, int max);

#endif
