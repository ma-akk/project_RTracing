/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:52:53 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/08 21:01:07 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	res = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(res + i) = (*f)(i, *(s + i));
		i++;
	}
	*(res + i) = '\0';
	return (res);
}
