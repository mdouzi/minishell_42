/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:36 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/02 06:35:34 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**allocation(char *s, int i, char c, char **str)
{
	int	len;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			len = 0;
			while (s[i + len] != '\0' && s[i + len] != c)
				len++;
			str[j] = ft_substr(s, i, len);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**str;
	int		str_count;

	i = 0;
	if (!s)
		return (0);
	str_count = count_strings(s, c);
	str = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!str)
		return (0);
	allocation(s, i, c, str);
	free(s);
	return (str);
}
