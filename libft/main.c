/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:36:59 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 17:11:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int main() 
{ 
    char str[100] = "Learningisfun"; 
    char *first, *second; 
    first = str; 
    second = str; 
    printf("Original string :%s\n ", str); 
    memmove(first + 8, first, 10); 
    printf("memmove : %s\n ", str);  
    ft_memmove(second + 8, first, 10); 
    printf("ft_memmove : %s\n ", str); 
  
    return 0; 
}
