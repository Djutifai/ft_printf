#include "../includes/myprintf.h"

void	ft_printstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
}


void	ft_decToHex(unsigned int n, char *base)
{
	unsigned int i;

	if (n >= 16)
	{
		i = n % 16;
		n = n / 16;
		ft_decToHex(n, base);
		write(1, &(base[i]), 1);
	}
	else if (n >= 0 && n < 16)
	{
		i = n % 16;
		write(1, &(base[i]), 1);
	}
}
