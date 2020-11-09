/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:05:41 by atote             #+#    #+#             */
/*   Updated: 2020/11/09 09:50:30 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../ft_printf/includes/libftprintf.h"

int	main(void)
{
	t_farm	farma;
	t_path	**pats;
	t_path	*short_path;
	size_t	k;

	read_farm(&farma);
	ft_printf("read-success\n");
	fill_rooms(&farma);
	printf("fill-success\n");
	links_room(&farma);
	printf("links-success\n");
	pats = (t_path**)malloc(sizeof(t_path*) * (farma.count_of_links + 2));
	k = 0;
	while ((short_path = bellman_ford(&farma)))
	{
		if (pats[k] != NULL)
			pats[k] = (t_path *)malloc(sizeof(t_path) * 2);
		delete_edges(short_path, &farma);
		pats[k] = get_shortest_path(&farma, short_path);
		free(short_path->rooms);
		// short_path->rooms = NULL;
		free(short_path);
		// short_path = NULL;
		if (pats[k])
			k++;
	}
	pats[k] = NULL;
	// k = 0;
	// i = 0;
	// path **tmp;
	// path *tmp1;
	// tmp = pPats;
	// while (tmp[k]) {
	// 	tmp1 = tmp[k];
	// 	while (tmp1) {
	// 		while (tmp1->rooms[i] != NULL) {
	// 			printf("%s ", tmp1->rooms[i]->name);
	// 			i++;
	// 		}
	// 		printf("\n");
	// 		i = 0;
	// 		tmp1 = tmp1->next;
	// 	}
	// 	printf("\n\n\n");
	// 	k++;
	// }
	out_map(&farma);
	out_pathes(get_best_path(pats, &farma), &farma);
	clear(&farma, pats);
	printf("%ld\n", farma.trash);
	return (0);
}
