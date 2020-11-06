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

size_t	get_index_max_cost(size_t *mas_cost, size_t len)
{
	size_t	i;
	int		max_index;
	int		max;

	i = 0;
	max_index = -1;
	max = 0;
	while (i < len)
	{
		if (mas_cost[i] > max)
		{
			max = mas_cost[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
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
	// printf("puk\n");
	return (min_index);
}

int     calc_steps_path(path *pathes,farm *farm)
{
	size_t	*mas_cost;
	size_t	*mas_cur_cost;
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
	// printf("count_pathes-->%d\n", count_pathes);
	mas_cost = (size_t *)malloc(sizeof(size_t) * count_pathes);
	mas_cur_cost = (size_t *)malloc(sizeof(size_t) * count_pathes);
	// farm->ants_in_path = (size_t *)malloc(sizeof(size_t) * count_pathes);
	tmp = pathes->linked_path;
	mas_cost[i] = steps_in_path(pathes);
	mas_cur_cost[i++] = 0;
	// printf("fsdf\n");
	while (i < count_pathes)
	{
		mas_cost[i] = steps_in_path(tmp);
		// printf("%d\n", mas_cost[i]);
		mas_cur_cost[i] = 0;
		// farm->ants_in_path[i] = 0;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < farm->count_of_ants)
	{
		k = get_index_min_cost(mas_cost, count_pathes);
		if (mas_cur_cost[k] == 0)
			mas_cur_cost[k] += mas_cost[k];
		else
			mas_cur_cost[k] = mas_cur_cost[k] + 1;
		mas_cost[k] = mas_cost[k] + 1;
		// farm->ants_in_path[k] = farm->ants_in_path[k] + 1;
		// printf("k-->%d\n", mas_cur_cost[k]);
		i++;
	}
	return (mas_cur_cost[get_index_max_cost(mas_cur_cost, count_pathes)]);
}

path	*best_of_the_best(path *best, farm *farm)
{
	size_t	*mas_cost;
	size_t	*mas_cur_cost;
	size_t	count_pathes;
	size_t	i;
	size_t	k;
	path	*tmp;
	path	*bestest;

	k = 0;
	i = 0;
	count_pathes = 1;
	tmp = best->linked_path;
	while (tmp != NULL)
	{
		count_pathes++;
		tmp = tmp->next;
	}
	// printf("count_pathes-->%d\n", count_pathes);
	mas_cost = (size_t *)malloc(sizeof(size_t) * count_pathes);
	mas_cur_cost = (size_t *)malloc(sizeof(size_t) * count_pathes);
	farm->ants_in_path = (size_t *)malloc(sizeof(size_t) * count_pathes);
	mas_cost[i] = steps_in_path(best);
	mas_cur_cost[i++] = 0;
	tmp = best->linked_path;
	// printf("fsdf\n");
	while (i < count_pathes)
	{
		mas_cost[i] = steps_in_path(tmp);
		printf("%d\n", mas_cost[i]);
		farm->ants_in_path[i] = 0;
		mas_cur_cost[i] = 0;
		tmp = tmp->next;
		i++;
	}
	// printf("biba/bibo\n");
	i = 0;
	while (i < farm->count_of_ants)
	{
		k = get_index_min_cost(mas_cost, count_pathes);
		printf("k-->%d\n", k);
		if (mas_cur_cost[k] == 0)
			mas_cur_cost[k] += mas_cost[k];
		else
			mas_cur_cost[k] = mas_cur_cost[k] + 1;
		mas_cost[k] = mas_cost[k] + 1;
		farm->ants_in_path[k] = farm->ants_in_path[k] + 1;
		// printf("k-->%d\n", mas_cur_cost[k]);
		i++;
	}
	i = 0;
	bestest = best;
	bestest->next = best->linked_path;
	return (bestest);
}

// path	*sort_list(path *best)
// {
// 	path	*prev;
// 	path	*cur;
// 	path	*tmp;
// 	size_t	loop;

// 	loop = 0;
// 	prev = best;
// 	while (prev)
// 	{
// 		prev = prev->next;
// 		loop++;
// 	}
// 	while (loop > 0)
// 	{
// 		prev = NULL;
// 		cur = best;
// 		while (cur->next)
// 		{
// 			// printf(cur->rooms[2]->name);
// 			if (steps_in_path(cur) > steps_in_path(cur->next))
// 			{
// 				tmp = cur->next;
// 				cur->next = cur->next->next;
// 				tmp->next = cur;
// 				// printf("suck\n");
// 				if (!prev)
// 				{
// 					prev = tmp;
// 					best = prev;
// 				}
// 				else
// 				{
// 					prev->next = tmp;
// 					prev = tmp;
// 				}
// 			}
// 			else
// 			{
// 				prev = cur;
// 				cur = cur->next;
// 			}
// 		}
// 		loop--;
// 	}
// 	return (best);
// }

path	*get_best_path(path *pathes, farm *farm)
{
    path	*best;
	path	*tmp;
	path	*trash;
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
	size_t i = 0;
	best = best_of_the_best(best, farm);
	tmp = best;
	i = 0;
	while (tmp->rooms[i] != NULL){
		printf("%s ", tmp->rooms[i]->name);
		i++;
	}
	printf("   %d", farm->ants_in_path[0]);
	printf("\n");
	trash = tmp->next;
	int jk = 1;
	while (trash)
	{
		i = 0;
		while (trash->rooms[i] != NULL){
			printf("%s ", trash->rooms[i]->name);
			i++;
		}
		printf("   %d", farm->ants_in_path[jk]);
		jk++;
		printf("\n");
		trash = trash->next;
	}
	printf("\n\n\n");
	// best = sort_list(best);
	// tmp = best;
	// i = 0;
	// while (tmp->rooms[i] != NULL){
	// 	printf("%s ", tmp->rooms[i]->name);
	// 	i++;
	// }
	// printf("\n");
	// trash = tmp->next;
	// while (trash)
	// {
	// 	i = 0;
	// 	while (trash->rooms[i] != NULL){
	// 		printf("%s ", trash->rooms[i]->name);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	trash = trash->next;
	// }
	// printf("\n\n\n");
    return (best);
}