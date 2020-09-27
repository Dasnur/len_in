/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:32:39 by atote             #+#    #+#             */
/*   Updated: 2020/09/01 18:32:39 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lem-in.h"

void	calloc_buffer_1lvl(room ***buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		buffer[i] = NULL;
		i++;
	}
}

void	calloc_buffer_2lvl(room **buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		buffer[i] = NULL;
		i++;
	}
}

path	*copy_buffer_2lvl_with_new_el(path *p, path *aim, room *r, size_t count)
{
	path	*tmp;
	size_t	i;

	i = 0;
	int k1 = 0;
	tmp = p;
	// printf("F\n");
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (aim->rooms[i + 1] != NULL)
	{
		tmp->rooms[i] = aim->rooms[i];
		// printf(tmp->rooms[i]->name);
		// printf(aim->rooms[i]->name);
		i++;
	}
	tmp->rooms[i] = r;
	while (k1 < count)
	{
		tmp->linked_indexes[k1] = aim->linked_indexes[k1];
		k1++;
	}
	tmp->linked_indexes[aim->rooms[i]->index] = 0;
	tmp->linked_indexes[tmp->rooms[i]->index] = 1;
	// printf("F\n");
	// printf("%s %d ", tmp->rooms[i]->name, k1);
	// r->seen_flag = 1;
	return p;
}

void	calloc_buffer_ints(int *mas, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		mas[i] = 0;
		i++;
	}
}

path	*add_spath_to_pathes(path *pathes, farm *farm)
{
	path	*tmp;

	tmp = pathes;
	if (pathes == NULL)
	{
		pathes = (path *)malloc(sizeof(path));
		pathes->rooms = (room **)malloc(sizeof(room *) * farm->count_of_rooms);
		pathes->linked_indexes = (int *)malloc(sizeof(int) * farm->count_of_rooms);
		calloc_buffer_ints(pathes->linked_indexes, farm->count_of_rooms);
		calloc_buffer_2lvl(pathes->rooms, farm->count_of_rooms);
		pathes->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (path*)malloc(sizeof(path));
		tmp->next->rooms = (room **)malloc(sizeof(room *) * farm->count_of_rooms);
		tmp->next->linked_indexes = (int *)malloc(sizeof(int) * farm->count_of_rooms);
		calloc_buffer_ints(tmp->next->linked_indexes, farm->count_of_rooms);
		calloc_buffer_2lvl(tmp->next->rooms, farm->count_of_rooms);
		tmp->next->next = NULL;
		// printf("gavno\n");
	}
	return pathes;
}

room	**get_name_node(path *pathes)
{
	path	*tmp;

	tmp = pathes;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return tmp->rooms;
}

int		verificate_inserted_room(size_t index, path *begin, path *th)
{
	path	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (tmp == th)
		{
			if (th->linked_indexes[index] == 0)
				return (1);
			return (0);
		}
		tmp = tmp->next;
	}
}

path	*find_pathes(farm *farm, path *pathes)
{
	int		flag_of_the_end_of_cycle;
	size_t	i;
	size_t	k;
	size_t	index_links;
	size_t	end_buffer_2lvl;
	size_t	ii;
	path	*tmp;
	room 	**tmp_my;

	ii = 0;
	end_buffer_2lvl = 1;
	k = 0;
	index_links = 0;
	i = 0;
	flag_of_the_end_of_cycle = 1;
	pathes = NULL;
	pathes = add_spath_to_pathes(pathes, farm);
	// printf("%s\n", buffer_of_pathes[0][0]->linked[1]->name);
	pathes->rooms[0] = farm->rooms[0];
	pathes->linked_indexes[pathes->rooms[0]->index] = 1;
	tmp = pathes;
	while (flag_of_the_end_of_cycle)
	{
		while (tmp)
		{
			printf("OH\n");
			while (tmp->rooms[k] != NULL)
			{
				printf(tmp->rooms[k]->name);
				k++;
			}
			k--;
			while (tmp->rooms[k]->linked[index_links] != NULL)
			{
				printf("HERE\n");
				printf(tmp->rooms[k]->linked[index_links]->name);
				if (tmp->rooms[k + 1] == NULL)
				{
					printf("HERE1\n");
					if (verificate_inserted_room(tmp->rooms[k]->linked[index_links]->index, pathes, tmp) && (ft_strcmp(tmp->rooms[k]->name, farm->rooms[1]->name) != 0))
					{
						tmp->rooms[k + 1] = tmp->rooms[k]->linked[index_links];
						tmp->linked_indexes[tmp->rooms[k]->linked[index_links]->index] = 1;
						flag_of_the_end_of_cycle = 0;
					}
				}
				else 
				{
					printf("HERE2\n");
					if (verificate_inserted_room(tmp->rooms[k]->linked[index_links]->index, pathes, tmp) && (ft_strcmp(tmp->rooms[k]->name, farm->rooms[1]->name) != 0))
					{
						pathes = add_spath_to_pathes(pathes, farm);
						pathes = copy_buffer_2lvl_with_new_el(pathes, tmp, tmp->rooms[k]->linked[index_links], farm->count_of_rooms);
						flag_of_the_end_of_cycle = 0;
					}
				}
				printf("OUT1\n");
				index_links++;
			}
			printf("WH\n");
			tmp = tmp->next;
			index_links = 0;
			k = 0;
		}
		printf("OUT2\n");
		if (!flag_of_the_end_of_cycle)
			flag_of_the_end_of_cycle = 1;
		else
			flag_of_the_end_of_cycle = 0;
		tmp = pathes;
	}
	return (pathes);
}

