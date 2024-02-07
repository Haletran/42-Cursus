/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 14:54:39 by bapasqui         ###   ########.fr       */
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
void	ft_free(t_lst **a, t_lst **b, int size, char **arr);
int		check_input(int nb_args, char **src);
t_lst	*init_stack(t_lst *a, int size, char **arr, int count);
int		ft_error(void);
int		ft_strcmp(char *s1, char *s2);
int		get_args(char **arr);
int		verif_input(int nb_args, char **src);
void	sort_small_stack(t_lst **a, t_lst **b, int size, int count);
void	sort_big_stack(t_lst **a, t_lst **b);
void	print_list(char *string, t_lst *lst);
int		is_sorted_list(t_lst **a);
void	sort_medium_stack(t_lst **a, t_lst **b, int size, int count);
void radix_sort(t_lst **a, t_lst **b);

/*OPERATIONS*/
void	sa(t_lst *a);
void	sb(t_lst *b);
void	ss(t_lst *a, t_lst *b);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);
t_lst	*ra(t_lst *a);
t_lst	*rb(t_lst *b);
t_lst	*rra(t_lst *a);
t_lst	*rrb(t_lst *b);

#endif
