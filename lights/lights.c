/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:31:07 by gtresa            #+#    #+#             */
/*   Updated: 2021/03/03 12:18:40 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_vect	diff_light(t_base *light, t_vect n, t_vect l)
{
	t_vect	l_diff;
	double	dot_nl;

	l_diff = init_vec(0, 0, 0);
	dot_nl = dot_vec(n, l);
	if (dot_nl > 0)
		l_diff = mult_vec(light->vec_rgb, light->bright * dot_nl);
	return (l_diff);
}

t_vect	spec_light(t_base *light, t_vect n, t_vect l, t_vect v)
{
	t_vect	l_spec;
	double	k_spec;
	t_vect	h;
	double	dot_nh;

	l_spec = init_vec(0, 0, 0);
	h = norm_vec(add_vec(l, v));
	dot_nh = dot_vec(n, h);
	if (dot_nh > 0)
	{
		k_spec = light->bright * pow(dot_nh, 100);
		l_spec = mult_vec(light->vec_rgb, k_spec);
	}
	return (l_spec);
}

t_vect	total_light(t_scene *scene, t_ray *ray, t_inter *inter)
{
	t_base *tmp_light;
	t_vect cur_color;
	t_vect vec_v;
	t_vect vec_l;

	vec_v = mult_vec(ray->dir, -1);
	tmp_light = scene->light;
	cur_color = mult_vec(scene->alight->vec_rgb, scene->alight->bright);
	while (scene->light != NULL)
	{
		if (dot_vec(inter->vec_n, vec_v) < 0)
			break ;
		if (!def_shadow(scene, scene->light, inter))
		{
			vec_l = norm_vec(sub_vec(scene->light->xyz, inter->xyz));
			cur_color = add_vec(cur_color, diff_light(scene->light, \
						inter->vec_n, vec_l));
			cur_color = add_vec(cur_color, \
					spec_light(scene->light, inter->vec_n, vec_l, vec_v));
		}
		scene->light = scene->light->next;
	}
	scene->light = tmp_light;
	return (cur_color);
}

int		def_shadow(t_scene *scene, t_base *light, t_inter *inter)
{
	t_ray	shadray;
	t_inter	shad_int;

	shadray = def_shadray(light, inter);
	shad_int = init_shadinter(inter, light, &shadray);
	if (trase_shadray(scene, &shadray, &shad_int))
		return (1);
	return (0);
}
