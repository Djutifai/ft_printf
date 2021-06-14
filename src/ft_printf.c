#include "../includes/myprintf.h"

//static void	ft_check_flag(){}

static void ft_xpux(char c, va_list ap)
{
	//int		i;
	//char			ch;
	//char			*str;
	unsigned long	p;

	if (c == '%')
		write(1, "%", 1);
	else if (c == 'p')
	{
		p = va_arg(ap, unsigned long);
		ft_ulToHex(p);
	}

}
static void ft_csdi(char c, va_list ap)
{
	int		i;
	char	ch;
	char	*str;

	if (c == 's')
	{
		str = va_arg(ap, char *);
		ft_printstr(str);
	}
	else if (c == 'c')
	{
		ch = (char)va_arg(ap, int);
		write(1, &ch, 1);
	}
	else if (c == 'd' || c == 'i')
	{
		i = va_arg(ap, int);
		str = ft_itoa(i);
		ft_printstr(str);
		free(str);
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
			ft_xpux(*format, ap);
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
