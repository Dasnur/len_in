/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:49:23 by acarlett          #+#    #+#             */
/*   Updated: 2020/11/08 23:29:46 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putlonglong2(long long int nb)
{
	char				a;
	long long int		b;

	if (nb < 0)
	{
		ft_putchar2('-');
		if (nb < -9000000000000000000)
		{
			ft_putchar2('9');
			nb = nb + 9000000000000000000;
		}
		nb *= -1;
	}
	if (nb >= 10)
		ft_putlonglong2(nb / 10);
	b = nb % 10;
	a = '0' + b;
	ft_putchar2(a);
}
