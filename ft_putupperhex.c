/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupperhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:50:57 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/11/20 01:41:15 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putupperhex(unsigned int num)
{
	int	count;

	count = 0;
	if (num > 15)
		count += ft_putupperhex(num / 16);
	count += ft_putchar("0123456789ABCDEF"[num % 16]);
	return (count);
}
