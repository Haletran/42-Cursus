#include <stdlib.h>

char *ft_strdup(char *src)
{
	int size = 0;
	for (int j = 0; src[j]; j++)
		size++;
	char *res = malloc(sizeof(res) * size + 1);
	for (int t = 0; src[t]; t++)
		res[t] = src[t];
	res[size] = '\0';
	return (res);
}
