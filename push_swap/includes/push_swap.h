/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 18:51:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			content;
	struct node	*next;
}				node_t;

/* FUNCTIONS */
void pa(node_t **node1, node_t **node2);
void freeList(struct node* head);
int				check_input(int nb_args, char **src);
int				init_stack(node_t **head, int size, char **arr);
int				ft_error(void);
int				ft_strcmp(char *s1, char *s2);
int				get_args(char **arr);
int				verif_input(int nb_args, char **src);

/*OPERATIONS*/
void			sa(node_t **node1);
void			sb(node_t **node1);

#endif