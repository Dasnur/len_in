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
    room	***buffer_of_pathes;

    read_farm(&farm);
    fill_rooms(&farm);
	links_room(&farm);
    // printf(farm.rooms[3]->linked[0]->name);
	buffer_of_pathes = find_pathes(&farm, buffer_of_pathes);
    printf(buffer_of_pathes[0][0]->name);
    printf(buffer_of_pathes[0][1]->name);
    printf(buffer_of_pathes[0][2]->name);
    printf(buffer_of_pathes[0][3]->name);
    // printf(buffer_of_pathes[1][1]->name);
    // printf(buffer_of_pathes[1][2]->name);
    // printf(buffer_of_pathes[1][3]->name);
	return (0);
}
