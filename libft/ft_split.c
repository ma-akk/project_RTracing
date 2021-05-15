/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:33:16 by gtresa            #+#    #+#             */
/*   Updated: 2020/11/13 17:29:52 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**arr_alloc(char const *str, char c)
{
	int		flag;
	int		count;
	size_t	i;
	char	**strs;

	flag = 0;
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (flag == 0 && str[i] != c)
		{
			count++;
			flag = 1;
		}
		if (flag == 1 && str[i] == c)
			flag = 0;
		i++;
	}
	strs = (char**)ft_calloc((count + 1), sizeof(char*));
	return (strs);
}

static char	**arr_free(char **strs)
{
	size_t i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	input_strs(char **strs, char *tmp, int j, char c)
{
	int	count_sim;
	int	start;
	int	i;

	i = 0;
	while (*(tmp + i) != '\0')
	{
		count_sim = 0;
		start = i;
		while (*(tmp + i) != c && *(tmp + i) != '\0')
		{
			count_sim++;
			i++;
		}
		*(strs + j) = ft_substr(tmp, start, count_sim);
		if (*(strs + j) == NULL)
			return (j);
		j++;
		while (*(tmp + i) == c && *(tmp + i) != '\0')
			i++;
	}
	*(strs + j) = NULL;
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**strs;
	char	*tmp;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(strs = arr_alloc(s, c)))
		return (NULL);
	tmp = ft_strtrim(s, &c);
	j = input_strs(strs, tmp, j, c);
	if (j != 0)
	{
		arr_free(strs);
		return (NULL);
	}
	free(tmp);
	return (strs);
}
