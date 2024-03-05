/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:18:10 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/05 13:13:37 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*STRUCTURES*/

typedef struct s_args
{
    int test;

}		t_args;

/*LIBRAIRIES*/
# include "../libft/libft.h"
# include <curses.h> // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <dirent.h> // opendir, readdir, closedir
# include <errno.h> // strerror, perror
# include <fcntl.h> // open
# include <limits.h> // PATH_MAX
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h> // sigaction
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <string.h> // strerror
# include <sys/ioctl.h> // ioctl
# include <sys/stat.h> // stat, lstat, fstat
# include <sys/types.h> // wait, waitpid, wait3, wait4, signal, sigemptyset,
# include <sys/wait.h>
# include <termios.h> // tcsetattr, tcgetattr
# include <unistd.h> // write, access, close, fork, execve, dup, dup2, pipe
# include <unistd.h> // unlink, chdir, getcwd

/*FUNCTIONS*/
int		exec(char **str);
void	print_commands(char **src);
int		check_commands(char **str);

#endif