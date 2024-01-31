/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 23:53:32 by baptiste         ###   ########.fr       */
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
void	pa(t_lst **node1, t_lst **node2);
void	ft_free(t_lst *a, char **arr);
int		check_input(int nb_args, char **src);
t_lst	*init_stack(t_lst *a, int size, char **arr, int count);
int		ft_error(void);
int		ft_strcmp(char *s1, char *s2);
int		get_args(char **arr);
int		verif_input(int nb_args, char **src);
void	sort_small_stack(t_lst *a, t_lst *b);
void	sort_big_stack(t_lst *a, t_lst *b);
void	print_list(t_lst *lst);

/*OPERATIONS*/
void	sa(t_lst *a);
void	sb(t_lst *b);

#endif
