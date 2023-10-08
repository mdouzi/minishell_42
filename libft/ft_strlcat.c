/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:53:25 by mzoheir           #+#    #+#             */
/*   Updated: 2023/08/08 23:23:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	ldst;
	int	lsrc;

	if (dstsize == 0 && dst == 0)
		return (0);
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (ldst >= dstsize)
		return (lsrc + dstsize);
	i = 0;
	while (src[i] && (ldst + i) < dstsize - 1)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (lsrc + ldst);
}
