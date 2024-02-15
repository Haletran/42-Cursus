/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:20:08 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 15:27:56 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstadd_back(t_lst *lst, int value)
{
	t_lst	*head;

	head = lst;
	if (lst == NULL)
	{
		lst = ft_lst_new(value, 0);
		return (lst);
	}
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = ft_lst_new(value, 0);
	lst = head;
	return (lst);
}
