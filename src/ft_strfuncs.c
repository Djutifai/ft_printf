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

void	ft_ulToHex(unsigned long p)
{
	char			*str;
	unsigned long	remainder;
	unsigned long	quotient;
	size_t			i;

	i = 0;
	write(1, "0x", 2);
	remainder = p % 16;
	quotient = p / 16;
	while (quotient != 0)
	{
		//deal with it
		p = quotient;
		remainder = p % 16;
		quotient = p / 16;
	}
	ft_printstr(str);
	free(str);
}
