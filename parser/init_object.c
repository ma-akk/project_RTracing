/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:59:36 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/19 17:14:41 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_vect	init_vec(double x, double y, double z)
{
	t_vect vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_base	*init_base(unsigned char id)
{
	t_base *elem_base;

	if ((elem_base = (t_base*)malloc(sizeof(t_base))))
	{
		elem_base->id = id;
		elem_base->xyz = init_vec(0, 0, 0);
		elem_base->bright = 0;
		elem_base->color = init_vec(0, 0, 0);
		elem_base->vec_rgb = init_vec(0, 0, 0);
		elem_base->v_orient = init_vec(0, 0, 0);
		elem_base->fov = 0;
		elem_base->next = NULL;
		elem_base->transform_mat = (elem_base->id & ID_C) ? \
		unit_matrix(4, 4) : NULL;
	}
	else
		error_exit(-1);
	return (elem_base);
}

t_shape	*init_shape(unsigned char id)
{
	t_shape *shape;

	if ((shape = (t_shape*)malloc(sizeof(t_shape))))
	{
		shape->id = id;
		shape->xyz = init_vec(0, 0, 0);
		shape->dim = 0;
		shape->v_orient = init_vec(0, 0, 0);
		shape->height = 0;
		shape->pos_xyz1 = init_vec(0, 0, 0);
		shape->pos_xyz2 = init_vec(0, 0, 0);
		shape->next = NULL;
	}
	else
		error_exit(-1);
	return (shape);
}

void	add_base(t_base **base, t_base *new)
{
	new->next = *base;
	*base = new;
}

void	add_shape(t_shape **shape, t_shape *new)
{
	new->next = *shape;
	*shape = new;
}
