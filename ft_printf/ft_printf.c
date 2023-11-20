/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:07:59 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 17:40:36 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int check_del(char format)
{
	return (format == '%');
}

int check_specifier(char format, char specifier)
{
	return (format == specifier);
}

void ft_printf(const char *format, ...)
{
	int c;

	c = 0;
	va_list args;
	va_start(args, format);

	while (format[c] != '\0')
	{
		if (check_del(format[c]) == 1)
		{
			c++;
			if (check_specifier(format[c], 's'))
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (check_specifier(format[c], 'd'))
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (check_specifier(format[c], 'c'))
				ft_putchar_fd(va_arg(args, int), 1);
			else if (check_specifier(format[c], '%'))
				ft_putchar_fd('%', 1);
		}
		else
			write(1, &format[c], 1);
		c++;
	}

	va_end(args);
}
