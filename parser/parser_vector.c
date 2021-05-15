/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:59:00 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/19 17:17:03 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		check_value(char *line, int fl_vec)
{
	int i;

	i = 0;
	if (line[i] == '+' || line[i] == '-')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == '.')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if ((line[i] == ',' || ft_isspace(line[i])) && fl_vec == 1)
		return (i);
	if (!(ft_isspace(line[i]) || line[i] != '\0' || line[i] != '\n') && \
	fl_vec == 0)
		return (0);
	i += skip_space(line + i);
	return (i);
}

int		input_vec(char *line, t_vect *vec)
{
	int i;

	i = 0;
	vec->x = ft_atof(line + i);
	i += check_value(line + i, 1);
	if (line[i] == ',' || ft_isspace(line[i]))
	{
		i++;
		i += skip_space(line + i);
		vec->y = ft_atof(line + i);
		i += check_value(line + i, 1);
		if (line[i] == ',' || ft_isspace(line[i]))
		{
			i++;
			i += skip_space(line + i);
			vec->z = ft_atof(line + i);
			i += check_value(line + i, 0);
			return (i);
		}
	}
	return (0);
}

int		check_vec_norm(t_vect vec)
{
	if (vec.x < -1 || vec.x > 1)
		return (1);
	if (vec.y < -1 || vec.y > 1)
		return (1);
	if (vec.z < -1 || vec.z > 1)
		return (1);
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return (1);
	return (0);
}
