/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:48:38 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/27 22:55:32 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		point_in_height(t_inter *inter, t_shape *cy, t_ray *ray)
{
	t_vect	point;
	double	vpr_xyz;

	point = add_vec(ray->orig, mult_vec(ray->dir, inter->dist1));
	vpr_xyz = dot_vec(sub_vec(point, cy->xyz), cy->v_orient);
	if (vpr_xyz < 0 || vpr_xyz > cy->height)
		return (0);
	return (1);
}

int		trim_cy(t_inter *inter, t_shape *cy, t_ray *ray)
{
	double tmp;

	if (inter->dist1 > inter->dist2)
	{
		tmp = inter->dist1;
		inter->dist1 = inter->dist2;
		inter->dist2 = tmp;
	}
	if (inter->dist1 < 0 || !point_in_height(inter, cy, ray))
	{
		inter->dist1 = inter->dist2;
		inter->dist2 = -1;
		if (inter->dist1 < 0 || !point_in_height(inter, cy, ray))
			return (0);
	}
	inter->dist2 = -1;
	return (1);
}

int		quadratic_cy(t_inter *inter, double k1, double k2, double k3)
{
	double discrim;
	double q;

	discrim = k2 * k2 - 4 * k1 * k3;
	if (discrim < 0)
		return (0);
	if (discrim == 0)
	{
		inter->dist1 = -0.5 * k2 / k1;
		inter->dist2 = -0.5 * k2 / k1;
	}
	if (discrim > 0)
	{
		if (k2 > 0)
			q = -0.5 * (k2 + sqrt(discrim));
		else
			q = -0.5 * (k2 - sqrt(discrim));
		inter->dist1 = q / k1;
		inter->dist2 = k3 / q;
	}
	return (1);
}

int		intersect_ray_cy(t_ray *ray, t_shape *cy, t_inter *inter_cy)
{
	double k1;
	double k2;
	double k3;
	t_vect vpr_point;
	t_vect vpr_cy_to_ray;

	cy->v_orient = norm_vec(cy->v_orient);
	vpr_point = sub_vec(ray->dir, mult_vec(cy->v_orient, \
				dot_vec(cy->v_orient, ray->dir)));
	vpr_cy_to_ray = sub_vec(sub_vec(ray->orig, cy->xyz), \
			mult_vec(cy->v_orient, dot_vec(cy->v_orient, \
			sub_vec(ray->orig, cy->xyz))));
	k1 = dot_vec(vpr_point, vpr_point);
	k2 = 2.0 * dot_vec(vpr_point, vpr_cy_to_ray);
	k3 = dot_vec(vpr_cy_to_ray, vpr_cy_to_ray) - pow(cy->dim, 2) / 4;
	if (quadratic_cy(inter_cy, k1, k2, k3))
		if (trim_cy(inter_cy, cy, ray))
			return (1);
	return (0);
}
