/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 19:12:07 by bapasqui         ###   ########.fr       */
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
void	freeList(struct s_lst *head);
int		check_input(int nb_args, char **src);
t_lst	*init_stack(t_lst *a, int size, char **arr);
int		ft_error(void);
int		ft_strcmp(char *s1, char *s2);
int		get_args(char **arr);
int		verif_input(int nb_args, char **src);
void	sort_small_stack(t_lst *a, t_lst *b);
void	sort_big_stack(t_lst *a, t_lst *b);

/*OPERATIONS*/
void	sa(t_lst *a);
void	sb(t_lst *b);

#endif
