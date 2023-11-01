/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:40:33 by bapasqui          #+#    #+#             */
/*   Updated: 2023/11/01 19:49:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

typedef unsigned long t_size_t;

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int ft_isprint(int c);
t_size_t	ft_strlen(const char *str);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strchr(const char *str, int to_find);
int	ft_atoi(char *str);
t_size_t ft_strlcpy(char *dest, const char *src, size_t size);
void * ft_memset(void * pointer, int value, size_t count);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t size);
void *ft_memmove(void *dest, const void *src, size_t size);
void *ft_memchr(const void * mem, int srh, size_t size);
char *ft_strdup(const char *src);
void ft_putchar_fd(char d, int fd);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
int ft_strncmp(const char *first, const char * second, size_t lenght);
size_t ft_strlcat(char *dst, const char *src, size_t size);


#endif



