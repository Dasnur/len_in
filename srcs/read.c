/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:54:09 by atote             #+#    #+#             */
/*   Updated: 2020/11/10 14:23:50 by atote            ###   ########.fr       */
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
		exec1("ERROR: Input has room name duplicate\n", 3, farma, line);
	if (check_coordinates(line))
		exec1("ERROR: letter_in_coordinates\n", 5, farma, line);
	farma->count_of_rooms++;
}

void	read_count(t_farm *farma, char *line, t_map *tmp, size_t *flag)
{
	while (line[0] == '#' && *flag)
	{
		free(line);
		get_next_line(0, &line);
	}
	*flag = 0;
	if (str_count_chr(line, ' ') == 2 && line[0] != '#')
		read_farm_room(line, farma, tmp);
	else if (str_count_chr(line, '-') == 1 && line[0] != '#')
		farma->count_of_links++;
	else if (str_count_chr(line, '#') == 0 && tmp != farma->mapa)
		exec1("ERROR: invalid line\n", 2, farma, line);
}

void	read_farm(t_farm *farma)
{
	char	*line;
	t_map	*tmp;
	t_map	*prev;
	size_t	flag;

	farma->mapa = (t_map*)malloc(sizeof(t_map));
	tmp = farma->mapa;
	flag = 1;
	farma->count_of_links = 0;
	farma->count_of_rooms = 0;
	while (get_next_line(0, &line) > 0)
	{
		read_count(farma, line, tmp, &flag);
		tmp->line = ft_strdup(line);
		free(line);
		tmp->next = (t_map*)malloc(sizeof(t_map));
		prev = tmp;
		tmp = tmp->next;
		tmp->next = NULL;
	}
	exec_no_links_nostart_end(farma, prev);
}
