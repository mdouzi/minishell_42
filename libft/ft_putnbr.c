/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:56:45 by mzoheir           #+#    #+#             */
/*   Updated: 2023/02/07 17:28:13 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n <= 9 && n >= 0)
		i += ft_putchar(n + 48);
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	ft_unsigned(unsigned int k)
{
	int	c;

	c = ft_putnbr(k);
	return (c);
}

// int main()
// {
// 	ft_putnbr(123);
// }

// if (b > 9)
// 	i += ft_putnbr(b/10);
// i += ft_putchar(b%10+'0');
