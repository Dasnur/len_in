/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:13:41 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 19:33:28 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"
#include "../ft_printf/includes/libftprintf.h"

size_t	find_index_of_room(const char *find, t_farm *farma)
{
	size_t	i;

	i = 0;
	while (i < farma->count_of_rooms)
	{
		if (ft_strcmp(find, farma->rooms[i]->name) == 0)
			return (i);
		i++;
	}
	ft_printf("ERROR: Invelid link\n");
	exit(6);
}

size_t	find_index_of_linked(t_room **rooms)
{
	size_t	i;

	i = 0;
	while (rooms[i] != NULL)
		i++;
	return (i);
}

int		check_link_start_end(t_farm *farma)
{
	size_t	i;

	i = 0;
	while (i < farma->count_of_links)
	{
		if (ft_strcmp(farma->links[i]->begin, farma->rooms[0]->name) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	links_room(t_farm *f)
{
	size_t		i;
	size_t		k;
	size_t		index_of_room;
	size_t		index_of_linked_room;

	i = 0;
	k = 0;
	if (check_link_start_end(f))
		exec("Start with no link", 77, f);
	f->edges = (t_edge *)malloc(sizeof(t_edge) * (f->count_of_links * 2));
	while (k < f->count_of_links)
	{
		index_of_room = find_index_of_room(f->links[k]->begin, f);
		index_of_linked_room = find_index_of_room(f->links[k]->end, f);
		k++;
		f->edges[i].begin = f->rooms[index_of_room];
		f->edges[i].end = f->rooms[index_of_linked_room];
		f->edges[i].del = 0;
		f->edges[i].weight = 1;
		f->edges[i + 1].begin = f->rooms[index_of_linked_room];
		f->edges[i + 1].end = f->rooms[index_of_room];
		f->edges[i + 1].del = 0;
		f->edges[i + 1].weight = 1;
		i = i + 2;
	}
}
