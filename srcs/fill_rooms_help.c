/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rooms_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:06:08 by atote             #+#    #+#             */
/*   Updated: 2020/11/10 14:19:29 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"
#include "../ft_printf/includes/libftprintf.h"

void	fill_start_end(t_farm *farma, t_map **tmp_map, size_t *k, int se)
{
	if (se == 1 || se == 0)
	{
		*tmp_map = (*tmp_map)->next;
		while ((*tmp_map)->line[0] == '#')
			*tmp_map = (*tmp_map)->next;
		farma->rooms[se] = (t_room*)malloc(sizeof(t_room));
		fill_room((*tmp_map)->line, farma->rooms[se],
		&(farma->count_index_room));
		*tmp_map = (*tmp_map)->next;
		(*k)++;
	}
	else
	{
		farma->rooms[se] = (t_room*)malloc(sizeof(t_room));
		fill_room((*tmp_map)->line, farma->rooms[se],
		&(farma->count_index_room));
		*tmp_map = (*tmp_map)->next;
		(*k)++;
	}
}

void	init_farma(t_farm *f)
{
	f->count_of_ants = ft_atoi(f->mapa->line);
	if (f->count_of_ants < 1)
	{
		clear_mapa(f);
		ft_printf("ERROR: Number of ants is incorrect\n");
		exit(100);
	}
	f->count_index_room = 0;
	f->rooms = (t_room**)malloc(sizeof(t_room*) * (f->count_of_rooms + 5));
	f->rooms[0] = NULL;
	f->rooms[1] = NULL;
	f->links = NULL;
}

t_path	*vv_clear(t_room **p, int *d, t_path *tpath, t_path *rpath)
{
	bf_clear(p, d, tpath);
	free(rpath->rooms);
	free(rpath);
	return (NULL);
}

void	clear_clc_mas(int *mas_cost, int *mas_cur_cost)
{
	free(mas_cost);
	free(mas_cur_cost);
}

void	init_d_farma(t_farm *farma, int **d)
{
	size_t	i;

	i = 0;
	while (i < farma->count_of_rooms)
	{
		if (i != farma->rooms[0]->index)
			(*d)[i] = INF;
		i++;
	}
}
