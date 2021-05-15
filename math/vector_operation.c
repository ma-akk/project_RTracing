/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:37:02 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 17:58:15 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_vect	add_vec(t_vect v1, t_vect v2)
{
	t_vect vec_add;

	vec_add.x = v1.x + v2.x;
	vec_add.y = v1.y + v2.y;
	vec_add.z = v1.z + v2.z;
	return (vec_add);
}

t_vect	sub_vec(t_vect v1, t_vect v2)
{
	t_vect vec_sub;

	vec_sub.x = v1.x - v2.x;
	vec_sub.y = v1.y - v2.y;
	vec_sub.z = v1.z - v2.z;
	return (vec_sub);
}

t_vect	mult_vec_vec(t_vect v1, t_vect v2)
{
	t_vect mult;

	mult.x = v1.x * v2.x;
	mult.y = v1.y * v2.y;
	mult.z = v1.z * v2.z;
	return (mult);
}

t_vect	mult_vec(t_vect v, double num)
{
	t_vect mult;

	mult.x = v.x * num;
	mult.y = v.y * num;
	mult.z = v.z * num;
	return (mult);
}

double	geron_square(t_vect ab, t_vect ac, t_vect bc)
{
	double p;
	double s;

	p = 0.5 * (len_vec(ab) + len_vec(ac) + len_vec(bc));
	s = sqrt(p * (p - len_vec(ab)) * (p - len_vec(ac)) * (p - len_vec(bc)));
	return (s);
}
