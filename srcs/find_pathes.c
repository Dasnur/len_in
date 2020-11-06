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
		i++;
	}
	// *tmp = *p;
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
		pathes->linked_path = NULL;
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
		pathes->linked_path = NULL;
		// calloc_buffer_ints(tmp->next->linked_indexes, farm->count_of_rooms);
		// calloc_buffer_2lvl(tmp->next->rooms, farm->count_of_rooms);
		tmp->next->next = NULL;
		// printf("gavno\n");
	}
	return pathes;
}

// room	**get_name_node(path *pathes)
// {
// 	path	*tmp;

// 	tmp = pathes;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	return tmp->rooms;
// }

int		verificate_inserted_room(size_t index, path *th)
{
	// printf("LOOK-->%d\n", th->linked_indexes[index]);
	if (th->linked_indexes[index] == 0)
		return (1);
	return (0);
}

path	*push(path *p, room *r)
{
	size_t	i;

	i = 0;
	while (p->rooms[i] != NULL)
		i++;
	// printf("I-->%s\n", r->name);
	p->rooms[i] = r;
	p->rooms[i + 1] = NULL;
	p->linked_indexes[r->index] = 1;
	return (p);
}

int		preverificate_inserted_room(room *insert, path *p, room *stop, farm *farm)
{
	int		*link_indexes;
	size_t	k;
	size_t	i;

	i = 0;
	k = 0;
	while (ft_strcmp(p->rooms[k]->name, stop->name) != 0)
		k++;
	k = k + 1;
	link_indexes = (int *)malloc(sizeof(int) * farm->count_of_rooms);
	calloc_buffer_ints(link_indexes, farm->count_of_rooms);
	while (i < k)
	{
		link_indexes[p->rooms[i]->index] = p->linked_indexes[p->rooms[i]->index];
		i++; 
	}
	if (link_indexes[insert->index] == 1)
	{
		free(link_indexes);
		return (0);
	}
	free(link_indexes);
	return (1);
}

void	copy_path(path *p, path *aim, room *stop, size_t count)
{
	size_t	i;
	path	*tmp;
	size_t	k;

	k = 0;
	tmp = p;
	i = 0;
	while (tmp->next)
		tmp = tmp->next;
	while (ft_strcmp(aim->rooms[i]->name, stop->name) != 0)
	{
		tmp->rooms[i] = aim->rooms[i];
		i++;
	}
	tmp->rooms[i] = aim->rooms[i];
	tmp->rooms[i + 1] = NULL;
	i++;
	while (k < i)
	{
		tmp->linked_indexes[aim->rooms[k]->index] = aim->linked_indexes[aim->rooms[k]->index];
		k++;
	}
}

void	rec_find_pathes(path **p, room* rt, farm *farm)
{
	size_t	i = 0;
	size_t	flag = 0;
	path	*tmp = *p;

	while (rt->linked[i] != NULL)
	{
		if (ft_strcmp(rt->name, farm->rooms[1]->name) == 0)
			return ;
		if (flag == 0)
		{
			if (verificate_inserted_room(rt->linked[i]->index, tmp)){
				tmp = push(tmp, rt->linked[i]);
				flag = 1;
				rec_find_pathes(&tmp, rt->linked[i], farm);
				// size_t ii = 0;
				// while (tmp->rooms[ii] != NULL){
				// 	printf("%s ", tmp->rooms[ii]->name);
				// 	ii++;
				// }
				// printf("\n");
			}
		}
		else
		{
			if (preverificate_inserted_room(rt->linked[i], tmp, rt, farm))
			{
				*p = add_spath_to_pathes(*p, farm);
				copy_path(*p, tmp, rt, farm->count_of_rooms);
				flag = 0;
				while (tmp->next)
					tmp = tmp->next;
				if (verificate_inserted_room(rt->linked[i]->index, tmp))
				{
					tmp = push(tmp, rt->linked[i]);
					flag = 1;
					rec_find_pathes(&tmp, rt->linked[i], farm);
				}
			}
		}
		i++;
	}
	// size_t ii = 0;
	// while (tmp->rooms[ii] != NULL){
	// 	printf("%s ", tmp->rooms[ii]->name);
	// 	ii++;
	// }
	// printf("\n");
	return ;
}

path	*find_pathes(farm *farm, path *pathes)
{
	int		flag_of_the_end_of_cycle;
	size_t	k;
	size_t	index_links;
	path	*tmp;
	size_t	ends;

	ends = 0;
	farm->ends = 0;
	k = 0;
	index_links = 0;
	flag_of_the_end_of_cycle = 1;
	pathes = NULL;
	pathes = add_spath_to_pathes(pathes, farm);
	pathes->rooms[0] = farm->rooms[0];
	pathes->linked_indexes[pathes->rooms[0]->index] = 1;
	rec_find_pathes(&pathes, farm->rooms[0], farm);
	// printf("gui\n");
	k = 0;
	tmp = pathes;
	printf("-->%d\n", farm->ends);
	while (tmp)
	{
		while (tmp->rooms[k] != NULL){
			printf("%s ", tmp->rooms[k]->name);
			k++;
		}
		printf("\n");
		tmp = tmp->next;
		k = 0;
	}
	printf("\n\n\n");

	// while (flag_of_the_end_of_cycle)
	// {
	// 	while (tmp)
	// 	{
	// 		// printf("OH\n");
	// 		while (tmp->rooms[k] != NULL)
	// 		{
	// 			// printf("%d", k);
	// 			// printf(tmp->rooms[k]->name);
	// 			// printf(" ");
	// 			k++;
	// 		}
	// 		// printf("\n");
	// 		k--;
	// 		while (tmp->rooms[k]->linked[index_links] != NULL)
	// 		{
	// 			if (verificate_inserted_room(tmp->rooms[k]->linked[index_links]->index, tmp) && (ft_strcmp(tmp->rooms[k]->name, farm->rooms[1]->name) != 0))
	// 			{
	// 				if (tmp->rooms[k + 1] == NULL)
	// 				{
	// 					tmp->rooms[k + 1] = tmp->rooms[k]->linked[index_links];
	// 					tmp->linked_indexes[tmp->rooms[k]->linked[index_links]->index] = 1;
	// 					tmp->rooms[k + 2] = NULL;
	// 					flag_of_the_end_of_cycle = 0;
	// 				}
	// 				else 
	// 				{
	// 					pathes = add_spath_to_pathes(pathes, farm);
	// 					pathes = copy_buffer_2lvl_with_new_el(pathes, tmp, tmp->rooms[k]->linked[index_links], farm->count_of_rooms);
	// 					flag_of_the_end_of_cycle = 0;
	// 				}
	// 			}
	// 			if ((ft_strcmp(tmp->rooms[k]->linked[index_links]->name, farm->rooms[1]->name) == 0))
	// 			{
	// 				if (ends > farm->count_of_ants)
	// 				{
	// 					// printf("%s\n", tmp->rooms[k]->linked[index_links]->name);
	// 					return (pathes);
	// 				}
	// 				ends++;
	// 			}
	// 			index_links++;
	// 		}
	// 		tmp = tmp->next;
	// 		index_links = 0;
	// 		k = 0;
	// 	}
	// 	// printf("OUT2\n");
	// 	if (!flag_of_the_end_of_cycle)
	// 		flag_of_the_end_of_cycle = 1;
	// 	else
	// 		flag_of_the_end_of_cycle = 0;
	// 	tmp = pathes;
	// 	ends = 0;
	// }
	return (pathes);
}

