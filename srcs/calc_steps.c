/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:21:07 by atote             #+#    #+#             */
/*   Updated: 2020/09/28 19:21:07 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lem-in.h"

size_t	steps_in_path(path *pathes)
{
	size_t	l;

	l = 0;
	while (pathes->rooms[l] != NULL)
		l++;
	return (--l);
}

size_t	get_index_min_cost(size_t *mas_cost, size_t len)
{
	size_t	min_index;
	size_t	min;
	size_t	i;

	i = 0;
	min_index = -1;
	min = 2147483647;
	// printf("%d\n", len);
	while (i < len)
	{
		if (mas_cost[i] < min)
		{
			min = mas_cost[i];
			min_index = i;
		}
		i++;
	}
	printf("puk\n");
	return (min_index);
}

int     calc_steps_path(path *pathes,farm *farm)
{
	size_t	*mas_cost;
	size_t	count_pathes;
	size_t	i;
	size_t	k;
	path	*tmp;

	k = 0;
	i = 0;
	count_pathes = 1;
	tmp = pathes->linked_path;
	while (tmp != NULL)
	{
		count_pathes++;
		tmp = tmp->next;
	}
	printf("%d\n", count_pathes);
	mas_cost = (size_t *)malloc(sizeof(size_t) * count_pathes);
	tmp = pathes->linked_path;
	mas_cost[i++] = steps_in_path(pathes);
	// printf("fsdf\n");
	while (i < count_pathes)
	{
		mas_cost[i] = steps_in_path(tmp);
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < farm->count_of_ants - 1)
	{
		k = get_index_min_cost(mas_cost, count_pathes);
		mas_cost[k] = mas_cost[k] + 1;
		printf("k-->%d\n", mas_cost[k]);
		i++;
	}
	return (mas_cost[get_index_min_cost(mas_cost, count_pathes)]);
}

path	*get_best_path(path *pathes, farm *farm)
{
    path	*best;
	path	*tmp;
	size_t	count_steps_min;
	size_t	steps;

	count_steps_min = 2147483647;
	best = pathes;
	tmp = pathes;
	while (tmp)
	{
    	steps = calc_steps_path(tmp, farm);
		printf("steps-->%d\n", steps);
		if (steps < count_steps_min)
		{
			count_steps_min = steps;
			best = tmp;
		}
		tmp = tmp->next;
	}
    return (best);
}