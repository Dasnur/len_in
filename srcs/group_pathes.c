/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_pathes.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:30:56 by atote             #+#    #+#             */
/*   Updated: 2020/09/28 16:30:56 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lem-in.h"

path    *validate_pathes(path *pathes, farm *farm)
{
	path    *tmp;
	path    *tmp_back;
	size_t  i;

	i = 0;
	tmp = pathes->next;
	tmp_back = pathes;
	// printf(tmp_back->rooms[1]->name);
	if (tmp == NULL)
	{
		while (tmp_back->rooms[i + 1] != NULL)
			i++;
		if (ft_strcmp(tmp_back->rooms[i]->name, farm->rooms[1]->name) != 0)
			exec("ERROR: no pathes\n", 10);
	}
	while (tmp)
	{	
		while (tmp_back->rooms[i + 1] != NULL)
			i++;
		if (tmp_back == pathes && (ft_strcmp(tmp_back->rooms[i]->name, farm->rooms[1]->name) != 0))
		{
			pathes = pathes->next;
			tmp_back = pathes;
			tmp = tmp->next;
		}
		else
		{
			i = 0;
			while (tmp->rooms[i + 1] != NULL)
				i++;
			if (ft_strcmp(tmp->rooms[i]->name, farm->rooms[1]->name) != 0)
				tmp_back->next = tmp->next;
			else
				tmp_back = tmp_back->next;
			tmp = tmp->next;
		}
		i = 0;
    }
    return (pathes);
}

path	*add_linked_path(path *p, path *aim, farm *farm)
{
	path	*tmp;
	size_t	i;

	i = 0;
	if (p == NULL)
	{
		p = (path *)malloc(sizeof(path));
		p->rooms = (room**)malloc(sizeof(room*) * farm->count_of_rooms);
		while (aim->rooms[i] != NULL)
		{
			p->rooms[i] = aim->rooms[i];
			i++;
		}
		p->rooms[i] = NULL;
		p->next = NULL;
	}
	else
	{
		tmp = p;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (path *)malloc(sizeof(path));
		tmp->next->rooms = (room**)malloc(sizeof(room*) * farm->count_of_rooms);
		while (aim->rooms[i] != NULL)
		{
			tmp->next->rooms[i] = aim->rooms[i];
			i++;
		}
	}
	return p;
}

path    *group_pathes(path *pathes, farm *farm)
{
    path    *tmp;
	path	*tmp1;
	path	*gavno;
    size_t  i;
	size_t	k;
	path *tmp_gavno;
    i = 1;

	gavno =pathes;
	// while (gavno){
	// 	int p = 0;
	// 	while (gavno->rooms[p] != NULL){
	// 		printf(gavno->rooms[p]->name);
	// 		printf(" ");
	// 		p++;
	// 	}
	// 	printf("\n");
	// 	gavno = gavno->next;
	// }
	// printf("\n\n\n");
    pathes = validate_pathes(pathes, farm);
	gavno =pathes;
	while (gavno){
		int p = 0;
		while (gavno->rooms[p] != NULL){
			printf(gavno->rooms[p]->name);
			printf(" ");
			p++;
		}
		printf("\n");
		gavno = gavno->next;
	}
	printf("\n\n\n");
    tmp = pathes;
	tmp1 = pathes->next;
    while (tmp)
    {
		tmp->linked_path = NULL;
		while (tmp1)
		{
			while ((tmp->rooms[i + 1] != NULL) && (tmp1->linked_indexes[tmp->rooms[i]->index] == 0))
				i++;
			if (tmp->rooms[i + 1] == NULL)
				tmp->linked_path = add_linked_path(tmp->linked_path, tmp1, farm);
			i = 1;
			tmp1 = tmp1->next;
		}
		// printf("aaa\n");
        tmp = tmp->next;
		if (tmp)
			tmp1 = tmp->next;
    }
	gavno = pathes;
	// printf("HUIII\n");
    return (pathes);
}