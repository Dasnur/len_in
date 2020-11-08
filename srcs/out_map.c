/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:55:01 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 20:48:51 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/lem_in.h"
#include "../ft_printf/includes/libftprintf.h"

void	out_map(t_farm *farma)
{
	size_t	i;
	t_map	*tmp;

	tmp = farma->mapa;
	i = 0;
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
