/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 12:34:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int					content;
	struct s_lst_stack	*next;
	struct s_lst_stack	*prev;
}						node_t;

/* FUNCTIONS */
void					init_stack(node_t *node, int size, char **arr);
int						ft_error(void);
int						ft_strcmp(char *s1, char *s2);
int						get_args(char **arr);
int						verif_input(int nb_args, char **src);

#endif