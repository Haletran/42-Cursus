/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:57:01 by baptiste          #+#    #+#             */
/*   Updated: 2023/11/15 14:48:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	/*
	printf("%c\n", 't');	// Prints a single character.
	printf("%s\n", "test"); // Prints a string (as defined by the common C convention).
	printf("%p\n", "t");	// The void * pointer argument has to be printed in hexadecimal format.
	printf("%d\n", 10);		// Prints a decimal (base 10) number.
	printf("%i\n", 10);		// Prints an integer in base 10.
	printf("%u\n", 10);		// Prints an unsigned decimal (base 10) number
	printf("%x\n", 13);		// Prints a number in hexadecimal (base 16) lowercase format.
	printf("%X\n", 10);		// Prints a number in hexadecimal (base 16) uppercase format.
	printf("%%\n");			// Prints a percent sign
	printf("Hello\n");      //Print without %
	*/
	ft_printf("Hello %d %d %d %d %d %d ", "Hello");
	

}
