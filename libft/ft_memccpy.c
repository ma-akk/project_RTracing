/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:56:38 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/04 21:30:53 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	*tmp;

	i = 0;
	c = (unsigned char)c;
	result = &dst[0];
	tmp = (unsigned char*)src;
	while (i < n && *tmp != '\0')
	{
		*(result + i) = *(tmp + i);
		if (*(tmp + i) == c)
		{
			result = (result + i + 1);
			return (result);
		}
		i++;
	}
	return (NULL);
}
