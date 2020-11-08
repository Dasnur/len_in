/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:11:55 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 18:41:20 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"

void	find_mirror_edge(t_edge tedg, t_farm *farma)
{
	size_t k;

	k = 0;
	while (k < farma->count_of_links * 2)
	{
		if (ft_strcmp(tedg.begin->name, farma->edges[k].end->name) == 0
		&& ft_strcmp(tedg.end->name, farma->edges[k].begin->name) == 0)
			farma->edges[k].weight = -1;
		k++;
	}
}

void	find_and_del_edge(char *begin, char *end, t_farm *farma)
{
	size_t	k;

	k = 0;
	while (k < farma->count_of_links * 2)
	{
		if (ft_strcmp(farma->edges[k].begin->name, begin) == 0 &&
		ft_strcmp(farma->edges[k].end->name, end) == 0)
		{
			farma->edges[k].del = 1;
			find_mirror_edge(farma->edges[k], farma);
		}
		k++;
	}
}

void	delete_edges(t_path *rpath, t_farm *farma)
{
	size_t i;

	i = 0;
	while (rpath->rooms[i + 1] != NULL)
	{
		find_and_del_edge(rpath->rooms[i]->name,
		rpath->rooms[i + 1]->name, farma);
		i++;
	}
}
