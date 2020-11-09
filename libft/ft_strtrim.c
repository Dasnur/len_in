/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <atote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:21:25 by atote             #+#    #+#             */
/*   Updated: 2020/11/08 23:21:32 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_str(int k, int i, char const *s)
{
	int		p;
	char	*res;

	if (!s)
		return (NULL);
	p = 0;
	res = (char *)malloc(sizeof(char) * (k - i + 2));
	if (!res)
		return (NULL);
	if (k == i)
	{
		res[0] = '\0';
		return (res);
	}
	while (i <= k)
	{
		res[p] = s[i++];
		p++;
	}
	res[p] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i++;
	k = i;
	while (s[k] != '\0')
		k++;
	if (k == i)
		return (create_str(k, i, s));
	k--;
	while ((s[k] == ' ') || (s[k] == '\t') || (s[k] == '\n'))
		k--;
	res = create_str(k, i, s);
	return (res);
}
