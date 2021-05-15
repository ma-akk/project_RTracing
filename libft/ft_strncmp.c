/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:27:33 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/09 12:21:01 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	max_len;
	int		res;

	i = 0;
	max_len = ft_strlen(s1);
	if (ft_strlen(s1) < ft_strlen(s2))
		max_len = ft_strlen(s2);
	while (i < n && i < max_len)
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			res = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (res);
		}
	}
	return (0);
}
