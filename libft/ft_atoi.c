/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:52:58 by mzoheir           #+#    #+#             */
/*   Updated: 2023/02/24 15:03:43 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(char *str)
{
	unsigned char	*s;
	int				i;
	long			res;
	long			sign;

	s = (unsigned char *)str;
	res = 0;
	i = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= 48 && s[i] <= 57)
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res * sign);
}
