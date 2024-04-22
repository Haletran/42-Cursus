/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:44:04 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/22 12:20:33 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

t_philo	*ft_lstadd_back(t_philo *lst, int value, t_table *table)
{
    t_philo	*head;
    t_philo *tmp;

    head = lst;
    if (lst == NULL)
    {
        lst = ft_lst_new(value, table);
        return (lst);
    }
    while (lst->next != NULL)
	{
        lst = lst->next;
	}
	tmp = lst;
	lst->prev = tmp;
	lst->prev->last = 0;
    lst->next = ft_lst_new(value, table);
	while (lst->next != NULL)
	{
        lst = lst->next;
	}
	tmp = lst;
	lst->prev = tmp;
    return (lst);
}