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

int		print_this_pos(path *th, farm *farm)
{
	size_t	i;
	room	*room_ant;
	int		flag;

	flag = 0;
	i = 1;
	while (i <= farm->count_of_ants) //Перепиасать
	{
		room_ant = find_room_of_ant(i, th);
		if (room_ant)
		{
			flag = 1;
			// printf("%s\n", room_ant->name);
			printf("L%d-%s ", i, room_ant->name);
		}
		i++;
	}
	farm->trash++;
	printf("\n");
	if (flag == 0)
		return (1);
	return (0);
}

int		check_all_is_gone(path *th)
{
	size_t	i;
	path	*tmp;

	tmp = th;
	while (tmp)
	{
		i = 0;
		while (tmp->rooms[i + 1] != NULL)
		{
			// printf("%d\n", tmp->rooms[i]->ant);
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
	farm->trash = 0;
	size_t  i;
	size_t  k;
	size_t	m;
	path	*tmp;

	i = 1;
	// while (gavno){
	// 	int p = 0;
	// 	while (gavno->rooms[p] != NULL){
	// 		printf(gavno->rooms[p]->name);
	// 		printf("\n");
	// 		p++;
	// 	}
	// 	gavno = gavno->next;
	// }
	th->rooms[0]->ant = i++;
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
			{
				if (tmp->rooms[k - 1]->ant != - 1)
				{
					if (k - 1 != 0)
					{
						tmp->rooms[k]->ant = tmp->rooms[k - 1]->ant;
						tmp->rooms[k - 1]->ant = -1;	
					}
						// printf("\n%d\n", farm->ants_in_path[m]);
					if (k - 1 == 0 && farm->ants_in_path[m] != 0)
					{
						tmp->rooms[k]->ant = tmp->rooms[k - 1]->ant;
						farm->ants_in_path[m] = farm->ants_in_path[m] - 1;
						tmp->rooms[k - 1]->ant = i++;
					}
					if (k - 1 == 0 && (i > farm->count_of_ants + 1))
						tmp->rooms[k - 1]->ant = -1;
					// if (tmp->rooms[k + 1] == NULL)
					// 	printf("L%d-%s ", tmp->rooms[k]->ant, tmp->rooms[k]->name);
				}
				k--;
			}
			// printf("aaa\n");
			m++;
			tmp = tmp->next;
		}
	if (print_this_pos(th, farm))
		return ;
	}
}
