/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:56:43 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 19:33:58 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"

int		bad_case(t_farm *pfarma, t_path *shpat, int flag)
{
	size_t	ii;
	size_t	k;

	k = 0;
	if (flag)
	{
		while (shpat->rooms[k + 1])
		{
			ii = 0;
			while (ii < pfarma->count_of_links * 2)
			{
				if (ft_strcmp(shpat->rooms[k]->name, pfarma->edges[ii].end->
				name) == 0 && ft_strcmp(shpat->rooms[k + 1]->name, pfarma->
				edges[ii].begin->name) == 0)
					pfarma->edges[ii].del = 1;
				ii++;
			}
			k++;
		}
		return (1);
	}
	return (0);
}

t_path	*init_list_path(t_path *p, int f, t_farm *pf)
{
	if (f == 1)
	{
		p->rooms = (t_room**)malloc(sizeof(t_room*) * pf->count_of_rooms);
		p->rooms[0] = pf->rooms[0];
		p->next = NULL;
		return (p);
	}
	if (f == 2)
	{
		p->next = (t_path*)malloc(sizeof(*p));
		p->next->rooms = (t_room**)malloc(sizeof(t_room*) * pf->count_of_rooms);
		p->next->rooms[0] = pf->rooms[0];
		p->next->next = NULL;
		p = p->next;
		return (p);
	}
	return (p);
}

void	gsp_help1(t_path *tmp, t_room **finded, t_farm *pfarma, t_edge **ne)
{
	tmp->rooms[pfarma->j] = (*ne)[pfarma->k].begin;
	(*ne)[pfarma->k].del = 1;
	*finded = (*ne)[pfarma->k].begin;
	pfarma->k = -1;
	pfarma->j++;
}

t_path	*gsp_help(t_path *ppth, t_farm *pfarma, int k_path, t_edge *new_edges)
{
	t_path	*tmp;
	t_room	*finded;

	init_list_path(ppth, 1, pfarma);
	tmp = ppth;
	pfarma->j = 1;
	while (k_path > 0)
	{
		pfarma->k = 0;
		finded = pfarma->rooms[0];
		if (pfarma->j != 1)
			tmp = init_list_path(tmp, 2, pfarma);
		pfarma->j = 1;
		while (pfarma->k < pfarma->ii)
		{
			if (ft_strcmp(new_edges[pfarma->k].end->name, finded->name)
			== 0 && new_edges[pfarma->k].del == 0)
				gsp_help1(tmp, &finded, pfarma, &new_edges);
			(pfarma->k)++;
		}
		k_path--;
		tmp->rooms[pfarma->j] = NULL;
	}
	return (ppth);
}

t_path	*get_shortest_path(t_farm *pfarma, t_path *shpat)
{
	t_edge	*new_edges;
	t_path	*ppth;
	size_t	k_path;
	int		flag;

	flag = 0;
	new_edges = (t_edge*)malloc((pfarma->count_of_links) * sizeof(*new_edges));
	ppth = (t_path*)malloc(1 * sizeof(*ppth));
	k_path = 0;
	pfarma->ii = count_avail_pathes(pfarma, &new_edges, &k_path, &flag);
	if (bad_case(pfarma, shpat, flag))
	{
		free(ppth);
		free(new_edges);
		return (NULL);
	}
	ppth = gsp_help(ppth, pfarma, k_path, new_edges);
	free(new_edges);
	return (ppth);
}
