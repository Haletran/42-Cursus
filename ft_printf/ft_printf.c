/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:07:59 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 16:39:16 by baptiste         ###   ########.fr       */
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
	if (format == '%')
		return 1;
	return 0;
}
char check_p(char format)
{
	if (format == 's')
		return 's';
	else if (format == 'd')
		return 'd';
	else if (format == 'c')
		return 'c';
	return 0;
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
			if (check_p(format[c++]) == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
				c++;
			}
			else if (check)
			else 
				c++;
		}
		else
			write(1, &format[c], 1);
		c++;
	}
	va_end(args);
}
