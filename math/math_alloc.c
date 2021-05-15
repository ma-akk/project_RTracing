/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:34:03 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 17:53:33 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

double	**mat_alloc(int n, int m)
{
	double	**mat;
	double	*start;
	int		i;
	int		j;

	i = -1;
	mat = (double**)malloc(n * sizeof(double*) + n * m * sizeof(double));
	if (mat)
	{
		start = (double*)((char*)mat + n * sizeof(double*));
		while (++i < n)
			mat[i] = start + i * m;
		i = -1;
		while (++i < n)
		{
			j = -1;
			while (++j < m)
				mat[i][j] = 0;
		}
	}
	else
		error_exit(-1);
	return (mat);
}

void	mat_free(double **mat)
{
	if (mat)
		free(mat);
}
