/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:07:59 by codespace         #+#    #+#             */
/*   Updated: 2023/11/15 14:50:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printf(const char *format, ...)
{  
    va_list args;
    va_start(args, format);

    //va_arg
    va_end(args);
    printf("Hello");
}