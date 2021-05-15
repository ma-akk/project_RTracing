/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:25:15 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/11 13:04:20 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t result;

	i = ft_strlen(dst);
	result = ft_strlen(dst);
	if (dstsize > ft_strlen(dst))
	{
		j = 0;
		while (i < dstsize - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (result >= dstsize)
		result = ft_strlen(src) + dstsize;
	else
		result += ft_strlen(src);
	return (result);
}
