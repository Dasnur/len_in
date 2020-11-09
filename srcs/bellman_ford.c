/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:26:16 by atote             #+#    #+#             */
/*   Updated: 2020/11/09 09:49:31 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"

void	recovery_path(t_farm *farma, t_path *rpath, t_path *tpath, t_room **p)
{
	int		i;
	int		k;
	size_t	index;

	i = 0;
	k = 0;
	index = farma->rooms[1]->index;
	while (index != farma->rooms[0]->index)
	{
		tpath->rooms[i] = p[index];
		index = p[index]->index;
		i++;
	}
	i--;
	while (i >= 0)
	{
		rpath->rooms[k] = tpath->rooms[i];
		k++;
		i--;
	}
	rpath->rooms[k] = farma->rooms[1];
	k++;
	rpath->rooms[k] = NULL;
}

int		fill_vector_of_pathes_help(t_farm *farma, int **d, t_room ***p, int k)
{
	if ((*d)[farma->edges[k].begin->index] < INF &&
	farma->edges[k].del == 0)
	{
		if ((*d)[farma->edges[k].begin->index] + farma->edges[k].
		weight < (*d)[farma->edges[k].end->index])
		{
			(*d)[farma->edges[k].end->index] = (*d)[farma->edges[k].
			begin->index] + farma->edges[k].weight;
			(*p)[farma->edges[k].end->index] = farma->edges[k].begin;
			return (1);
		}
	}
	return (0);
}

void	fill_vector_of_pathes(t_farm *farma, int **d, t_room ***p)
{
	size_t	i;
	size_t	k;
	int		any;

	any = 1;
	i = 1;
	k = 0;
	while (i < farma->count_of_rooms && any != 0)
	{
		any = 0;
		while (k < farma->count_of_links * 2)
		{
			any = any + fill_vector_of_pathes_help(farma, d, p, k);
			k++;
		}
		k = 0;
		i++;
	}
}

void	bf_clear(t_room **p, int *d, t_path *tpath)
{
	free(p);
	free(d);
	free(tpath->rooms);
	free(tpath);
}

t_path	*bellman_ford(t_farm *farma)
{
	int		*d;
	t_room	**p;
	t_path	*tpath;
	t_path	*rpath;

	d = (int *)malloc(sizeof(int) * (farma->count_of_rooms + 5));
	p = (t_room **)malloc(sizeof(t_room*) * (farma->count_of_rooms + 5));
	tpath = (t_path *)malloc(sizeof(t_path) * 2);
	rpath = (t_path *)malloc(sizeof(t_path) * 2);
	tpath->rooms = (t_room **)malloc(sizeof(t_room *) * (farma->count_of_rooms + 5));
	rpath->rooms = (t_room **)malloc(sizeof(t_room *) * (farma->count_of_rooms + 5));
	d[farma->rooms[0]->index] = 0;
	init_d_farma(farma, &d);
	fill_vector_of_pathes(farma, &d, &p);
	if (d[farma->rooms[1]->index] == INF)
		return (vv_clear(p, d, tpath, rpath));
	recovery_path(farma, rpath, tpath, p);
	bf_clear(p, d, tpath);
	return (rpath);
}
