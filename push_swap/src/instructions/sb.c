/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:49:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 16:03:19 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// TODO: Why making sb if it is the same as sa but with b pile
void	sb(t_lst *b)
{
	struct s_lst *tmp;

	tmp = malloc(sizeof(t_lst));
	tmp->content = b->content;
	b->content = b->next->content;
	b->next->content = tmp->content;
	free(tmp);
	ft_putendl_fd("sa", 1);
}