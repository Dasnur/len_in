/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:59:46 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/22 21:10:00 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		to_binary(t_params *m, va_list a)
{
	int		b;
	char	*c;
	int		i;

	b = 0;
	i = 0;
	if (!(c = malloc(sizeof(char*) * 120)))
		return ;
	m->long_long_in = va_arg(a, long int);
	while (m->long_long_in)
	{
		b = m->long_long_in % 2;
		c[i] = b + '0';
		i++;
		m->long_long_in /= 2;
	}
	while (i >= 0)
	{
		ft_putchar2(c[i]);
		i--;
	}
	free(c);
}

long double	zero_part(t_params *m, long double doubl1)
{
	doubl1 = m->doubl;
	if (m->long_long_in == 0 && m->doubl > 0)
		return (doubl1 + 1);
	if (m->long_long_in == 0 && m->doubl < 0)
		return (doubl1 - 1);
	return (doubl1);
}

int			ft_check_star(char *line, int i)
{
	while (ft_check_all_flags(line, i))
	{
		if (line[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

void		format_p_firsthelp(t_params *m, char *res)
{
	m->f_check_width = (m->f_check_width - (ft_strlen(&res[0]) + 2));
	while (--(m->f_check_width) >= 0)
		ft_putchar2(' ');
	ft_putstr2("0x");
	while (m->i >= 0)
	{
		ft_putchar2(res[m->i]);
		m->i--;
	}
}

void		format_ox_fourth_help(t_params *m, int flag)
{
	if (m->f_check_zero && m->f_check_octotorp &&
	m->f_check_presicion == 0 && (m->f_check_width -= 2))
		ft_putstr2((flag == 8 ? "0X" : "0x"));
	ft_putstrrev(m->res, m, m->long_long_in);
	m->f_check_width = (m->f_check_width - ft_strlen(m->res) + 1);
	while (--(m->f_check_width) > 0)
		ft_putchar2(' ');
}
