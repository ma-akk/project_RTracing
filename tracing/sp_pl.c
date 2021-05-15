/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_pl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:49:03 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/27 22:55:34 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		intersect_ray_sp(t_ray *ray, t_shape *sp, t_inter *inter_sp)
{
	double	k2;
	double	k3;
	double	discrim;
	t_vect	sp_to_ray;

	sp_to_ray = sub_vec(ray->orig, sp->xyz);
	k2 = 2 * dot_vec(sp_to_ray, ray->dir);
	k3 = dot_vec(sp_to_ray, sp_to_ray) - (sp->dim * sp->dim) / 4;
	discrim = k2 * k2 - 4 * k3;
	if (discrim >= 0)
	{
		inter_sp->dist1 = (-k2 - sqrt(discrim)) / 2;
		inter_sp->dist2 = (-k2 + sqrt(discrim)) / 2;
		if (inter_sp->dist1 < 0 && inter_sp->dist2 > 0)
			inter_sp->dist1 = inter_sp->dist2;
		return (1);
	}
	return (0);
}

int		intersect_ray_pl(t_ray *ray, t_shape *pl, t_inter *inter_pl)
{
	double k1;
	double k2;
	t_vect pl_to_ray;

	pl_to_ray = sub_vec(ray->orig, pl->xyz);
	pl->v_orient = norm_vec(pl->v_orient);
	if (dot_vec(ray->dir, pl->v_orient) > 0)
		pl->v_orient = mult_vec(pl->v_orient, -1);
	k1 = dot_vec(pl_to_ray, pl->v_orient);
	k2 = dot_vec(ray->dir, pl->v_orient);
	if (k2 != 0)
	{
		inter_pl->dist1 = -k1 / k2;
		inter_pl->dist2 = INFINITY;
		return (1);
	}
	return (0);
}
