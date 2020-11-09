/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:42:39 by acarlett          #+#    #+#             */
/*   Updated: 2020/11/08 23:29:47 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putstr2(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar2(s[i]);
		i++;
	}
}
