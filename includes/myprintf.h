#ifndef MYPRINTF_H
# define MYPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
void	ft_printstr(char *str);
void	ft_decToHex(unsigned int n, char *base);

#endif
