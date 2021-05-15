/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:43:17 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/28 15:47:36 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_sqr	init_square(t_shape *sq)
{
	t_sqr	sqr;
	t_vect	tmp;

	sqr.centr = sq->xyz;
	tmp = init_vec(0, 1, 0);
	if (sq->v_orient.y == 1 || sq->v_orient.y == -1)
		tmp = init_vec(0, 0, 1);
	sqr.vr = norm_vec(cross_vec(sq->v_orient, tmp));
	sqr.vup = norm_vec(cross_vec(sqr.vr, sq->v_orient));
	sqr.half_side = (sq->dim) / 2;
	return (sqr);
}

int		proj_point(t_sqr *sqr, t_vect point)
{
	double p_right;
	double p_up;
	t_vect cp;

	cp = sub_vec(point, sqr->centr);
	p_right = dot_vec(cp, sqr->vr);
	p_up = dot_vec(cp, sqr->vup);
	if ((fabs(p_right) <= sqr->half_side) && (fabs(p_up) <= sqr->half_side))
		return (1);
	return (0);
}

int		intersect_ray_sq(t_ray *ray, t_shape *sq, t_inter *inter_sq)
{
	t_sqr	sqr;
	t_vect	point;

	sqr = init_square(sq);
	if (intersect_ray_pl(ray, sq, inter_sq))
	{
		point = add_vec(ray->orig, mult_vec(ray->dir, inter_sq->dist1));
		if (proj_point(&sqr, point))
			return (1);
	}
	return (0);
}
