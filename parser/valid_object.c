/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:59:54 by gtresa            #+#    #+#             */
/*   Updated: 2021/03/04 13:01:44 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int	valid_cam_light(t_scene *on_scene)
{
	t_base *tmp_base;

	if (on_scene->light != NULL)
	{
		tmp_base = on_scene->light;
		while (tmp_base != NULL)
		{
			if (tmp_base->bright < 0 || tmp_base->bright > 1)
				return (1);
			tmp_base = tmp_base->next;
		}
	}
	tmp_base = on_scene->cam;
	while (tmp_base != NULL)
	{
		if (check_vec_norm(tmp_base->v_orient))
			return (1);
		if (tmp_base->fov < 0 || tmp_base->fov > 180)
			return (1);
		tmp_base = tmp_base->next;
	}
	return (0);
}

int	valid_base(t_scene *on_scene)
{
	if (on_scene->cam == NULL || on_scene->alight == NULL || \
	on_scene->width < 1 || on_scene->height < 1)
		return (1);
	if (on_scene->alight->bright < 0 || on_scene->alight->bright > 1)
		return (1);
	return (valid_cam_light(on_scene));
}

int	valid_sp_pl(t_scene *on_scene)
{
	t_shape *tmp_shape;

	tmp_shape = on_scene->sp;
	while (tmp_shape != NULL)
	{
		if (tmp_shape->dim < 0)
			return (1);
		tmp_shape = tmp_shape->next;
	}
	tmp_shape = on_scene->pl;
	while (tmp_shape != NULL)
	{
		if (check_vec_norm(tmp_shape->v_orient))
			return (1);
		tmp_shape = tmp_shape->next;
	}
	return (0);
}

int	valid_shape(t_scene *on_scene)
{
	t_shape *tmp_shape;

	tmp_shape = on_scene->cy;
	while (tmp_shape != NULL)
	{
		if (check_vec_norm(tmp_shape->v_orient) || \
		tmp_shape->dim < 0 || tmp_shape->height < 0)
			return (1);
		tmp_shape = tmp_shape->next;
	}
	tmp_shape = on_scene->sq;
	while (tmp_shape != NULL)
	{
		if (check_vec_norm(tmp_shape->v_orient) || tmp_shape->dim < 0)
			return (1);
		tmp_shape = tmp_shape->next;
	}
	return (valid_sp_pl(on_scene));
}
