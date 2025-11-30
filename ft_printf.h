/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:58:23 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/11/22 14:03:47 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putnbr(int n);
int		ft_putun(unsigned int num);
int		ft_putstr(char *s);
int		count_digits(long n);
int		ft_putupperhex(unsigned int num);
int		ft_puthex(unsigned int n);
int		ft_putaddress(unsigned long int n);
int		ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		print_args(char s, va_list ap);
size_t	ft_strlen(const char *s);

#endif
