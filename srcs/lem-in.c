/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:04:12 by atote             #+#    #+#             */
/*   Updated: 2020/08/29 19:04:12 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int		main()
{
    farm    farm;
    path	*pathes;

    read_farm(&farm);
    fill_rooms(&farm);
    // int i = 0;
    // while (i < farm.count_of_rooms)
    // {
    //     printf("fdsf\n");
    //     printf(farm.rooms[i]->name);
    //     i++;
    // }
	links_room(&farm);
    // printf(farm.rooms[5]->linked[1]->name);
	pathes = find_pathes(&farm, pathes);
    while (pathes != NULL)
    {
        int i = 0;
        while (pathes->rooms[i] != NULL)
        {
            printf(pathes->rooms[i]->name);
            i++;
        }
        pathes = pathes->next;
        printf("\n");
    }
	return (0);
}
