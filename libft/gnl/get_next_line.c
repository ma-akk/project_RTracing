/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:29:48 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 15:30:56 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_rem(char **rem, char **line, char *buf)
{
	int i;

	i = 0;
	if (ft_strchr_gnl(*rem, '\n'))
	{
		while ((*rem)[i] != '\n')
			i++;
		(*rem)[i] = '\0';
		if (!(*line = ft_strdup(*rem)))
			return (-1);
		i = ft_strcpy(*rem, &(*rem)[i + 1]);
		free(buf);
		return (1);
	}
	return (0);
}

static int	read_stream(int fd, char **line, char *buf, char **rem)
{
	int byte;

	if (!(ft_strchr_gnl(*rem, '\n')))
		while ((byte = read(fd, buf, BUFFER_SIZE)))
		{
			if (byte == -1)
				return (byte);
			buf[byte] = '\0';
			if (!(*rem = ft_strjoin_gnl(*rem, buf)))
				return (-1);
			if (check_rem(&(*rem), line, buf))
				return (1);
		}
	else if (check_rem(&(*rem), line, buf))
		return (1);
	if (!(*line = ft_strdup(*rem)))
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	int			res;
	static char	*rem;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if (rem == NULL)
		if (!(rem = ft_strdup("")))
			return (-1);
	res = read_stream(fd, line, buf, &rem);
	if (res < 1)
	{
		free(rem);
		free(buf);
		rem = NULL;
	}
	return (res);
}
