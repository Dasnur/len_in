/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_pathes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:25:49 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 18:37:18 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include "../libft/libft.h"
#include "../ft_printf/includes/libftprintf.h"

t_room	*find_room_of_ant(int ant, t_path *th)
{
	int		i;
	t_path	*tmp;

	tmp = th;
	while (tmp)
	{
		i = 1;
		while (tmp->rooms[i] != NULL)
		{
			if (tmp->rooms[i]->ant == ant)
				return (tmp->rooms[i]);
			i++;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int		print_this_pos(t_path *th, t_farm *farma)
{
	int		i;
	t_room	*room_ant;
	int		flag;

	flag = 0;
	i = 1;
	while (i <= farma->count_of_ants)
	{
		room_ant = find_room_of_ant(i, th);
		if (room_ant)
		{
			flag = 1;
			if (ft_strcmp(room_ant->name, farma->rooms[1]->name) != 0)
				ft_printf("L%d-%s ", i, room_ant->name);
		}
		i++;
	}
	farma->trash++;
	ft_printf("\n");
	if (flag == 0)
		return (1);
	return (0);
}

int		check_all_is_gone(t_path *th)
{
	size_t	i;
	t_path	*tmp;

	tmp = th;
	while (tmp)
	{
		i = 0;
		while (tmp->rooms[i + 1] != NULL)
		{
			if (tmp->rooms[i]->ant != -1)
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	move_ants(t_farm *farma, t_path *tmp, size_t *k, size_t m)
{
	if (tmp->rooms[*k - 1]->ant != -1)
	{
		if (*k - 1 != 0)
		{
			tmp->rooms[*k]->ant = tmp->rooms[*k - 1]->ant;
			tmp->rooms[*k - 1]->ant = -1;
		}
		if (*k - 1 == 0 && farma->ants_in_path[m] != 0)
		{
			tmp->rooms[*k]->ant = tmp->rooms[*k - 1]->ant;
			farma->ants_in_path[m] = farma->ants_in_path[m] - 1;
			tmp->rooms[*k - 1]->ant = (farma->i)++;
		}
		if (*k - 1 == 0 && (farma->i > farma->count_of_ants + 1))
			tmp->rooms[*k - 1]->ant = -1;
		if (tmp->rooms[*k + 1] == NULL)
			ft_printf("L%d-%s ", tmp->rooms[*k]->ant,
			tmp->rooms[*k]->name);
	}
	*k = *k - 1;
}

void	out_pathes(t_path *th, t_farm *farma)
{
	size_t	k;
	size_t	m;
	t_path	*tmp;

	farma->i = 1;
	farma->trash = 0;
	th->rooms[0]->ant = (farma->i)++;
	while (check_all_is_gone(th))
	{
		tmp = th;
		m = 0;
		while (tmp)
		{
			k = 0;
			while (tmp->rooms[k + 1] != NULL)
				k++;
			while (k > 0)
				move_ants(farma, tmp, &k, m);
			m++;
			tmp = tmp->next;
		}
		if (print_this_pos(th, farma))
			return ;
	}
}
