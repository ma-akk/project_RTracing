/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:58:31 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/19 17:25:24 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		parser_sp(char *line, t_scene *on_scene)
{
	t_shape	*newsp;
	int		i;
	int		tmp;

	i = 2;
	if (!(newsp = init_shape(ID_SP)))
		return (-1);
	i += skip_space(line + i);
	if (!(tmp = input_vec((line + i), &newsp->xyz)))
		return (1);
	i += tmp;
	newsp->dim = ft_atof(line + i);
	if (!check_value(line + i, 0))
		return (1);
	i += check_value(line + i, 0);
	if (!(parser_color(line + i, &newsp->color)))
		return (1);
	newsp->vec_rgb = get_vec_color(newsp->color);
	add_shape(&(on_scene->sp), newsp);
	return (0);
}

int		parser_pl(char *line, t_scene *on_scene)
{
	t_shape	*newpl;
	int		i;
	int		tmp;

	i = 2;
	if (!(newpl = init_shape(ID_PL)))
		return (-1);
	i += skip_space(line + i);
	if (!(tmp = input_vec((line + i), &newpl->xyz)))
		return (1);
	i += tmp;
	if (!(tmp = input_vec((line + i), &newpl->v_orient)))
		return (1);
	i += tmp;
	if (!(parser_color(line + i, &newpl->color)))
		return (1);
	newpl->vec_rgb = get_vec_color(newpl->color);
	add_shape(&(on_scene->pl), newpl);
	return (0);
}

int		parser_sq(char *line, t_scene *on_scene)
{
	int		i;
	int		tmp;
	t_shape	*newsq;

	i = 2;
	if (!(newsq = init_shape(ID_SQ)))
		return (-1);
	i += skip_space(line + i);
	if (!(tmp = input_vec((line + i), &newsq->xyz)))
		return (1);
	i += tmp;
	if (!(tmp = input_vec((line + i), &newsq->v_orient)))
		return (1);
	i += tmp;
	newsq->dim = ft_atof(line + i);
	if (!check_value(line + i, 0))
		return (1);
	i += check_value(line + i, 0);
	if (!(parser_color(line + i, &newsq->color)))
		return (1);
	newsq->vec_rgb = get_vec_color(newsq->color);
	add_shape(&(on_scene->sq), newsq);
	return (0);
}

int		parser_cy(char *line, t_scene *on_scene)
{
	int		i;
	int		tmp;
	t_shape	*newcy;

	i = 2;
	if (!(newcy = init_shape(ID_CY)))
		return (-1);
	i += skip_space(line + i);
	if (!(tmp = input_vec((line + i), &newcy->xyz)))
		return (1);
	i += tmp;
	if (!(tmp = input_vec((line + i), &newcy->v_orient)))
		return (1);
	i += tmp;
	newcy->dim = ft_atof(line + i);
	i += check_value(line + i, 0);
	newcy->height = ft_atof(line + i);
	if (!check_value(line + i, 0))
		return (1);
	i += check_value(line + i, 0);
	if (!(parser_color(line + i, &newcy->color)))
		return (1);
	newcy->vec_rgb = get_vec_color(newcy->color);
	add_shape(&(on_scene->cy), newcy);
	return (0);
}

int		parser_tr(char *line, t_scene *on_scene)
{
	int		i;
	int		tmp;
	t_shape	*newtr;

	i = 2;
	if (!(newtr = init_shape(ID_TR)))
		return (-1);
	i += skip_space(line + i);
	if (!(tmp = input_vec((line + i), &newtr->xyz)))
		return (1);
	i += tmp;
	if (!(tmp = input_vec((line + i), &newtr->pos_xyz1)))
		return (1);
	i += tmp;
	if (!(tmp = input_vec((line + i), &newtr->pos_xyz2)))
		return (1);
	i += tmp;
	if (!(parser_color(line + i, &newtr->color)))
		return (1);
	newtr->vec_rgb = get_vec_color(newtr->color);
	add_shape(&(on_scene->tr), newtr);
	return (0);
}
