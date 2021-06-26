/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:45:55 by ftassada          #+#    #+#             */
/*   Updated: 2021/06/26 20:04:19 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_recursion(char **res, unsigned int n)
{
	char	divdigit;

	if (n >= 10)
	{
		divdigit = (n % 10) + 48;
		n = n / 10;
		ft_recursion(res, n);
		*(*res)++ = divdigit;
	}
	else if (n >= 0 && n <= 9)
	{
		divdigit = n + 48;
		*(*res)++ = divdigit;
	}
}

static	int	ft_count_digits(unsigned int n)
{
	int	res;

	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	if (res == 0)
		return (1);
	return (res);
}

char	*ft_uItoa(unsigned int n, int *wid_pre)
{
	char	*res;
	int		digits;
	(void)wid_pre;

	digits = ft_count_digits(n);
	res = (char *)ft_calloc(digits + 1, sizeof(*res));
	if (!res)
		return (NULL);
	ft_recursion(&res, n);
	*res = '\0';
	return (res - digits);
}
