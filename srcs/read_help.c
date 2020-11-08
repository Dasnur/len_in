/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:19:53 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 20:10:37 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"
#include "../ft_printf/includes/libftprintf.h"

int		check_duplicate_name(char *line, t_map *farm_map, t_map *cur)
{
	t_map		*begin;

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

void	exec1(const char *line, size_t code, t_farm *farma, char *line1)
{
	free(line1);
	clear_mapa(farma);
	clear_links(farma);
	clear_rooms(farma);
	free(farma->rooms);
	ft_printf("%s", line);
	exit(code);
}
