/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:27:19 by bapasqui          #+#    #+#             */
/*   Updated: 2024/04/18 13:27:27 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(const char *str)
{
	int		c;
	int		d;
	int		e;
	char	oe;

	c = 0;
	oe = 1;
	d = 0;
	e = 0;
	if (!str)
		return (0);
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == 43 || str[c] == 45)
	{
		if (str[c] == 45)
			d++;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		e = e * 10 + str[c] - '0';
		c++;
	}
	if (d == 1)
		oe = -1;
	return (e * oe);
}