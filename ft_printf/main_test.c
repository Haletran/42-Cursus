/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:57:01 by baptiste          #+#    #+#             */
/*   Updated: 2023/11/22 14:23:22 by codespace        ###   ########.fr       */
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
	int n = 0;
	void *ptr = &n;
	
	ft_printf("·FT_PRINTF = 1 : %s  2 : %s  3 : %d 4 : %c  5 : %% 6: %u 7: %i 8 : %x 9 : %X 10 : %p", "Hello", "Goodbye", 10, 'd', -123, -2147483647, 894, 894, ptr);
	printf("\n·PRINTF = 1 : %s  2 : %s  3 : %d 4 : %c  5 : %% 6 : %u 7 : %i 8 : %x 9: %X 10 : %p\n", "Hello", "Goodbye", 10, 'd', -123, -2147483647, 894, 894, ptr);
}
