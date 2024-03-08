/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:18:10 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/08 10:25:57 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*LIBRAIRIES*/
# include "../libft/libft.h"
# include <curses.h> // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <dirent.h> // opendir, readdir, closedir
# include <errno.h>  // strerror, perror
# include <fcntl.h>  // open
# include <limits.h> // PATH_MAX
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>    // sigaction
# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free
# include <string.h>    // strerror
# include <sys/ioctl.h> // ioctl
# include <sys/stat.h>  // stat, lstat, fstat
# include <sys/types.h> // wait, waitpid, wait3, wait4, signal, sigemptyset,
# include <sys/wait.h>
# include <termios.h> // tcsetattr, tcgetattr
# include <unistd.h>  // write, access, close, fork, execve, dup, dup2, pipe
# include <unistd.h>  // unlink, chdir, getcwd

static int	g_value = 0;

/*STRUCTURES*/
typedef struct s_lst
{
	char	*home_path;
	char	*current_path;
	char	*env_path;
	char	*username;
	char	*prompt;
	char	**env_var;
	int		exit_code;
}			t_lst;

/*FUNCTIONS*/
void ft_export(char **envp, char **str);
int			ft_exit(t_lst *args);
void	ft_env(char **envp, char **str);
char		*ft_join(char *s1, char *s2);
void		free_list(t_lst **lst);
void		free_tab(char **str);
int			exec(char **str, t_lst *args);
void		print_commands(char **src);
int			check_commands(char **str, t_lst *args);
int			ft_echo(char **str);
int			ft_cd(char **str, t_lst *lst);
int			get_nbargs(char **str);
char		*strjoin(char *s1, char *s2);
void		init_lst(t_lst **args, char **envp);
void		get_exit_code(t_lst *args);
void		print_commands(char **src);
int			get_len(char **str);
/* FUNCTIONS */
void		signal_handler(int signalNum);

#endif