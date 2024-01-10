/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:27 by codespace         #+#    #+#             */
/*   Updated: 2024/01/10 14:42:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Initialiser le debut de la liste
// Creer une nouvelle node pour rajouter le contenu (memory allocation for the node)
// Allouer la memoire pour le nombre
// Mettre le pointeur de NULL a next newnode->next = NULL
// Et si c'est la premiere node alors set as head sinon rajouter la node a la suite

#include "../includes/push_swap.h"

void	init_stack(node_t *head, int size, char **arr)
{
	int	i;

	i = 1;
	if (size == 2)
	{
		size = get_args(arr);
		i = 0;
	}
	while (i < size)
	{
		head = malloc(sizeof(node_t));
		if (head == NULL)
			return ;
		head->content = ft_atoi(arr[i]);
		printf("%d\n", head->content);
		ft_lstnew(head);
		i++;
	}
}
