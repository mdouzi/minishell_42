/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:53:05 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/03 22:01:12 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	char		*str;
	int			t;

	t = count * size;
	str = (char *)malloc(t);
	if (!str)
		return (NULL);
	ft_bzero(str, t);
	return (str);
}
