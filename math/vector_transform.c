/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:39:32 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 17:56:25 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

double	len_vec(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vect	norm_vec(t_vect v)
{
	double v_inv;

	if (len_vec(v) == 0)
		return (v);
	v_inv = 1 / len_vec(v);
	v.x = v.x * v_inv;
	v.y = v.y * v_inv;
	v.z = v.z * v_inv;
	return (v);
}

double	dot_vec(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect	cross_vec(t_vect v1, t_vect v2)
{
	t_vect cross;

	cross.x = v1.y * v2.z - v1.z * v2.y;
	cross.y = v1.z * v2.x - v1.x * v2.z;
	cross.z = v1.x * v2.y - v1.y * v2.x;
	return (cross);
}
