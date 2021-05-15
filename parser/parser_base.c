/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:58:22 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/19 17:20:57 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		parser_resol(char *line, t_scene *on_scene)
{
	int i;

	i = 1;
	i += skip_space(line + i);
	if (!(on_scene->width > 1 || on_scene->height > 1))
	{
		on_scene->width = ft_atoi(line + i);
		i += skip_digit(line + i);
		on_scene->height = ft_atoi(line + i);
		on_scene->img_rat = (double)on_scene->width / (double)on_scene->height;
		i += skip_digit(line + i);
		return (check_endofline(line + i));
	}
	return (1);
}

int		parser_alight(char *line, t_scene *on_scene)
{
	int i;

	i = 1;
	i += skip_space(line + i);
	if (!(on_scene->alight = init_base('A')))
		return (-1);
	on_scene->alight->bright = ft_atof(line + i);
	if (!check_value(line + i, 0))
		return (1);
	i += check_value(line + i, 0);
	if (!(parser_color(line + i, &on_scene->alight->color)))
		return (1);
	on_scene->alight->vec_rgb = get_vec_color(on_scene->alight->color);
	return (0);
}

int		parser_camera(char *line, t_scene *on_scene)
{
	t_base	*newcam;
	int		tmp;
	int		i;

	i = 1;
	if (!(newcam = init_base(ID_C)))
		return (-1);
	i += skip_space(line + i);
	if (!(tmp = input_vec((line + i), &newcam->xyz)))
		return (1);
	i += tmp;
	if (!(tmp = input_vec((line + i), &newcam->v_orient)))
		return (1);
	i += tmp;
	newcam->fov = ft_atof(line + i);
	if (!check_value(line + i, 0))
		return (1);
	i += check_value(line + i, 0);
	add_base(&on_scene->cam, newcam);
	newcam = NULL;
	return (check_endofline(line + i));
}

int		parser_light(char *line, t_scene *on_scene)
{
	t_base	*newl;
	int		i;

	i = 1;
	if (!(newl = init_base(ID_L)))
		return (-1);
	i += skip_space(line + i);
	if (!(input_vec((line + i), &newl->xyz)))
		return (1);
	i += input_vec((line + i), &newl->xyz);
	newl->bright = ft_atof(line + i);
	if (!check_value(line + i, 0))
		return (1);
	i += check_value(line + i, 0);
	if (!(parser_color(line + i, &newl->color)))
		return (1);
	newl->vec_rgb = get_vec_color(newl->color);
	add_base(&on_scene->light, newl);
	return (0);
}
