/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:15:53 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/09 12:58:26 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	c = (char)c;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return ((char*)(s + i));
			i++;
		}
	if (s[i] == c || c == '\0')
		return ((char*)(s + i));
	return (NULL);
}
