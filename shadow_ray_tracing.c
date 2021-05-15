/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray_trasing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:05:16 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 15:54:30 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_ray	def_shadray(t_base *light, t_inter *inter)
{
	t_ray ray;

	ray.orig = light->xyz;
	ray.dir = sub_vec(inter->xyz, light->xyz);
	ray.dir = norm_vec(ray.dir);
	return (ray);
}

t_inter	init_shadinter(t_inter *inter, t_base *light, t_ray *shadray)
{
	t_inter	shad_int;

	shad_int.close_shape = NULL;
	shad_int.vec_n = vec_n_shape(inter, shadray);
	shad_int.close_t = len_vec(sub_vec(light->xyz, inter->xyz));
	shad_int.dist1 = len_vec(sub_vec(light->xyz, inter->xyz));
	shad_int.dist2 = len_vec(sub_vec(light->xyz, inter->xyz));
	return (shad_int);
}

int		inter_shadray(t_ray *shadray, t_inter *shad_int, t_shape *shape, \
		int (f)(t_ray*, t_shape*, t_inter*))
{
	t_shape *fst_shape;

	fst_shape = shape;
	while (shape != NULL)
	{
		if ((f)(shadray, shape, shad_int))
			if (shad_int->dist1 > 0 && shad_int->dist1 < shad_int->close_t)
				return (1);
		shape = shape->next;
	}
	shape = fst_shape;
	return (0);
}

int		inter_shadray_cy(t_ray *shadray, t_inter *shad_int, t_shape *cy, \
		int (f)(t_ray*, t_shape*, t_inter*))
{
	t_shape *fst_cy;

	fst_cy = cy;
	while (cy != NULL)
	{
		if ((f)(shadray, cy, shad_int))
			if (shad_int->dist1 > 0 && shad_int->dist1 < shad_int->close_t)
				return (1);
		if (shad_int->dist2 > 0 && shad_int->dist2 < shad_int->close_t)
			return (1);
		cy = cy->next;
	}
	cy = fst_cy;
	return (0);
}

int		trase_shadray(t_scene *scene, t_ray *shadray, t_inter *close_shad)
{
	if (inter_shadray(shadray, close_shad, scene->sp, intersect_ray_sp))
		return (1);
	if (inter_shadray(shadray, close_shad, scene->pl, intersect_ray_pl))
		return (1);
	if (inter_shadray(shadray, close_shad, scene->tr, intersect_ray_tr))
		return (1);
	if (inter_shadray(shadray, close_shad, scene->sq, intersect_ray_sq))
		return (1);
	if (inter_shadray_cy(shadray, close_shad, scene->cy, intersect_ray_cy))
		return (1);
	return (0);
}
