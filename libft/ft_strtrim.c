/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:22:03 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/13 17:45:20 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*res;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	if (set && s1)
	{
		while (s1[i] != 0 && ft_strchr(set, s1[i]))
			i++;
		start = i;
		while (len > start && ft_strchr(set, s1[len - 1]))
			len--;
	}
	res = ft_substr(s1, start, len - start);
	return (res);
}
