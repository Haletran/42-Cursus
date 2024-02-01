/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:54:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 16:13:24 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_lst *a, t_lst *b)
{
	if (b == NULL)
		return ;
	ft_lst_add_front(&a, b);
	// delone on b
}

void	pb(t_lst *b, t_lst *a)
{
	if (a == NULL)
		return ;
	ft_lst_add_front(&b, a);
	// delone on b
}