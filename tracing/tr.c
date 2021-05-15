/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:44:18 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 15:45:27 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_trgl	init_triangle(t_shape *tr)
{
	t_trgl trgl;

	trgl.a = tr->xyz;
	trgl.b = tr->pos_xyz1;
	trgl.c = tr->pos_xyz2;
	trgl.ab = sub_vec(trgl.b, trgl.a);
	trgl.ac = sub_vec(trgl.c, trgl.a);
	trgl.bc = sub_vec(trgl.c, trgl.b);
	trgl.s_abc = geron_square(trgl.ab, trgl.ac, trgl.bc);
	return (trgl);
}

int		compare_tr(t_trgl trgl, t_vect p)
{
	double s_pab;
	double s_pac;
	double s_pbc;
	double sum_s;

	s_pab = geron_square(trgl.ab, sub_vec(trgl.a, p), sub_vec(trgl.b, p));
	s_pac = geron_square(trgl.ac, sub_vec(trgl.a, p), sub_vec(trgl.c, p));
	s_pbc = geron_square(trgl.bc, sub_vec(trgl.b, p), sub_vec(trgl.c, p));
	sum_s = s_pab + s_pac + s_pbc;
	if ((sum_s - trgl.s_abc) < EPS)
		return (1);
	return (0);
}

int		intersect_ray_tr(t_ray *ray, t_shape *tr, t_inter *inter_tr)
{
	t_trgl trgl;
	t_vect point;

	trgl = init_triangle(tr);
	tr->v_orient = norm_vec(cross_vec(trgl.ac, trgl.ab));
	if (intersect_ray_pl(ray, tr, inter_tr))
	{
		point = add_vec(ray->orig, mult_vec(ray->dir, inter_tr->dist1));
		if (compare_tr(trgl, point))
			return (1);
	}
	return (0);
}
