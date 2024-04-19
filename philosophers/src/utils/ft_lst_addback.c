/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:44:04 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/19 16:10:58 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_lstadd_back(t_philo *lst, int value, t_table *table)
{
	t_philo	*head;

	head = lst;
	if (lst == NULL)
	{
		lst = ft_lst_new(value, table);
		return (lst);
	}
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = ft_lst_new(value, table);
	lst = head;
	return (lst);
}