/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:02:56 by mzoheir           #+#    #+#             */
/*   Updated: 2023/02/07 17:27:04 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_argprint(va_list p, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(p, int));
	else if (c == 'i' || c == 'd')
		i += ft_putnbr(va_arg(p, int));
	else if (c == 's')
		i += ft_putstr(va_arg(p, char *));
	else if (c == '%')
		i += ft_putchar('%');
	else if (c == 'x')
		i += ft_putnbrhex(va_arg(p, unsigned int), BASE_LOW);
	else if (c == 'X')
		i += ft_putnbrhex(va_arg(p, unsigned int), BASE_UP);
	else if (c == 'p')
	{
		ft_putstr("0x");
		i += 2 + ft_putnbrhex(va_arg(p, unsigned long), BASE_LOW);
	}
	else if (c == 'u')
		i += ft_unsigned(va_arg(p, unsigned int));
	return (i);
}
