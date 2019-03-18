/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:10:11 by bkiehn            #+#    #+#             */
/*   Updated: 2019/02/09 19:29:41 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_dot **points, double *angle)
{
	t_dot	temp;

	temp.x_c = (**points).x_c;
	temp.y_c = (**points).y_c;
	temp.z_c = (**points).z_c;
	if (angle[0] != 0)
	{
		(**points).y_c = temp.y_c * cos(angle[0]) + temp.z_c * sin(angle[0]);
		(**points).z_c = (-temp.y_c) * sin(angle[0]) + temp.z_c * cos(angle[0]);
		temp.y_c = (**points).y_c;
		temp.z_c = (**points).z_c;
	}
	if (angle[1] != 0)
	{
		(**points).x_c = temp.x_c * cos(angle[1]) + temp.z_c * sin(angle[1]);
		(**points).z_c = (-temp.x_c) * sin(angle[1]) + temp.z_c * cos(angle[1]);
		temp.x_c = (**points).x_c;
		temp.z_c = (**points).z_c;
	}
	if (angle[2] != 0)
	{
		(**points).x_c = temp.x_c * cos(angle[2]) - temp.y_c * sin(angle[2]);
		(**points).y_c = temp.x_c * sin(angle[2]) + temp.y_c * cos(angle[2]);
	}
}

void	projection(t_dot **points)
{
	int x;
	int y;
	int z;

	x = (**points).x_c;
	y = (**points).y_c;
	z = (**points).z_c;
	(**points).x_c = (x + y) * -cos(0.523599);
	(**points).y_c = (x - y) * sin(0.523599) - z;
}

void	center(t_dot **po, t_mlx lx)
{
	(**po).x_c += lx.w_window / 2;
	(**po).y_c += lx.h_window / 2;
}

int		get_proj(t_dot **gr, t_mlx lx)
{
	float	z_inv;

	if (((**gr).z_c + lx.z_offset) > 0)
	{
		z_inv = 1 / ((**gr).z_c + lx.z_offset);
		(**gr).x_c = ((**gr).x_c * z_inv) * lx.x_factor;
		(**gr).y_c = ((**gr).y_c * z_inv) * lx.y_factor;
	}
	else
		return (0);
	return (1);
}
