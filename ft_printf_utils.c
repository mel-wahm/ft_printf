/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:15:42 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/11/22 14:01:44 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_args(char s, va_list ap)
{
	int	count;

	count = 0;
	if (s == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (s == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (s == 'i' || s == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (s == 'x')
		count += ft_puthex(va_arg(ap, unsigned int));
	else if (s == 'X')
		count += ft_putupperhex(va_arg(ap, unsigned int));
	else if (s == 'p')
		count += ft_putaddress(va_arg(ap, unsigned long int));
	else if (s == 'u')
		count += ft_putun(va_arg(ap, unsigned int));
	else if (s == '%')
		count += ft_putchar('%');
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(s);
	}
	return (count);
}
