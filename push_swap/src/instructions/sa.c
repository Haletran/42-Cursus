/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:45:47 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 15:47:22 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_lst *a)
{
	struct s_lst *tmp;

	tmp = malloc(sizeof(t_lst));
	tmp->content = a->content;
	a->content = a->next->content;
	a->next->content = tmp->content;
	free(tmp);
	ft_putendl_fd("sa", 1);
}