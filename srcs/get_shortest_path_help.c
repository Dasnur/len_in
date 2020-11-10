/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_path_help.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 01:15:13 by atote             #+#    #+#             */
/*   Updated: 2020/11/10 14:17:45 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"

size_t	count_avail_pathes(t_farm *pf, t_edge **ne, size_t *k_path, int *flag)
{
	size_t	i;
	size_t	ii;

	pf->k = 0;
	i = 0;
	while (pf->k < pf->count_of_links * 2)
	{
		if (pf->edges[pf->k].del == 0 && pf->edges[pf->k].weight == -1)
		{
			ii = 0;
			(*ne)[i] = pf->edges[pf->k];
			while (ii < i)
			{
				if (ft_strcmp((*ne)[ii].end->name, (*ne)[i].end->name) == 0 &&
				ft_strcmp((*ne)[i].end->name, pf->rooms[0]->name) != 0)
					(*flag) = 1;
				ii++;
			}
			if (ft_strcmp((*ne)[i].begin->name, pf->rooms[1]->name) == 0)
				(*k_path)++;
			i++;
		}
		(pf->k)++;
	}
	return (i);
}

void	del_no_end(t_path *ppth, t_farm *pfarma)
{
	size_t	i;
	t_path	*tmp;
	t_path	*prev;

	tmp = ppth->next;
	prev = ppth;
	i = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->rooms[i] != NULL)
			i++;
		if (ft_strcmp(tmp->rooms[i - 1]->name, pfarma->rooms[1]->name) != 0)
			prev->next = tmp->next;
		else
			prev = prev->next;
		tmp = tmp->next;
	}
}
