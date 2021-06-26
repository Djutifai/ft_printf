#include "../includes/myprintf.h"

//static void	ft_check_flag(){}

static void ft_xpuX(char c, va_list ap)
{
	unsigned int	n;
	size_t		p;
	char		*strnum;

	if (c == '%')
		write(1, "%", 1);
	else if (c == 'x' || c == 'X')
	{
		n = va_arg(ap, unsigned int);
		if (c == 'x')
			ft_decToHex(n, "0123456789abcdef");
		else if (c == 'X')
			ft_decToHex(n, "0123456789ABCDEF");
	}
	else if (c == 'p')
	{
		p = (size_t)va_arg(ap, void*);
		write(1, "0x", 2);
		ft_decToHex(p, "0123456789abcdef");
	}
	else if (c == 'u')
	{
		n = va_arg(ap, unsigned int);
		strnum = ft_itoa(n);
		ft_printstr(strnum);
		free(strnum);
	}

}
static void ft_csdi(char c, va_list ap)
{
	int		i;
	char	ch;
	char	*strnum;

	if (c == 's')
	{
		strnum = va_arg(ap, char *);
		ft_printstr(strnum);
	}
	else if (c == 'c')
	{
		ch = (char)va_arg(ap, int);
		write(1, &ch, 1);
	}
	else if (c == 'd' || c == 'i')
	{
		i = va_arg(ap, int);
		strnum = ft_itoa(i);
		ft_printstr(strnum);
		free(strnum);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_xpuX(*format, ap);
			ft_csdi(*format, ap);
			//ft_check_flag(*format);
			//ft_check_flag(*format, ap);
		}
		else
			write(1, &(*format), 1);
		format++;
	}
	va_end(ap);
	return (1);
}
