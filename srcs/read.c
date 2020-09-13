/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:04:57 by atote             #+#    #+#             */
/*   Updated: 2020/08/29 19:04:57 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lem-in.h"

size_t	str_count_chr(const char *line, char a)
{
	size_t count = 0;

	while (*line != '\0')
	{
		if (*line == a)
			count++;
		line++;
	}
	return count;
}

void    read_farm(farm *farm)
{
	char	*line;
	map		*tmp;

	farm->map = (map*)malloc(sizeof(map));
	tmp = farm->map;
	farm->count_of_links = 0;
	farm->count_of_rooms = 0;
	while (get_next_line(1, &line))
	{
		if (str_count_chr(line, ' ') == 2)
			farm->count_of_rooms++;
		if (str_count_chr(line, '-') == 1)
			farm->count_of_links++;
		tmp->line = ft_strdup(line);
		tmp->next = (map*)malloc(sizeof(map));
		tmp = tmp->next;
	}
}