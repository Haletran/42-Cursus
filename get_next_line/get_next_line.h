/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:36:52 by bapasqui          #+#    #+#             */
/*   Updated: 2023/12/07 17:54:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_str(char *src1, char *src2);
void	*ft_calloc(size_t elementCount, size_t elementSize);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
size_t	ft_nstrlen(const char *str);
char	*ft_free(char *buffer, char *line);

#endif
