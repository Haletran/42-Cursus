/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/30 16:14:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	int			content;
	struct node	*next;
}				t_lst;

/* FUNCTIONS */
void pa(t_lst **node1, t_lst **node2);
void freeList(struct node* head);
int				check_input(int nb_args, char **src);
int				init_stack(t_lst **head, int size, char **arr);
int				ft_error(void);
int				ft_strcmp(char *s1, char *s2);
int				get_args(char **arr);
int				verif_input(int nb_args, char **src);

/*OPERATIONS*/
void			sa(t_lst **node1);
void			sb(t_lst **node1);

#endif