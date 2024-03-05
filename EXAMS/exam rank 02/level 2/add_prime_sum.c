#include <unistd.h>

int ft_atoi(const char *str)
{
	int res = 0;
	for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++)
		res = res * 10 + str[i] - '0';
	return (res);
}

void ft_putnbr(int nbr)
{
	if (nbr > 9)
			ft_putnbr(nbr /10);
	char di = nbr % 10 + '0';
	write(1, &di, 1);
}

int isprime(int nbr)
{
	int i = 2;

	if (nbr <= 1)
			return (0);
	while(i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}


int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = ft_atoi(av[1]);
		int sum = 0;
		while (i > 0)
		{	
			if (isprime(i))
				sum += i;
			i--;
		}
		ft_putnbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

