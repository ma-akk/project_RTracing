/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:56:40 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 17:59:39 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

double	**unit_matrix(int n, int m)
{
	int		i;
	int		j;
	double	**unit;

	if ((unit = (double**)mat_alloc(n, m)))
	{
		i = -1;
		while (++i < n)
		{
			j = -1;
			while (++j < m)
				unit[i][j] = (i == j) ? 1 : 0;
		}
	}
	return (unit);
}

t_vect	mult_mat_vec3(double **mat, t_vect v)
{
	t_vect mult;

	mult.x = v.x * mat[0][0] + v.y * mat[1][0] + v.z * mat[2][0];
	mult.y = v.x * mat[0][1] + v.y * mat[1][1] + v.z * mat[2][1];
	mult.z = v.x * mat[0][2] + v.y * mat[1][2] + v.z * mat[2][2];
	return (mult);
}

t_vect	mult_mat_vec4(double **mat, t_vect v)
{
	t_vect mult;

	mult.x = v.x * mat[0][0] + v.y * mat[1][0] + v.z * mat[2][0] + \
	mat[3][0];
	mult.y = v.x * mat[0][1] + v.y * mat[1][1] + v.z * mat[2][1] + \
	mat[3][1];
	mult.z = v.x * mat[0][2] + v.y * mat[1][2] + v.z * mat[2][2] + \
	mat[3][2];
	return (mult);
}
