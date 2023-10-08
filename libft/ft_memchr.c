/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:53:13 by mzoheir           #+#    #+#             */
/*   Updated: 2023/08/08 23:22:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	unsigned char	*t;
	unsigned char	k;

	t = (unsigned char *)s;
	k = (unsigned char)c;
	if (!n)
		return (0);
	while (*t != k && --n)
		t++;
	if (*t == k)
		return (t);
	return (NULL);
}
// int main()
// {
//     char s[] = "hi how are you ";
//     char k = 'a';
//     printf("%s",ft_memchr(s, k, 7));
// }