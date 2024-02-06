/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:54:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/06 17:46:11 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_lst **a, t_lst **b)
{
    t_lst *afrique;

    afrique = (*a)->next;
    if (*b == NULL)
    {
        *b = ft_lstnew((**a).content);
        free(*a);
    }
/*     else 
    {
        ft_lst_add_front(b, *a);
        free(*a);
    } */
    *a = afrique;
}