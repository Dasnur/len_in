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
	links_room(&farm);
    printf("links-success\n");
	pathes = find_pathes(&farm, pathes);
    pathes = group_pathes(pathes, &farm);
    out_pathes(get_best_path(pathes, &farm), &farm);
	return (0);
}
