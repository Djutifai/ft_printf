#include "../includes/ft_printf.h"

//static void	ft_check_flag(){}

static void	ft_xpuX(char c, va_list ap, size_t *counter, int *wid_pre)
{
	char			*strnum;

	if (c == '%')
		write(1, "%", 1);
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			ft_decToHex(va_arg(ap, unsigned int), "0123456789abcdef", counter);
		else if (c == 'X')
			ft_decToHex(va_arg(ap, unsigned int), "0123456789ABCDEF", counter);
	}
	else if (c == 'p')
		ft_printP(va_arg(ap, void *), "0123456789abcdef", counter);
	else if (c == 'u')
	{
		strnum = ft_uItoa(va_arg(ap, unsigned int), wid_pre);
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
	}
}

static	void	ft_err(void)
{
}
static void	ft_csdi(char c, va_list ap, size_t *counter, int *wid_pre)
{
	char	*strnum;
	(void)wid_pre;
	if (c == 's')
	{
		strnum = va_arg(ap, char *);
		if (!strnum)
			ft_err();
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
	}
	else if (c == 'c')
	{
		*counter += 1;
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	else if (c == 'd' || c == 'i')
	{
		strnum = ft_itoa(va_arg(ap, int));
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
	}
}

void	ft_check_flag(const char *format, va_list ap, int *wid_pre)
{
	if (*format == '*')
	{
		wid_pre[0] = va_arg(ap, int);
		format++;
	}
	//if (*format  '0')
		
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	counter;
	int		wid_pre[2];

	counter = 0;
	wid_pre[0] = -1;
	wid_pre[1] = -1;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_check_flag(format, ap, wid_pre);
			ft_xpuX(*format, ap, &counter, wid_pre);
			ft_csdi(*format, ap, &counter, wid_pre);
		}
		else
		{
			write(1, &(*format), 1);
			counter++;
		}
		format++;
	}
	va_end(ap);
	return (counter);
}
