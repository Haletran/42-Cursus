/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:10:24 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/02 13:06:53 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_lst *a)
{
	struct s_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	tmp->content = a->content;
	a->content = a->next->content;
	a->next->content = tmp->content;
	free(tmp);
	ft_putendl_fd("sa", 1);
}

void	sb(t_lst *b)
{
	struct s_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	tmp->content = b->content;
	b->content = b->next->content;
	b->next->content = tmp->content;
	free(tmp);
	ft_putendl_fd("sb", 1);
}

void	ss(t_lst *a, t_lst *b)
{
	struct s_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	tmp->content = b->content;
	b->content = b->next->content;
	b->next->content = tmp->content;
	free(tmp);
	tmp = malloc(sizeof(t_lst));
	tmp->content = a->content;
	a->content = a->next->content;
	a->next->content = tmp->content;
	free(tmp);
	ft_putendl_fd("ss", 1);
}
