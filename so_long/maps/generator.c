/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:29:56 by codespace         #+#    #+#             */
/*   Updated: 2024/01/16 14:58:42 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 0 = empty space
// 1 = Walls (the rectangle border)
// C = Collectible (coins)
// E = map exit (appear after  collecting all the coins)
// P = player starting position

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_smap(int x, int y)
{
    int c = 0;
    int d = 0;

    // write(1, "Simple Map :\n\n", 14);
/*     if (x < y || x == y)
    {
        write(1, "Error, invalid size\n", 20);
        return;
    } */
    while (c < x)
    {
        write(1, "1", 1);
        c++;
    }
    c = 0;
    write(1, "\n", 1);
    while (c < y - 2)
    {
        write(1, "1", 1);
        d = 0;
        while (d != x - 2)
        {
            write(1, "0", 1);
            d++;
        }
        write(1, "1\n", 2);
        c++;
    }
    c = 0;
    while (c < x)
    {
        write(1, "1", 1);
        c++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        if (argv[1][0] == '1')
            generate_smap(atoi(argv[2]), atoi(argv[3]));
    }
    return (0);
}