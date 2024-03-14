/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:54:32 by bapasqui          #+#    #+#             */
/*   Updated: 2024/03/14 11:15:26 by bapasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_split2(char *str, char *delim)
{
	int		num_words;
	char	**words;

	int i, j, k;
	num_words = 0;
	char *start, *end;
	i = 0;
	while (str[i] != '\0')
	{
		if (strstr(&str[i], delim) == &str[i])
		{
			i += ft_strlen(delim);
		}
		else if (str[i] != '\0')
		{
			num_words++;
			while (str[i] != '\0' && strstr(&str[i], delim) != &str[i])
			{
				i++;
			}
		}
	}
	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}
	i = 0;
	j = 0;
	while (j < num_words)
	{
		while (str[i] != '\0' && strstr(&str[i], delim) == &str[i])
		{
			i += ft_strlen(delim);
		}
		start = &str[i];
		while (str[i] != '\0' && strstr(&str[i], delim) != &str[i])
		{
			i++;
		}
		end = &str[i];
		k = end - start;
		words[j] = (char *)malloc((k + 1) * sizeof(char));
		if (words[j] == NULL)
		{
			return (NULL);
		}
		strncpy(words[j], start, k);
		words[j][k] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}

/* void *piping(char **tab, t_lst *args)
{



	
} */




int	exec_pipe(char **str, t_lst *args)
{
	int		i;
	char	**tab;

	i = 0;
	(void)args;
	while (str[i])
	{
		tab = ft_split(str[i], ' ');
		//piping(tab, args);
		i++;
		// exec(tab, args);
	}
	//print_commands(tab);
	free_tab(tab);
	tab = NULL;
	return (0);
}
