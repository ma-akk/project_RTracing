/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:04:25 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/10 22:09:05 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenstr(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	pow_ten(int len)
{
	int pow;

	pow = 1;
	if (len == 1)
		return (pow);
	while (len > 1)
	{
		pow = pow * 10;
		len--;
	}
	return (pow);
}

static void	input(long nl, int i, char *str)
{
	int div;
	int len;

	len = lenstr(nl);
	div = pow_ten(lenstr(nl));
	while (len > 1)
	{
		*(str + i) = (nl / div) + '0';
		nl = nl % div;
		div = div / 10;
		i++;
		len--;
	}
	*(str + i) = nl + '0';
	*(str + i + 1) = '\0';
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nl;

	nl = (long)n;
	i = 0;
	if (nl < 0)
	{
		nl = nl * (-1);
		if (!(str = (char*)malloc((lenstr(nl) + 2) * sizeof(char))))
			return (NULL);
		*str = '-';
		i = 1;
	}
	else if (!(str = (char*)malloc((lenstr(nl) + 1) * sizeof(char))))
		return (NULL);
	input(nl, i, str);
	return (str);
}
