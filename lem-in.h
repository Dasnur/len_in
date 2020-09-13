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
	int				seen_flag;
	struct t_room	**linked;
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
	size_t			count_of_rooms;
	size_t			count_of_links;
	size_t			count_of_ants;
	room			***buffer_of_pathes;
	map				*map;
}					farm;

void    fill_rooms(farm *farm);
void    read_farm(farm *farm);
void	links_room(farm *farm);
room	***find_pathes(farm *farm, room ***buffer_of_pathes);

#endif