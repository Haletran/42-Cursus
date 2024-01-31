/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:09:14 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 16:47:30 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstnew(int *content)
{
	t_lst	*elem;

	elem = malloc(sizeof(t_lst));
	if (!elem)
		return (NULL);
	elem->content = *content;
	elem->next = NULL;
	return (elem);
}
