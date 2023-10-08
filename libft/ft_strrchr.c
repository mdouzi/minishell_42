/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:19:26 by mzoheir           #+#    #+#             */
/*   Updated: 2022/10/05 20:20:59 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*q;
	char	b;
	int		i;
	int		len;

	q = (char *)s;
	b = (char)c;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (q[len] == b)
			return (&q[len]);
		len--;
	}
	return (0);
}
