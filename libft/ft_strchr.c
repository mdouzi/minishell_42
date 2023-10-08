/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:15:06 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/03 22:00:48 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

/*int main()
{
	char	*str;

    str = "bo\0njour 1337";
    printf("%s", strchr(str,'n'));
    return(0);
}
*/
