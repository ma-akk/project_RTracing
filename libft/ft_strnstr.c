/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:43:42 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/09 15:07:02 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	check_str(const char *sh, const char *sn, size_t l, size_t i)
{
	size_t j;
	size_t start;

	while (sh[i] != '\0' && i < l)
	{
		j = 0;
		if (sh[i] == sn[j] && sn != NULL)
		{
			start = i;
			while (sh[i] == sn[j] && sh[i] != '\0' && i < l)
			{
				j++;
				i++;
			}
			if (sn[j] == '\0')
				return (start + 1);
		}
		else
			i++;
	}
	return (0);
}

char			*ft_strnstr(const char *hstack, const char *needle, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (needle == NULL)
		return (NULL);
	i = check_str(hstack, needle, len, i);
	if (needle[0] == '\0')
		i = 0;
	else if (i == 0)
		return (NULL);
	else
		i--;
	result = (char*)&hstack[i];
	return (result);
}
