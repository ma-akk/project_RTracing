/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:16:50 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/09 15:42:07 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	input(char const *s, char *join, size_t i)
{
	size_t j;

	j = 0;
	while (*(s + j) != '\0')
	{
		*(join + i) = *(s + j);
		i++;
		j++;
	}
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(join = (char*)malloc(len * sizeof(char))))
		return (NULL);
	i = 0;
	i = input(s1, join, i);
	i = input(s2, join, i);
	*(join + i) = '\0';
	return (join);
}
