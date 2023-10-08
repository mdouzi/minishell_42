/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:38:43 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/04 22:19:18 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	cp_st(char *src, char *dst, int *i)
{
	while (src[*i])
	{
		dst[*i] = src[*i];
		(*i)++;
	}
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	cp_st(s1, str, &i);
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[len1 + len2] = '\0';
	free(s1);
	return (str);
}
