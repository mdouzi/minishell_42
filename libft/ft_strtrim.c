/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:02:01 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/03 21:56:28 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int	len;
	int	i;

	i = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (!s1[i])
		return (ft_substr(s1, 0, 0));
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]) && len > i)
		len--;
	return (ft_substr(s1, i, len - i));
}

// int main()
// {
//     char *str = "          ";
//     char *st = " ";
//     printf("%s", ft_strtrim(str,st));
//     return(0);
// }
