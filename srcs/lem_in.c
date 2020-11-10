/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:05:41 by atote             #+#    #+#             */
/*   Updated: 2020/11/10 15:51:38 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../ft_printf/includes/libftprintf.h"

void	find_pathes(t_farm *farma, t_path **pats)
{
	t_path	*short_path;
	size_t	k;

	k = 0;
	while ((short_path = bellman_ford(farma)))
	{
		if (pats[k] != NULL)
			pats[k] = (t_path *)malloc(sizeof(t_path) * 2);
		delete_edges(short_path, farma);
		pats[k] = get_shortest_path(farma, short_path);
		free(short_path->rooms);
		free(short_path);
		if (pats[k])
			k++;
	}
	pats[k] = NULL;
}

int		main(void)
{
	t_farm	farma;
	t_path	**pats;

	read_farm(&farma);
	fill_rooms(&farma);
	links_room(&farma);
	pats = (t_path**)malloc(sizeof(t_path*) * (farma.count_of_links + 2));
	find_pathes(&farma, pats);
	if (pats[0] == NULL)
	{
		free(pats);
		free(farma.edges);
		exec("ERROR: No path from start to end\n", 666, &farma);
	}
	out_map(&farma);
	out_pathes(get_best_path(pats, &farma), &farma);
	clear(&farma, pats);
	return (0);
}
