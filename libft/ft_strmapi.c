/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:52:56 by mzoheir           #+#    #+#             */
/*   Updated: 2022/10/11 18:41:01 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char yo(unsigned int i,char s)
// {
//     (void) i;
//     return (s - 32);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (0);
	str = malloc(ft_strlen(s) + 1);
	if (!(str))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main(void)
// {
//     char s[] = "abcdef";
//     printf("%s",ft_strmapi(s, yo));
//     return(0);
// }