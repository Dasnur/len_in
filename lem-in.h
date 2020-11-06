/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:47:39 by atote             #+#    #+#             */
/*   Updated: 2020/08/31 09:47:39 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEM_IN_
#define _LEM_IN_

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_link
{
	char			*begin;
	char			*end;
}					t_link;

typedef struct		t_room
{
	char			*name;
	int				x;
	int				y;
	size_t			count_linked_with;
	int				ant;
	struct t_room	**linked;
	size_t			index;
	struct t_room			*prev;
	size_t			seen;
}					room;

typedef struct	s_map
{
	char			*line;
	struct s_map	*next;
}					map;

typedef struct		s_farm
{
	room			**rooms;
	t_link			**links;
	size_t			*ants_in_path;
	size_t			count_of_rooms;
	size_t			count_of_links;
	int				count_of_ants;
	room			***buffer_of_pathes;
	size_t			count_index_room;
	size_t			trash;
	map				*map;
	size_t			ends;
}					farm;

typedef struct		s_path
{
	room			**rooms;
	struct s_path	*next;
	struct s_path	*linked_path;
	int				*linked_indexes;
}					path;

void	exec(const char *line, size_t code);
size_t	str_count_chr(const char *line, char a);
void    fill_rooms(farm *farm);
void    read_farm(farm *farm);
void	links_room(farm *farm);
path	*find_pathes(farm *farm, path *buffer_of_pathes);
path    *group_pathes(path *pathes, farm *farm);
path	*get_best_path(path *pathes, farm *farm);
void	out_pathes(path *th, farm *farm);
void	out_map(farm *farm);

#endif