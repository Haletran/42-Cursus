/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:07:59 by codespace         #+#    #+#             */
/*   Updated: 2023/11/27 09:31:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_del(char format)
{
	return (format == '%');
}

int	check_specifier(char format, char specifier)
{
	return (format == specifier);
}

int	check_identifier(int len, char format, va_list args)
{
	if (check_specifier(format, 's'))
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (check_specifier(format, 'd') || check_specifier(format, 'i'))
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (check_specifier(format, 'c'))
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (check_specifier(format, '%'))
		len += ft_putchar_fd('%', 1);
	else if (check_specifier(format, 'u'))
		len += ft_putnbr_special(va_arg(args, unsigned int), 1);
	else if (check_specifier(format, 'x'))
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (check_specifier(format, 'X'))
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (check_specifier(format, 'p'))
		len += v_pointer(va_arg(args, unsigned long long), "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		c;
	va_list	args;

	len = 0;
	c = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[c])
	{
		if (check_del(format[c]) == 1)
		{
			c++;
			len = check_identifier(len, format[c], args);
		}
		else
			len += write(1, &format[c], 1);
		c++;
	}
	va_end(args);
	return (len);
}
