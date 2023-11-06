/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:30 by bapasqui          #+#    #+#             */
/*   Updated: 2023/10/31 19:05:10 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list* tmp = malloc(sizeof(t_list));
    if (!tmp)
        return NULL;
    lst->next = tmp;
    return tmp;
}