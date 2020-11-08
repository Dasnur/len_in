/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:21:07 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 18:42:30 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"

int		calc_steps_path(t_path *pathes, t_farm *farma)
{
	int		*mas_cost;
	int		*mas_cur_cost;
	size_t	i;
	t_path	*tmp;

	i = 0;
	farma->count_pathes = 0;
	tmp = pathes;
	while (tmp != NULL)
	{
		farma->count_pathes++;
		tmp = tmp->next;
	}
	mas_cost = (int *)malloc(sizeof(int) * farma->count_pathes);
	mas_cur_cost = (int *)malloc(sizeof(int) * farma->count_pathes);
	tmp = pathes;
	calc_steps_path_help(farma, tmp, &mas_cost, &mas_cur_cost);
	i = mas_cur_cost[get_index_max_cost(mas_cur_cost,
	farma->count_pathes)];
	free(mas_cur_cost);
	free(mas_cost);
	return (i);
}

t_path	*best_of_the_best(t_path *best, t_farm *farma)
{
	int		*mas_cost;
	int		*mas_cur_cost;
	int		i;
	int		k;
	t_path	*tmp;

	k = 0;
	i = 0;
	farma->count_pathes = 0;
	tmp = best;
	while (tmp != NULL)
	{
		farma->count_pathes++;
		tmp = tmp->next;
	}
	mas_cost = (int *)malloc(sizeof(int) * (farma->count_pathes));
	mas_cur_cost = (int *)malloc(sizeof(int) * (farma->count_pathes));
	farma->ants_in_path = (size_t *)malloc(sizeof(size_t) *
	(farma->count_pathes));
	mas_cost[i] = steps_in_path(best);
	mas_cur_cost[i] = 0;
	tmp = best;
	botb_calc(farma, tmp, &mas_cost, &mas_cur_cost);
	clear_clc_mas(mas_cost, mas_cur_cost);
	return (best);
}

t_path	*get_best_path(t_path **pathes, t_farm *farma)
{
	t_path	*best;
	t_path	*tmp;
	size_t	count_steps_min;
	size_t	steps;
	size_t	k;

	k = 0;
	count_steps_min = 2147483647;
	tmp = pathes[k];
	while (tmp)
	{
		steps = calc_steps_path(tmp, farma);
		if (steps < count_steps_min)
		{
			count_steps_min = steps;
			best = tmp;
		}
		tmp = pathes[k++];
	}
	best = best_of_the_best(best, farma);
	return (best);
}
