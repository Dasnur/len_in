/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:47:39 by atote             #+#    #+#             */
/*   Updated: 2020/11/10 14:17:55 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define INF 1e9

# include <stdlib.h>

typedef struct		s_link
{
	char			*begin;
	char			*end;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				ant;
	size_t			index;
}					t_room;

typedef struct		s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct		s_edge
{
	t_room			*begin;
	t_room			*end;
	int				weight;
	int				del;
}					t_edge;

typedef struct		s_farm
{
	t_room			**rooms;
	t_link			**links;
	size_t			*ants_in_path;
	size_t			count_of_rooms;
	size_t			count_of_links;
	int				count_of_ants;
	size_t			count_index_room;
	size_t			trash;
	t_map			*mapa;
	size_t			ends;
	t_edge			*edges;
	int				count_pathes;
	int				i;
	size_t			ii;
	size_t			j;
	size_t			k;
}					t_farm;

typedef struct		s_path
{
	t_room			**rooms;
	struct s_path	*next;
	struct s_path	*linked_path;
	int				*linked_indexes;
}					t_path;

void				exec(const char *line, size_t code, t_farm *farma);
size_t				str_count_chr(const char *line, char a);
void				fill_rooms(t_farm *farma);
void				read_farm(t_farm *farma);
void				links_room(t_farm *farma);
t_path				*get_best_path(t_path **pathes, t_farm *farma);
void				out_pathes(t_path *th, t_farm *farma);
void				out_map(t_farm *farma);
t_path				*add_st_path_to_pathes(t_path *pathes, t_farm *farma);
t_path				*bellman_ford(t_farm *farma);
void				delete_edges(t_path *rt_path, t_farm *farma);
t_path				*get_shortest_path(t_farm *farma, t_path *short_path);
int					check_coordinates(char *line);
int					check_duplicate_name(char *line, t_map *farm_map,
t_map *cur);
void				init_farma(t_farm *farma);
void				fill_start_end(t_farm *farma, t_map **tmp_map,
size_t *k, int se);
void				botb_calc(t_farm *farma, t_path *tmp, int **mc,
int **mcc);
void				calc_steps_path_help(t_farm *farma, t_path *tmp,
int **mc, int **mcc);
size_t				get_index_min_cost(const int *mas_cost, size_t len);
size_t				get_index_max_cost(const int *mas_cost, size_t len);
size_t				steps_in_path(t_path *t_pathes);
size_t				count_avail_pathes(t_farm *pf, t_edge **ne, size_t
*k_path, int *flag);
void				clear(t_farm *farma, t_path **pats);
void				clear_mapa(t_farm *farma);
void				fill_room(char *line, t_room *tr, size_t *c_ind_r);
void				clear_links(t_farm *farma);
void				clear_rooms(t_farm *farma);
t_path				*vv_clear(t_room **p, int *d, t_path *tt_path, t_path
*rt_path);
void				clear_clc_mas(int *mas_cost, int *mas_cur_cost);
void				bf_clear(t_room **p, int *d, t_path *tt_path);
void				exec1(const char *line, size_t code, t_farm *farma,
char *line1);
void				init_d_farma(t_farm *farma, int **d);
void				exec_no_links_nostart_end(t_farm *farma, t_map *prev);
void				del_no_end(t_path *ppth, t_farm *pfarma);

#endif
