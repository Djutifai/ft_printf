#include "../includes/ft_printf.h"

static void	ft_write_char(char c, size_t *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

static int	ft_xpX(char c, va_list ap, size_t *counter)
{
	if (c == '%')
	{
		*counter += 1;
		write(1, "%", 1);
	}
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			ft_decToHex(va_arg(ap, unsigned int), "0123456789abcdef", counter);
		else if (c == 'X')
			ft_decToHex(va_arg(ap, unsigned int), "0123456789ABCDEF", counter);
	}
	else if (c == 'p')
		ft_printP(va_arg(ap, void *), "0123456789abcdef", counter);
	if (c == '%' || c == 'x' || c == 'X' || c == 'p' || c == 'p' || c == 'u')
		return (1);
	return (0);
}

static int	ft_cs(char c, va_list ap, size_t *counter)
{
	char	*strnum;

	if (c == 's')
	{
		strnum = va_arg(ap, char *);
		if (strnum == NULL)
		{
			ft_print_null(counter);
			return (0);
		}
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
	}
	else if (c == 'c')
	{
		*counter += 1;
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	if (c == 's' || c == 'c' || c == 'd' || c == 'i')
		return (1);
	return (0);
}

static int	ft_diu(char c, va_list ap, size_t *counter)
{
	char	*strnum;

	if (c == 'd' || c == 'i')
	{
		strnum = ft_itoa(va_arg(ap, int));
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
	}
	else if (c == 'u')
	{
		strnum = ft_uItoa(va_arg(ap, unsigned int));
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
	}
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	counter;

	counter = 0;
	va_start(ap, format);
	while (*format && format)
	{
		if (*format == '%')
		{
			format++;
			if (!ft_xpX(*format, ap, &counter) && \
					!ft_cs(*format, ap, &counter) && \
					!ft_diu(*format, ap, &counter))
				ft_write_char(*format, &counter);
		}
		else
			ft_write_char(*format, &counter);
		if (*format)
			format++;
	}
	va_end(ap);
	return (counter);
}
