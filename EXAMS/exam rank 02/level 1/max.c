int max(int *tab, unsigned int len)
{
	unsigned int i = 0;
	int res = 0;

	while (i < len)
	{
		if (res < tab[i])
				res = tab[i];
		i++;
	}
	return (res);
}
