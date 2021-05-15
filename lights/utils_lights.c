/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:26:18 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 15:37:20 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_vect	get_vec_color(t_vect color)
{
	t_vect new_color;

	new_color.x = color.x / 255.0;
	new_color.y = color.y / 255.0;
	new_color.z = color.z / 255.0;
	return (new_color);
}

int		get_int_color(t_vect color)
{
	t_vect new_color;

	new_color.x = fmin(color.x * 255.0, 255.0);
	new_color.y = fmin(color.y * 255.0, 255.0);
	new_color.z = fmin(color.z * 255.0, 255.0);
	return (0 << 24 | ((int)new_color.x) << 16 | ((int)new_color.y) << 8 \
			| (int)new_color.z);
}

t_vect	vec_n_shape(t_inter *inter, t_ray *ray)
{
	t_vect	vn_shape;
	t_vect	opp_dir;
	t_vect	start;
	double	vpr;
	int		id;

	id = inter->close_shape->id;
	vn_shape = norm_vec(inter->close_shape->v_orient);
	if (id == ID_SP)
		vn_shape = norm_vec(sub_vec(inter->xyz, inter->close_shape->xyz));
	if (id == ID_CY)
	{
		vpr = dot_vec(sub_vec(inter->xyz, inter->close_shape->xyz), \
		inter->close_shape->v_orient);
		vn_shape = mult_vec(inter->close_shape->v_orient, vpr);
		vn_shape = norm_vec(sub_vec(sub_vec(inter->xyz, inter->close_shape->xyz), vn_shape));
	}
	opp_dir = mult_vec(ray->dir, -1);
	vpr = dot_vec(vn_shape, opp_dir);
	if (dot_vec(vn_shape, opp_dir) != 0)
		vn_shape = norm_vec(mult_vec(vn_shape, vpr));
	start = mult_vec(vn_shape, EPS);
	inter->xyz = add_vec(inter->xyz, start);
	return (vn_shape);
}
