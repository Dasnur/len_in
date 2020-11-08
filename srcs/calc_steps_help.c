/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_steps_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:21:46 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 18:42:50 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

size_t	steps_in_path(t_path *pathes)
{
	size_t	l;

	l = 0;
	while (pathes->rooms[l] != NULL)
		l++;
	return (--l);
}

size_t	get_index_max_cost(const int *mas_cost, size_t len)
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

size_t	get_index_min_cost(const int *mas_cost, size_t len)
{
	size_t	min_index;
	int		min;
	size_t	i;

	i = 0;
	min_index = -1;
	min = 2147483647;
	while (i < len)
	{
		if (mas_cost[i] < min)
		{
			min = mas_cost[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	calc_steps_path_help(t_farm *farma, t_path *tmp, int **mc, int **mcc)
{
	int		i;
	size_t	k;

	i = 0;
	while (i < farma->count_pathes)
	{
		(*mc)[i] = steps_in_path(tmp);
		(*mcc)[i] = 0;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < farma->count_of_ants)
	{
		k = get_index_min_cost((*mc), farma->count_pathes);
		if ((*mcc)[k] == 0)
			(*mcc)[k] += (*mc)[k];
		else
			(*mcc)[k] = (*mcc)[k] + 1;
		(*mc)[k] = (*mc)[k] + 1;
		i++;
	}
}

void	botb_calc(t_farm *farma, t_path *tmp, int **mc, int **mcc)
{
	int		i;
	int		k;

	i = 0;
	while (i < farma->count_pathes)
	{
		(*mc)[i] = steps_in_path(tmp);
		farma->ants_in_path[i] = 0;
		(*mcc)[i] = 0;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < farma->count_of_ants)
	{
		k = get_index_min_cost(*mc, farma->count_pathes);
		if ((*mcc)[k] == 0)
			(*mcc)[k] += (*mc)[k];
		else
			(*mcc)[k] = (*mcc)[k] + 1;
		(*mc)[k] = (*mc)[k] + 1;
		farma->ants_in_path[k] = farma->ants_in_path[k] + 1;
		i++;
	}
}
