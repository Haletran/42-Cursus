/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:32:48 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/06 21:51:06 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lst_size(t_lst *a)
{
    int size;
    
    size = 0;
    while (a != NULL)
    {
        a = a->next; 
        size++;
    }
    return (size);
}