/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:18:10 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/04 18:49:51 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H


/*LIBRAIRIES*/
#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, free
#include <unistd.h>     // write, access, close, fork, execve, dup, dup2, pipe
#include <fcntl.h>      // open
#include <sys/types.h>  // wait, waitpid, wait3, wait4, signal, sigemptyset, sigaddset, kill
#include <signal.h>     // sigaction
#include <errno.h>      // strerror, perror
#include <dirent.h>     // opendir, readdir, closedir
#include <string.h>     // strerror
#include <sys/stat.h>   // stat, lstat, fstat
#include <unistd.h>     // unlink, chdir, getcwd
#include <termios.h>    // tcsetattr, tcgetattr
#include <curses.h>     // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <sys/ioctl.h>  // ioctl
#include <limits.h>     // PATH_MAX
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"



/*FUNCTIONS*/
void exec();



#endif