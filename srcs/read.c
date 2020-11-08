/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:54:09 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 20:09:06 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"
#include "../ft_printf/includes/libftprintf.h"

void	exec(const char *line, size_t code, t_farm *farma)
{
	clear_mapa(farma);
	clear_links(farma);
	clear_rooms(farma);
	free(farma->rooms);
	ft_printf("%s", line);
	exit(code);
}

size_t	str_count_chr(const char *line, char a)
{
	size_t count;

	count = 0;
	while (*line != '\0')
	{
		if (*line == a)
			count++;
		line++;
	}
	return (count);
}

void	read_farm_room(char *line, t_farm *farma, t_map *tmp)
{
	if (check_duplicate_name(line, farma->mapa, tmp))
		exec("ERROR: Input has room name duplicate\n", 3, farma);
	if (check_coordinates(line))
		exec("ERROR: letter_in_coordinates\n", 5, farma);
	farma->count_of_rooms++;
}

void	exec_no_links_nostart_end(t_farm *farma)
{
	if (farma->count_of_rooms < 2)
		exec("Error: Input has no start or end room\n", 4, farma);
	if (farma->count_of_links == 0)
		exec("ERROR: No links\n", 9, farma);
}

void	read_farm(t_farm *farma)
{
	char	*line;
	t_map	*tmp;
	t_map	*prev;

	farma->mapa = (t_map*)malloc(sizeof(t_map));
	tmp = farma->mapa;
	farma->count_of_links = 0;
	farma->count_of_rooms = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (str_count_chr(line, ' ') == 2)
			read_farm_room(line, farma, tmp);
		else if (str_count_chr(line, '-') == 1)
			farma->count_of_links++;
		else if (str_count_chr(line, '#') == 0 && tmp != farma->mapa)
			exec1("ERROR: invalid line\n", 2, farma, line);
		tmp->line = ft_strdup(line);
		free(line);
		tmp->next = (t_map*)malloc(sizeof(t_map));
		prev = tmp;
		tmp = tmp->next;
	}
	free(prev->next);
	prev->next = NULL;
	exec_no_links_nostart_end(farma);
}
