/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:42:46 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 20:05:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_split(char const *s, char c)
{
    char **dest;
    int d;
    char **src = (char **)s;

    d = 0;
    src = 0;
    if (!s && !c)
        return NULL;
    dest = malloc(sizeof(char**) *100);
    if (!dest)
        return NULL;
    return(dest);
}