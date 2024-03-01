/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:06:12 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/01 15:02:20 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colors.h"
# include "philo.h"
# include "struct.h"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/*FUNCTIONS*/
int				ft_error(int choice);
int				checker(char **arr);
int				ft_atoi(const char *str);
int				ft_atoi_check(const char *str);
int				get_args(char **arr);
int				ft_isdigit(int c);
void			create_thread(t_table **table);
int				check_valid_time(t_table *table);
void			init_value(t_table **table, char **arr);
void			print_table(t_table *table);
void			*start_dinner(t_table **table);
void			ft_free_all(t_table **table);
void			*runtime(void *param);
int				ft_usleep(size_t milliseconds);
size_t			get_current_time(void);
unsigned long	get_time(void);

#endif
