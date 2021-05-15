/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:58:08 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/19 17:21:00 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	parser_id(char *line, t_scene *on_scene)
{
	if (line[0] == 'c' && ft_isspace(line[1]))
		return (parser_camera(line, on_scene));
	if (line[0] == 'l' && ft_isspace(line[1]))
		return (parser_light(line, on_scene));
	if (line[0] == 's' && line[1] == 'p')
		return (parser_sp(line, on_scene));
	if (line[0] == 'p' && line[1] == 'l')
		return (parser_pl(line, on_scene));
	if (line[0] == 's' && line[1] == 'q')
		return (parser_sq(line, on_scene));
	if (line[0] == 'c' && line[1] == 'y')
		return (parser_cy(line, on_scene));
	if (line[0] == 't' && line[1] == 'r')
		return (parser_tr(line, on_scene));
	if (line[0] == 'R' && ft_isspace(line[1]))
		return (parser_resol(line, on_scene));
	if (line[0] == 'A' && ft_isspace(line[1]) && !on_scene->alight)
		return (parser_alight(line, on_scene));
	return (1);
}

int	check_last_line(t_scene *on_scene, char *line, int fl)
{
	if (fl == 0 && line != NULL && line[0] != '\0')
		if ((fl = parser_id(line, on_scene)))
		{
			free(line);
			return (fl);
		}
	return (0);
}

int	parser_scene(t_scene *on_scene, int fd)
{
	char	*line;
	int		fl;

	while ((fl = get_next_line(fd, &line)) > 0)
	{
		if (!(line[0] == '\0'))
			if ((fl = parser_id(line, on_scene)))
			{
				free(line);
				return (fl);
			}
		free(line);
	}
	if (fl < 0)
		return (2);
	if ((fl = check_last_line(on_scene, line, fl)))
		return (fl);
	free(line);
	return (0);
}
