/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:17:30 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/24 19:27:00 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <limits.h>

int		ft_check_long_int(char *line, int i)
{
	while (line[i] != 'd' && line[i] != 'i')
	{
		if (((line[i] == 'l' || line[i] == 'j' || line[i] == 'z') &&
		(line[i + 1] == 'd' || line[i + 1] == 'i' ||
					line[i + 1] == 'u' || line[i + 1] == 'o' ||
				line[i + 1] == 'x' || line[i + 1] == 'X')) || line[i] == 'U')
			return (1);
		if (line[i] == 'l' && line[i + 1] == 'l' && (line[i + 2] == 'd' ||
					line[i + 2] == 'i' || line[i + 2] == 'u' ||
			line[i + 2] == 'o' || line[i + 2] == 'x' ||
			line[i + 2] == 'X' || line[i + 3] == 'x'))
			return (2);
		i++;
	}
	return (0);
}

int		ft_choose_flags_help(char *line, int i)
{
	if (line[i] == 'g')
		return (92);
	if (line[i] == 'e')
		return (91);
	if (line[i] == 'E')
		return (911);
	if (line[i] == 'b')
		return (12);
	return (-1);
}

int		ft_choose_flags(char *line, int i)
{
	while (ft_check_all_flags(line, i))
	{
		if (ft_check_vl(line[i]))
			return (0);
		if (line[i] != '%')
			i++;
	}
	if (line[i] == 'c')
		return (1);
	if (line[i] == 's')
		return (2);
	if (line[i] == 'p')
		return (3);
	if (line[i] == 'd' || line[i] == 'i')
		return (4);
	return (choose_flags_first_help(line, i));
}

int		ft_crossroads(int i, va_list a, char *line)
{
	t_params m;

	m.type = ft_choose_flags(line, i);
	if (m.type == 1)
		format_c(line, i, a, m.type);
	if (m.type == 4 || m.type == 6)
		d_u(line, i, a, m);
	if (m.type == 2)
		format_str(line, i, a);
	if (m.type == 3)
		format_p(line, i, a);
	if (m.type == 5)
		format_o8(line, i, a);
	if (m.type == 7 || m.type == 8)
		format_x(line, i, a, m.type);
	if (m.type == 9 || m.type == 91 || m.type == 911 || m.type == 92)
		format_f(line, i, a, m.type);
	if (m.type == 10)
		format_c(line, i, a, m.type);
	if (m.type == 12)
		to_binary(&m, a);
	return (count_flags(line, i));
}

int		ft_printf(char *line, ...)
{
	int			i;
	va_list		a;

	i = 0;
	g_count = 0;
	va_start(a, line);
	while (line[i])
	{
		if (line[i] == '%')
		{
			i = ft_crossroads(i + 1, a, line);
			if (help_ft_printf(line, i) && (i++))
				continue ;
			if (line[i + 1] == '\0')
				break ;
			if (line[i] == '%' && !ft_check_all_flags(line, i + 1))
				i--;
		}
		else if (line[i] == '%' && line[i + 1] == '%' && (i++))
			ft_putchar2('%');
		else if (line[i] != '%')
			ft_putchar2(line[i]);
		i++;
	}
	return (help2_ft_printf(a, g_count));
}
