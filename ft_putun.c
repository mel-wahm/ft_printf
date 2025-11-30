/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:18:05 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/11/19 06:38:51 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putun(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_putun(num / 10);
	count += ft_putchar(num % 10 + '0');
	return (count);
}
