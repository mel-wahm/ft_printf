/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:59:18 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/11/20 15:54:08 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 15)
		count += ft_puthex(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}
