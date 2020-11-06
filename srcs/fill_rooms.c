/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:32:59 by atote             #+#    #+#             */
/*   Updated: 2020/08/31 10:32:59 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lem-in.h"

void	init_linked_NULL(room *this_room, size_t count_of_links)
{
	size_t	i;

	i = 0;
	this_room->linked = (room**)malloc(sizeof(room*) * count_of_links);
	while (i < count_of_links)
	{
		this_room->linked[i] = NULL;
		i++;
	}
}

void	fill_room(char *line, room *room, size_t count_of_links, size_t *count_index_room)
{
	size_t		i;

	i = 0;
	init_linked_NULL(room, count_of_links);
	while (line[i] != ' ')
		i++;
	room->name = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (*line != ' ')
	{
		room->name[i] = *line;
		i++;
		line++;
	}
	room->name[i] = '\0';
	line++;
	room->x = ft_atoi(line);
	while (*line != ' ')
		line++;
	line++;
	room->y = ft_atoi(line);
	room->count_linked_with = 0;
	room->index = *count_index_room;
	room->ant = -1;
	room->seen = 0;
	(*count_index_room)++;
}

void	fill_link(t_link* link, char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '-')
		i++;
	link->begin = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (*line != '-')
	{
		link->begin[i] = *line;
		line++;
		i++;
	}
	link->begin[i] = '\0';
	line++;
	i = 0;
	while (line[i] != '\0')
		i++;
	link->end = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (*line != '\0')
	{
		link->end[i] = *line;
		line++;
		i++;
	}
}

void    fill_rooms(farm *farm)
{
	map		*tmp_map;
	size_t	i;
	size_t	k;

	farm->count_index_room = 0;
	i = 2;
	k = 0;
	printf("dfasd\n");
	farm->rooms = (room**)malloc(sizeof(room*) * (farm->count_of_rooms));
	farm->rooms[0] = NULL;
	farm->rooms[1] = NULL;
	tmp_map = farm->map;
	farm->count_of_ants = ft_atoi(farm->map->line);
	if (farm->count_of_ants < 1)
		exec("ERROR: Number of ants is incorrect\n", 1);
	tmp_map = tmp_map->next;
	while (k < farm->count_of_rooms)
	{
		if (ft_strcmp(tmp_map->line, "##start") == 0)
    	{
			tmp_map = tmp_map->next;
			while (tmp_map->line[0] == '#')
				tmp_map = tmp_map->next;
			farm->rooms[0] = (room*)malloc(sizeof(room));
			fill_room(tmp_map->line, farm->rooms[0], farm->count_of_links, &(farm->count_index_room));
			tmp_map = tmp_map->next;
			k++;
		}
		else if (ft_strcmp(tmp_map->line, "##end") == 0)
		{
			k++;
			tmp_map = tmp_map->next;
			while (tmp_map->line[0] == '#')
				tmp_map = tmp_map->next;
			// if (str_count_chr(tmp_map->line, ' ') != 1)
			// 	exec("ERROR: No end room\n", 2);
			farm->rooms[1] = (room*)malloc(sizeof(room));
			fill_room(tmp_map->line, farm->rooms[1], farm->count_of_links, &(farm->count_index_room));
			tmp_map = tmp_map->next;
		}
		else if (tmp_map->line[0] == '#')
			tmp_map = tmp_map->next;
		else
		{
			farm->rooms[i] = (room*)malloc(sizeof(room));
			fill_room(tmp_map->line, farm->rooms[i], farm->count_of_links, &(farm->count_index_room));
			tmp_map = tmp_map->next;
			k++;
			i++;
		}
	}
	if (farm->rooms[0] == NULL || farm->rooms[1] == NULL)
		exec("ERROR: Input has no start or end room\n", 2);
	farm->rooms[i] = NULL;
	i = 0;
	farm->links = (t_link**)malloc(sizeof(t_link*) * farm->count_of_links);
	while (i < farm->count_of_links)
	{
		if (tmp_map->line[0] == '#')
			tmp_map = tmp_map->next;
		else
		{
			farm->links[i] = (t_link*)malloc(sizeof(t_link));
			fill_link(farm->links[i], tmp_map->line);
			tmp_map = tmp_map->next;
			i++;
		}
	}
}