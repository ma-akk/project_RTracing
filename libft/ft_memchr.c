/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:24:26 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/06 17:13:30 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*result;

	c = (unsigned char)c;
	i = 0;
	result = (unsigned char*)s;
	while (i < n)
	{
		if (*(result + i) == c)
			return (result + i);
		i++;
	}
	return (NULL);
}
