/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:20:50 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 18:41:51 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	clear_mapa(t_farm *farma)
{
	t_map		*tmp;
	t_map		*mapa;

	tmp = farma->mapa;
	while (tmp)
	{
		mapa = tmp;
		tmp = tmp->next;
		free(mapa->line);
		free(mapa);
	}
}

void	clear_paths(t_path **pats)
{
	size_t	k;
	t_path	*tmp;
	t_path	*tmp1;

	k = 0;
	while (pats[k] != NULL)
	{
		tmp = pats[k];
		while (tmp)
		{
			tmp1 = tmp->next;
			free(tmp->rooms);
			free(tmp);
			tmp = tmp1;
		}
		k++;
	}
	free(pats);
}

void	clear_links(t_farm *farma)
{
	size_t	i;

	i = 0;
	if (farma->links)
	{
		while (i < farma->count_of_links && farma->links[i])
		{
			free(farma->links[i]->begin);
			free(farma->links[i]->end);
			free(farma->links[i]);
			i++;
		}
		free(farma->links);
	}
}

void	clear_rooms(t_farm *farma)
{
	size_t	it;

	it = 0;
	if (farma->rooms)
	{
		while ((it < farma->count_of_rooms) && farma->rooms[it])
		{
			free(farma->rooms[it]->name);
			free(farma->rooms[it]);
			it++;
		}
	}
}

void	clear(t_farm *farma, t_path **pats)
{
	clear_rooms(farma);
	free(farma->edges);
	free(farma->rooms);
	clear_mapa(farma);
	clear_paths(pats);
	clear_links(farma);
	free(farma->ants_in_path);
}
