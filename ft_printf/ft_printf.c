/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:07:59 by codespace         #+#    #+#             */
/*   Updated: 2023/11/22 18:07:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

void ft_putnbr_special(unsigned int n, unsigned int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

size_t ft_putnbr_base(size_t nb, char *base)
{
	int i;
	size_t quotient;
	i = 0;
	if (nb == __LONG_MAX__)
	{
		write(1, "ffffffff ", 8);
		return (8);
	}
	quotient = nb / 16;
	if (quotient > 0)
		i = ft_putnbr_base(quotient, base);
	return (i + ft_putchar_fd(base[nb % 16], 1));
}

void v_pointer(void *ptr, char *base)
{

	long long x;
	x = (long long)ptr;
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(x, base);
}

int check_del(char format)
{
	return (format == '%');
}

int check_specifier(char format, char specifier)
{
	return (format == specifier);
}

int ft_printf(const char *format, ...)
{
	int c;
	int len;

	len = 0;
	c = 0;
	if (!format)
		return (-1);
	va_list args;
	va_start(args, format);
	while (format[c] != '\0')
	{
		if (check_del(format[c]) == 1)
		{
			c++;
			if (check_specifier(format[c], 's'))
				len += ft_putstr_fd(va_arg(args, char *), 1);
			else if (check_specifier(format[c], 'd'))
				len += ft_putnbr_fd(va_arg(args, int), 1);
			else if (check_specifier(format[c], 'c'))
				len += ft_putchar_fd(va_arg(args, int), 1);
			else if (check_specifier(format[c], '%'))
				len += ft_putchar_fd('%', 1);
			else if (check_specifier(format[c], 'i'))
				len += ft_putnbr_fd(va_arg(args, int), 1);
			else if (check_specifier(format[c], 'u'))
				ft_putnbr_special(va_arg(args, unsigned int), 1);
			else if (check_specifier(format[c], 'x'))
				len += ft_putnbr_base(va_arg(args, size_t), "0123456789abcdef");
			else if (check_specifier(format[c], 'X'))
				len += ft_putnbr_base(va_arg(args, size_t), "0123456789ABCDEF");
			else if (check_specifier(format[c], 'p'))
				v_pointer(va_arg(args, void *), "0123456789abcdef");
		}
		else
			len += write(1, &format[c], 1);
		c++;
	}
	va_end(args);
	return (len);
}
