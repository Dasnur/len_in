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
    printf("read-success\n");
    fill_rooms(&farm);
    printf("fill-success\n");
    // printf(farm.rooms[0]->name);
    // printf("\n");
	links_room(&farm);
    printf("links-success\n");
	pathes = find_pathes(&farm, pathes);
    printf("pathes finded:\n");
    pathes = group_pathes(pathes, &farm);
    printf("pathes grouped\n");
    // out_map(&farm);
    out_pathes(get_best_path(pathes, &farm), &farm);
    printf("%ld\n", farm.trash);
	return (0);
}
