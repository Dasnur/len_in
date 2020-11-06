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

#include <stdio.h>
#include "../libft/libft.h"
#include "../lem-in.h"

void	exec(const char *line, size_t code)
{
	printf("%s", line);
	exit(code);
}

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

int		check_duplicate_name(char *line, map *farm_map, map *cur)
{
	map		*begin;

	begin = farm_map;
	if (str_count_chr(line, '#') == 1)
		return (0);
	while (begin != cur && begin)
	{
		if (ft_strcmp(line, begin->line) == 0)
			return (1);
		begin = begin->next;
	}
	return (0);
}

int		check_coordinates(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != ' ')
		i++;
	i++;
	while (line[i] != ' ')
	{
		if (line[i] < '0' || line[i] > '9')
			return (1);
		i++;
	}
	i++;
	while (line[i] != '\0')
	{
		if (line[i] < '0' || line[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void    read_farm(farm *farm)
{
	char	*line;
	map		*tmp;
	map		*prev;

	farm->map = (map*)malloc(sizeof(map));
	tmp = farm->map;
	farm->count_of_links = 0;
	farm->count_of_rooms = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (str_count_chr(line, ' ') == 2)
		{
			if (check_duplicate_name(line, farm->map, tmp))
				exec("ERROR: Input has room name duplicate\n", 3);
			if (check_coordinates(line))
				exec("ERROR: letter_in_coordinates\n", 5);
			farm->count_of_rooms++;
		}
		else if (str_count_chr(line, '-') == 1)
			farm->count_of_links++;
		else if (str_count_chr(line, '#') == 0 && tmp != farm->map)
			exec("ERROR: invalid line\n", 2);
		tmp->line = ft_strdup(line);
		tmp->next = (map*)malloc(sizeof(map));
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	// printf("fasgd\n");
	// while (farm->map->next)
	// {
	// 	printf("%s\n", farm->map->line);
	// 	farm->map = farm->map->next;
	// }
	// printf("fasdf\n");
	if (farm->count_of_rooms < 2)
		exec("Error: Input has no start or end room\n", 4);
	if (farm->count_of_links == 0)
		exec("ERROR: No links\n", 9);
}
