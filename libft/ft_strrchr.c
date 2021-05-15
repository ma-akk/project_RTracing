/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:49:38 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/06 18:34:21 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*result;

	i = 0;
	c = (char)c;
	result = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			result = (char*)&s[i];
		i++;
	}
	if (s[i] == c || c == 0)
		result = (char*)&s[i];
	return (result);
}
