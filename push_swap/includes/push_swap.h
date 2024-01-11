/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 18:13:31 by codespace        ###   ########.fr       */
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
void			sort_two_nodes(node_t **node1);
int				check_input(int nb_args, char **src);
int				init_stack(node_t **head, int size, char **arr);
int				ft_error(void);
int				ft_strcmp(char *s1, char *s2);
int				get_args(char **arr);
int				verif_input(int nb_args, char **src);

#endif