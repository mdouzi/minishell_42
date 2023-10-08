/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:18 by mzoheir           #+#    #+#             */
/*   Updated: 2023/02/07 17:28:16 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrhex(long b, char *base)
{
	int	i;

	i = 0;
	if (b < 16)
		i += ft_putchar(base[b]);
	if (b >= 16)
	{
		i += ft_putnbrhex(b / 16, base);
		i += ft_putnbrhex(b % 16, base);
	}
	return (i);
}
