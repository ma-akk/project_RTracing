/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:27:54 by gtresa            #+#    #+#             */
/*   Updated: 2020/12/10 19:00:28 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
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
	return (NULL);
}

size_t	ft_strcpy(char *dst, char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst));
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		*(s + i) = *(s1 + i);
		i++;
	}
	*(s + i) = '\0';
	return (s);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(join = (char*)malloc(len * sizeof(char))))
		return (NULL);
	i = ft_strcpy(join, s1);
	while (*(s2 + j) != '\0')
	{
		*(join + i) = *(s2 + j);
		i++;
		j++;
	}
	free(s1);
	*(join + i) = '\0';
	return (join);
}
