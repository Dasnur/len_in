/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:13:41 by atote             #+#    #+#             */
/*   Updated: 2020/09/01 17:13:41 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lem-in.h"

size_t	find_index_of_room(const char *find, farm *farm)
{
	size_t	i;

	i = 0;
	while (i < farm->count_of_rooms)
	{
		if (ft_strcmp(find, farm->rooms[i]->name) == 0)
			return (i);
		i++;
	}
}

size_t	find_index_of_linked(room **rooms)
{
	size_t	i;

	i = 0;
	while (rooms[i] != NULL)
		i++;
	return (i);
}

void	links_room(farm *farm)
{
	size_t		i;
	size_t		k;
	size_t		index_of_room;
	size_t		index_of_linked;
	size_t		index_of_linked_room;

	i = 0;
	k = 0;
	while (k < farm->count_of_links)
	{
		index_of_room = find_index_of_room(farm->links[k]->begin, farm);
		index_of_linked = find_index_of_linked(farm->rooms[index_of_room]->linked);
		index_of_linked_room = find_index_of_room(farm->links[k]->end, farm);
		farm->rooms[index_of_room]->linked[index_of_linked] = farm->rooms[index_of_linked_room];
		index_of_linked = find_index_of_linked(farm->rooms[index_of_linked_room]->linked);
		farm->rooms[index_of_linked_room]->linked[index_of_linked] = farm->rooms[index_of_room];
		k++;
	}
}