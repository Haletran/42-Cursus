/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:10:28 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/05 20:19:17 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_cd(char **str)
{
    print_commands(str);
    char *path;
    char **split_path = malloc(100);
    //*split_path = malloc(100);
    path = getenv("PWD");
    printf("%s\n", path);

    if (!str[1][0])
    {
        split_path = ft_split(path, '/');
        printf("%s", path);
    }
    return (0);
}