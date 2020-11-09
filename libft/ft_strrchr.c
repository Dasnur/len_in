/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:06:03 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 23:27:26 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char*)(&(s[i])));
	i--;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char*)(&(s[i])));
		i--;
	}
	return (NULL);
}
