/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:07:59 by codespace         #+#    #+#             */
/*   Updated: 2023/11/23 18:31:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr_special(unsigned int n, unsigned int fd)
{
	int len;
	len = 0;
	if (n > 9)
	{
		len += ft_putnbr_fd(n / 10, fd);
		len += ft_putnbr_fd(n % 10, fd);
	}
	else
		len += ft_putchar_fd('0' + n, fd);
	return (len);
}

int ft_putnbr_base(unsigned int nb, char *base)
{
	int i;
	int quotient;
	i = 0;

	quotient = nb / 16;
	if (quotient > 0)
		i = ft_putnbr_base(quotient, base);
	return (i + ft_putchar_fd(base[nb % 16], 1));
}

int ft_putnbr_base_ptr(unsigned long long nb, char *base)
{
	int i;
	unsigned long long quotient;
	i = 0;

	quotient = nb / 16;
	if (quotient > 0)
		i = ft_putnbr_base_ptr(quotient, base);
	return (i + ft_putchar_fd(base[nb % 16], 1));
}

int v_pointer(unsigned long long ptr, char *base)
{
	int len;

	len = 0;
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	len += ft_putstr_fd("0x", 1);
	len += ft_putnbr_base_ptr(ptr, base);
	return (len);
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
				len += ft_putnbr_special(va_arg(args, unsigned int), 1);
			else if (check_specifier(format[c], 'x'))
				len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (check_specifier(format[c], 'X'))
				len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
			else if (check_specifier(format[c], 'p'))
				len += v_pointer(va_arg(args, unsigned long long), "0123456789abcdef");
		}
		else
			len += write(1, &format[c], 1);
		c++;
	}
	va_end(args);
	return (len);
}
