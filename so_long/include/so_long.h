/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:25:27 by codespace         #+#    #+#             */
/*   Updated: 2023/12/07 17:52:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WIDTH 1000
# define HEIGHT 500
//# include <../MLX42/MLX42.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_str(char *src1, char *src2);
void	*ft_calloc(size_t elementCount, size_t elementSize);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
size_t	ft_nstrlen(const char *str);
char	*ft_free(char *buffer, char *line, char *test);
int		ft_parse(char *line);
int		ft_render(char **map);
int		ft_transform(void);
int		ft_check_validity(char **map);

#endif