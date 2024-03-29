/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:22:04 by bapasqui          #+#    #+#             */
/*   Updated: 2024/01/10 14:50:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
