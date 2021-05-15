/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:58:46 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/19 16:58:51 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		check_rgb(char *line, double *color)
{
	*color = (ft_isdigit(line[0])) ? ft_atof(line) : -1;
	if (*color < 0.0 || *color > 255.0)
		*color = -1;
	return (0);
}

int		parser_color(char *line, t_vect *new_color)
{
	int i;

	i = 0;
	check_rgb(line + i, &new_color->x);
	i += skip_digit(line + i);
	if (line[i] == ',')
		i++;
	i += skip_space(line + i);
	check_rgb(line + i, &new_color->y);
	i += skip_digit(line + i);
	if (line[i] == ',')
		i++;
	i += skip_space(line + i);
	check_rgb(line + i, &new_color->z);
	i += skip_digit(line + i);
	if (new_color->x == -1 || new_color->y == -1 || new_color->z == -1 \
	|| check_endofline(line + i))
		return (0);
	return (1);
}
