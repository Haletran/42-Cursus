/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 14:32:00 by bapasqui         ###   ########.fr       */
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
int		check_input(int nb_args, char **src);
t_lst	*init_stack(t_lst *a, int size, char **arr, int count);
int		ft_error(void);
int		ft_strcmp(char *s1, char *s2);
int		get_args(char **arr);
int		verif_input(int nb_args, char **src);
void	print_list(char *string, t_lst *lst);
int		is_sorted_list(t_lst **a);
void	index_list(t_lst *stack, int index);
void	*ft_lst_new(int content, int index);
int		is_sorted_list(t_lst **a);
void	choose_sort(t_lst **a, t_lst **b, int size);

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
