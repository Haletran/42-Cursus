/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:27:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/09 18:01:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst_stack
{
	int					content;
	struct s_lst_stack	*next;
	struct s_lst_stack	*prev;
}						t_lst_stack;

/* FUNCTIONS */
int	valid_input(int nb_args, char **src);
int						check_input(int nb_args, char **src);

#endif