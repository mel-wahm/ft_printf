/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:49:30 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/11/20 15:36:34 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	phex(unsigned long int n)
{
	int	count;

	count = 0;
	if (n > 15)
		count += phex(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putaddress(unsigned long int n)
{
	if (n == 0)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (phex(n) + 2);
}
