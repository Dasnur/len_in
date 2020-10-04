/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_pathes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:25:49 by atote             #+#    #+#             */
/*   Updated: 2020/09/29 19:25:49 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"
#include "../libft/libft.h"

room	*find_room_of_ant(int ant, path *th)
{
	int		i;
	path	*tmp;

	i = 1;
	while (th->rooms[i] != NULL)
	{
		if (th->rooms[i]->ant == ant)
			return (th->rooms[i]);
		i++;
	}
	tmp = th->linked_path;
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

void	print_this_pos(path *th, farm *farm)
{
	size_t	i;
	room	*room_ant;

	i = 1;
	while (i <= farm->count_of_ants)
	{
		room_ant = find_room_of_ant(i, th);
		if (room_ant && (ft_strcmp(room_ant->name, farm->rooms[1]->name) != 0))
			printf("L%d-%s ", i, room_ant->name);
		i++;
	}
	printf("\n");
}

int		check_all_is_gone(path *th)
{
	size_t	i;
	path	*tmp;

	tmp = th->linked_path;
	i = 0;
	while (th->rooms[i + 1] != NULL)
	{
		if (th->rooms[i]->ant != -1)
			return (1);
		i++;
	}
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

void	out_pathes(path *th, farm *farm)
{
	size_t  i;
	size_t  k;
	path	*tmp;

	i = 1;
	th->rooms[0]->ant = i++;
	while (check_all_is_gone(th))
	{
		k = 0;
		while (th->rooms[k + 1] != NULL)
			k++;
		while (k > 0)
		{
			if (th->rooms[k - 1]->ant != - 1)
			{
				th->rooms[k]->ant = th->rooms[k - 1]->ant;
				th->rooms[k - 1]->ant = -1;
				if (th->rooms[k + 1] == NULL)
					printf("L%d-%s ", th->rooms[k]->ant, th->rooms[k]->name);
				if (k - 1 == 0 && i > farm->count_of_ants)
					th->rooms[k - 1]->ant = -1;
				else if (k - 1 == 0)
					th->rooms[k - 1]->ant = i++;
				else
					th->rooms[k - 1]->ant = -1;
			}
			k--;
		}
		tmp = th->linked_path;
		while (tmp)
		{
			k = 0;
			while (tmp->rooms[k + 1] != NULL)
				k++;
			while (k > 0)
			{
				if (tmp->rooms[k - 1]->ant != - 1)
				{
					tmp->rooms[k]->ant = tmp->rooms[k - 1]->ant;
					tmp->rooms[k - 1]->ant = -1;
					if (tmp->rooms[k + 1] == NULL)
						printf("L%d-%s ", tmp->rooms[k]->ant, tmp->rooms[k]->name);
					if (k - 1 == 0 && i > farm->count_of_ants)
						tmp->rooms[k - 1]->ant = -1;
					else if (k - 1 == 0)
						tmp->rooms[k - 1]->ant = i++;
					else
						tmp->rooms[k - 1]->ant = -1;
				}
				k--;
			}
			tmp = tmp->next;
		}
		print_this_pos(th, farm);
	}
}