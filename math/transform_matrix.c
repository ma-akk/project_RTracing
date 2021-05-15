/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:38:46 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 17:54:50 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

static void	add_str_mat(t_vect str, int n, t_base *cam)
{
	cam->transform_mat[n][0] = str.x;
	cam->transform_mat[n][1] = str.y;
	cam->transform_mat[n][2] = str.z;
	if (n == 2)
	{
		n++;
		cam->transform_mat[n][0] = cam->xyz.x;
		cam->transform_mat[n][1] = cam->xyz.y;
		cam->transform_mat[n][2] = cam->xyz.z;
	}
}

void		transform_mat(t_base *cam)
{
	t_vect	tmp;
	t_vect	v_r;
	t_vect	v_up;
	t_vect	v_dir;

	tmp = init_vec(0, 1, 0);
	v_r = init_vec(1, 0, 0);
	v_dir = norm_vec(mult_vec(cam->v_orient, -1));
	if (!(v_dir.y == 1 || v_dir.y == -1))
		v_r = cross_vec(tmp, v_dir);
	v_up = norm_vec(cross_vec(v_dir, norm_vec(v_r)));
	add_str_mat(v_r, 0, cam);
	add_str_mat(v_up, 1, cam);
	add_str_mat(v_dir, 2, cam);
}
