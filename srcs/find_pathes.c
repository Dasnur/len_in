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

void	copy_buffer_2lvl_with_new_el(room ***buffer_of_pathes, size_t end_of_buffer_2lvl, size_t i, room *r)
{
	size_t	l;

	l = 0;
	while (buffer_of_pathes[i][l + 1] != NULL)
	{
		buffer_of_pathes[end_of_buffer_2lvl][l] = buffer_of_pathes[i][l];
		l++;
	}
	printf("F\n");
	buffer_of_pathes[end_of_buffer_2lvl][l] = r;
	r->seen_flag = 1;
}

room	***find_pathes(farm *farm, room ***buffer_of_pathes)
{
	int		flag_of_the_end_of_cycle;
	size_t	i;
	size_t	k;
	size_t	index_links;
	size_t	end_buffer_2lvl;
	size_t	ii;

	ii = 0;
	end_buffer_2lvl = 1;
	k = 0;
	index_links = 0;
	i = 0;
	flag_of_the_end_of_cycle = 1;
	buffer_of_pathes = (room***)malloc(sizeof(room**) * farm->count_of_rooms + 1);
	calloc_buffer_1lvl(buffer_of_pathes, farm->count_of_rooms + 1);
	buffer_of_pathes[0] = (room**)malloc(sizeof(room*) * farm->count_of_rooms + 1);
	calloc_buffer_2lvl(buffer_of_pathes[0], farm->count_of_rooms + 1);
	buffer_of_pathes[0][0] = farm->rooms[0];
	// printf("%s\n", buffer_of_pathes[0][0]->linked[1]->name);
	farm->rooms[0]->seen_flag = 1;
	while (flag_of_the_end_of_cycle)
	{
		while (i < end_buffer_2lvl)
		{
			printf("OH\n");
			while (buffer_of_pathes[i][k] != NULL)
			{
				// printf("fd\n");
				printf(buffer_of_pathes[i][k]->name);
				k++;
			}
			k--;
			// printf(" -->%d %d\n", i, k);
			// printf(buffer_of_pathes[i][k]->linked[0]->name);
			while (buffer_of_pathes[i][k]->linked[index_links] != NULL)
			{
				printf("HERE\n");
				if (buffer_of_pathes[i][k + 1] == NULL && buffer_of_pathes[i][k]->linked[index_links]->seen_flag == 0)
				{
					printf("HERE1\n");
					buffer_of_pathes[i][k + 1] = buffer_of_pathes[i][k]->linked[index_links];
					if (ft_strcmp(buffer_of_pathes[i][k]->linked[index_links]->name, farm->rooms[1]->name) != 0)
						buffer_of_pathes[i][k]->linked[index_links]->seen_flag = 1;
					flag_of_the_end_of_cycle = 0;
				}
				else if (buffer_of_pathes[i][k]->linked[index_links]->seen_flag == 0)
				{
					printf("HERE2\n");
					buffer_of_pathes[end_buffer_2lvl + ii] = (room**)malloc(sizeof(room*) * farm->count_of_links);
					calloc_buffer_2lvl(buffer_of_pathes[end_buffer_2lvl + ii], farm->count_of_links);
					copy_buffer_2lvl_with_new_el(buffer_of_pathes, end_buffer_2lvl + ii, i, buffer_of_pathes[i][k]->linked[index_links]);
					ii++;
					flag_of_the_end_of_cycle = 0;
				}
				printf("OUT1\n");
				if (ft_strcmp(farm->rooms[1]->name, buffer_of_pathes[i][k]->linked[index_links]->name) == 0)
				{
					size_t
				}
				index_links++;
			}
			printf("WH\n");
			i++;
			index_links = 0;
			k = 0;
		}
		printf("OUT2\n");
		if (!flag_of_the_end_of_cycle)
			flag_of_the_end_of_cycle = 1;
		else
			flag_of_the_end_of_cycle = 0;
		end_buffer_2lvl = end_buffer_2lvl + ii;
		ii = 0;
		i = 0;
	}
	return (buffer_of_pathes);
}

