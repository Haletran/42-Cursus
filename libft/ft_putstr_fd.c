/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:03:24 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/02 11:05:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	if (s == 0)
		return ;
	if (fd < 0 || fd > 3)
		return ;
	while (s[c] != '\0')
	{
		write(fd, &s[c], 1);
		c++;
	}
	write(1, "\n", 1);
}
