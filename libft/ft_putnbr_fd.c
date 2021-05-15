/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:26:08 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/07 20:22:15 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_sign(char *str, int nb)
{
	if (nb == -2147483648)
	{
		str[0] = '-';
		str[1] = '8';
		nb = -214748364;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		str[0] = '-';
	}
	else
		str[0] = '+';
	return (nb);
}

static void	print_char(char *str, int i, int fd)
{
	if (str[0] == '-')
		write(fd, &str[0], 1);
	while (i >= 1)
	{
		write(fd, &str[i], 1);
		i--;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		digit;
	char	str[12];

	i = 1;
	if (n == -2147483648)
		i = 2;
	n = nb_sign(str, n);
	while (n / 10 >= 1)
	{
		digit = n % 10;
		str[i] = digit + '0';
		i++;
		n = n / 10;
	}
	str[i] = n + '0';
	print_char(str, i, fd);
}
