/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:57:43 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/19 17:05:39 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		check_endofline(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(ft_isspace(line[i])))
			return (1);
		i++;
	}
	return (0);
}

int		skip_space(char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

int		skip_digit(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	i += skip_space(line + i);
	return (i);
}
