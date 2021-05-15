/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:19:16 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/11 12:24:58 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	*tmp;

	i = 0;
	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	result = dst;
	tmp = (unsigned char*)src;
	while (i < n && *tmp != '\0')
	{
		*(result + i) = *(tmp + i);
		i++;
	}
	return (dst);
}
