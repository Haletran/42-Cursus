/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:58:02 by bapasqui          #+#    #+#             */
/*   Updated: 2024/02/07 16:42:55 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LST_H
# define T_LST_H

typedef struct s_lst
{
	int				content;
	int	index;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

#endif