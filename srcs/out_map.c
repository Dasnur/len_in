/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:39:49 by atote             #+#    #+#             */
/*   Updated: 2020/11/06 13:31:28 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lem-in.h"

void	out_map(farm *farm)
{
	size_t	i;

	i = 0;
	while (farm->map->next)
	{
		printf("%s\n", farm->map->line);
		farm->map = farm->map->next;
	}
	printf("\n");
}