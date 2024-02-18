/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/02/18 19:11:48 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "t_lst.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* FUNCTIONS */
void	radix_sort(t_lst **a, t_lst **b);
void	ft_free(t_lst **a, t_lst **b, int size, char **arr);
t_lst	*init_stack(t_lst *a, int size, char **arr, int flag);
int		ft_error(void);
int		ft_strcmp(char *s1, char *s2);
int		get_args(char **arr);
void	print_list(char *string, t_lst *lst);
int		is_sorted_list(t_lst **a);
void	index_list(t_lst *stack, int index);
int		is_sorted_list(t_lst **a);
void	choose_sort(t_lst **a, t_lst **b, int size, int flag);

/*PARSING*/
int global_check(int size, int flag, char **src);
long long	ft_atoi_max(const char *str, int flag);
int	check_list(int nb_args, int flag, char **src);
int	check_input(int nb_args, int flag, char **src);
int	ft_isabove(char **src);

/*OPERATIONS*/
void	sa(t_lst **a);
void	sb(t_lst **b);
void	ss(t_lst **a, t_lst **b);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rra(t_lst **a);
void	rrb(t_lst **a);

#endif
