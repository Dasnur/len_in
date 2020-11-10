/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:32:59 by atote             #+#    #+#             */
/*   Updated: 2020/11/10 14:18:24 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"

void	fill_room(char *line, t_room *tr, size_t *c_ind_r)
{
	size_t		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	tr->name = (char *)malloc(sizeof(char) * (i));
	i = 0;
	while (*line != ' ')
	{
		tr->name[i] = *line;
		i++;
		line++;
	}
	tr->name[i] = '\0';
	line++;
	tr->x = ft_atoi(line);
	while (*line != ' ')
		line++;
	line++;
	tr->y = ft_atoi(line);
	tr->index = *c_ind_r;
	tr->ant = -1;
	(*c_ind_r)++;
}

void	fill_link(t_link *link, char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '-')
		i++;
	link->begin = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (*line != '-')
	{
		link->begin[i] = *line;
		line++;
		i++;
	}
	link->begin[i] = '\0';
	line++;
	i = 0;
	while (line[i] != '\0')
		i++;
	link->end = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (*line != '\0')
	{
		link->end[i++] = *line;
		line++;
	}
}

void	fill_l(t_farm *farma, t_map *tmp_map)
{
	size_t	i;

	i = 0;
	if (farma->rooms[0] == NULL || farma->rooms[1] == NULL)
		exec("ERROR: Input has no start or end room\n", 21, farma);
	farma->links = (t_link**)malloc(sizeof(t_link*) * farma->count_of_links);
	while (i < farma->count_of_links)
	{
		if (tmp_map->line[0] == '#')
			tmp_map = tmp_map->next;
		else
		{
			farma->links[i] = (t_link*)malloc(sizeof(t_link));
			fill_link(farma->links[i], tmp_map->line);
			tmp_map = tmp_map->next;
			i++;
		}
	}
}

void	fill_rooms(t_farm *farma)
{
	t_map	*tmp_map;
	size_t	i;
	size_t	k;

	i = 2;
	k = 0;
	tmp_map = farma->mapa;
	init_farma(farma);
	tmp_map = tmp_map->next;
	while (k < farma->count_of_rooms)
	{
		if (ft_strcmp(tmp_map->line, "##start") == 0)
			fill_start_end(farma, &tmp_map, &k, 0);
		else if (ft_strcmp(tmp_map->line, "##end") == 0)
			fill_start_end(farma, &tmp_map, &k, 1);
		else if (tmp_map->line[0] == '#')
			tmp_map = tmp_map->next;
		else
		{
			fill_start_end(farma, &tmp_map, &k, i);
			i++;
		}
	}
	farma->rooms[i] = NULL;
	fill_l(farma, tmp_map);
}
