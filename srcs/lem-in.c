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
    path    *th;

    read_farm(&farm);
    fill_rooms(&farm);
	links_room(&farm);
	pathes = find_pathes(&farm, pathes);
    pathes = group_pathes(pathes, &farm);
	// th = get_best_path(pathes, &farm);
    // while (th != NULL)
    // {
    //     int i = 0;
    //     while (th->rooms[i] != NULL)
    //     {
    //         printf(th->rooms[i]->name);
    //         i++;
    //     }
    //     th = th->next;
    // }
    out_pathes(get_best_path(pathes, &farm), &farm);
    // while (pathes != NULL)
    // {
    //     int i = 0;
    //     while (pathes->rooms[i] != NULL)
    //     {
    //         printf(pathes->rooms[i]->name);
    //         i++;
    //     }
    //     i = 0;
    //     if (pathes->linked_path)
    //     {
	// 		printf("\nlinked-->");
    //         while (pathes->linked_path->rooms[i] != NULL)
    //         {
    //             printf(pathes->linked_path->rooms[i]->name);
    //             i++;
    //         }
    //     }
    //     pathes = pathes->next;
    //     printf("\n");
    // }
	return (0);
}
