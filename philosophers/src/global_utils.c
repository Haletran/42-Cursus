/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:35:28 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/22 17:53:12 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int			c;
	long long	e;
	char		oe;

	c = 0;
	oe = 1;
	e = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == 43 || str[c] == 45)
		if (str[c++] == 45)
			oe = -1;
	while (str[c] >= '0' && str[c] <= '9')
	{
		e = e * 10 + str[c] - '0';
		c++;
	}
	return (e * oe);
}

int	ft_isdigit(int c)
{
	if ((c >= '1' && c <= '9'))
		return (1);
	return (0);
}


int	ft_atoi_check(const char *str)
{
	int			c;
	long long	e;
	char		oe;

	c = 0;
	oe = 1;
	e = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == 43 || str[c] == 45)
		if (str[c++] == 45)
			oe = -1;
	while (str[c] >= '0' && str[c] <= '9')
	{
		e = e * 10 + str[c] - '0';
		c++;
	}
	if ((e * oe) >= INT_MAX)
		return (-1);
	return (oe);
}

void print_args(t_arg *args)
{
	printf(RED"[ NUMBERS OF PHILOSOPHERS ] :"RESET" %d\n", args->nb_philo);
	printf(YELLOW"[ TIME_TO_DIE ] :"RESET" %d\n", args->time_to_die);
	printf(BLUE"[ TIME_TO_EAT ] :"RESET" %d\n", args->time_to_eat);
	printf(MAGENTA"[ TIME_TO_SLEEP ] :"RESET" %d", args->time_to_sleep);
	if (args->must_eat)
		printf(CYAN"\n[ NBS TIME_TO_EAT ] :"RESET" %d", args->time_to_die);
	printf("\n\n - STARTING DINNER - \n");

}



int	ft_error(int choice)
{
	if (choice == 1)
		printf("\033[1m\033[31m[ Error ]\033[0m : Invalid Usage");
	else if (choice == 2)
		printf("\033[1m\033[31m[ Error ]\033[0m : Invalid Input");
	return (0);
}