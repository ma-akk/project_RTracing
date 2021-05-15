/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:03:40 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/11 12:33:03 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*my_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	*tmp;

	i = 0;
	result = dst;
	tmp = (unsigned char*)src;
	while (i < n)
	{
		*(result + i) = *(tmp + i);
		i++;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*result;
	unsigned const char	*tmp;

	i = 0;
	result = (unsigned char*)dst;
	tmp = (unsigned char*)src;
	if (result < tmp)
		result = my_memcpy(dst, src, len);
	else if (result == tmp || len == 0)
		return (dst);
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			*(result + i) = *(tmp + i);
		}
	}
	return (dst);
}
