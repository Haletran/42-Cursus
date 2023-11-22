/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:07:59 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 12:26:36 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_putnbr_special(int n, int fd)
{
	if(n < 0)
		ft_putstr_fd("4294967295", 1);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr (nb % 10);
	}
	else
		ft_putchar_fd('0' + nb, 1);
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

	c = 0;
	if (!format)
		return 0;
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
			else if (check_specifier(format[c], 'i'))
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (check_specifier(format[c], 'u'))
				ft_putnbr_special(va_arg(args, unsigned int), 1);
			else if (check_specifier(format[c], 'x'))
				ft_putnbr(va_arg(args, unsigned int));
		}
		else
			write(1, &format[c], 1);
		c++;
	}
	va_end(args);
	return(ft_strlen(format));
}
