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
			tmp_back = NULL;
	}
	while (tmp)
	{
		while (tmp->rooms[i + 1] != NULL)
			i++;
		if (ft_strcmp(tmp->rooms[i]->name, farm->rooms[1]->name) != 0)
			tmp_back->next = tmp->next;
		else
			tmp_back = tmp_back->next;
		i = 0;
		tmp = tmp->next;
    }
    return (pathes);
}

path	*add_linked_path(path *p, path *aim, farm *farm)
{
	path	*tmp;
	size_t	i;

	i = 0;
	tmp = p;
	while (tmp != NULL)
		tmp = tmp->next;
	tmp = (path *)malloc(sizeof(path));
	tmp->rooms = (room**)malloc(sizeof(room*) * farm->count_of_rooms);
	while (aim->rooms[i] != NULL)
	{
		tmp->rooms[i] = aim->rooms[i];
		i++;
	}
	// printf(tmp->rooms[0]->name);
	// printf("kal\n");
	tmp->rooms[i] = NULL;
	tmp->next = NULL;
	if (p == NULL)
		p = tmp;
	return p;
}

path    *group_pathes(path *pathes, farm *farm)
{
    path    *tmp;
	path	*tmp1;
    size_t  i;
	size_t	k;

    i = 1;
    pathes = validate_pathes(pathes, farm);
    tmp = pathes;
	tmp1 = pathes;
    while (tmp)
    {
		while (tmp1)
		{
			while ((tmp->rooms[i + 1] != NULL) && (tmp1->linked_indexes[tmp->rooms[i]->index] == 0))
				i++;
			if (tmp->rooms[i + 1] == NULL)
			{
				tmp->linked_path = add_linked_path(tmp->linked_path, tmp1, farm);
				// printf(tmp->linked_path->rooms[0]->name);
				// printf("asdf\n");
			}
			i = 1;
			tmp1 = tmp1->next;
		}
		tmp1 = pathes;
        tmp = tmp->next;
    }
    return (pathes);
}