/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:18:53 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/04 18:10:09 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(int key, t_mlx *lx)
{
	if (key == 125)
		lx->h_window += 10;
	else if (key == 123)
		lx->w_window -= 10;
	else if (key == 124)
		lx->w_window += 10;
	else if (key == 126)
		lx->h_window -= 10;
}

void	change_proj(int key, t_mlx *lx)
{
	if (key == 92)
		defolt(lx);
	if (key == 18 && lx->projection != 1)
	{
		lx->projection = 1;
		defolt(lx);
	}
	if (key == 19 && lx->projection != 2)
	{
		lx->projection = 2;
		defolt(lx);
	}
	if (key == 20 && lx->projection != 3)
	{
		lx->projection = 3;
		defolt(lx);
	}
}

void	change_angle(int key, t_mlx *lx)
{
	if (key == 86)
		lx->angle[0] += 0.069813;
	if (key == 83)
		lx->angle[0] -= 0.069813;
	if (key == 87)
		lx->angle[1] += 0.069813;
	if (key == 84)
		lx->angle[1] -= 0.069813;
	if (key == 88)
		lx->angle[2] += 0.069813;
	if (key == 85)
		lx->angle[2] -= 0.069813;
}

void	change_scale(int key, t_mlx *lx)
{
	if (key == 69)
	{
		if (lx->projection == 1)
			lx->scale += 1;
		else if (lx->projection == 2)
			lx->scale -= 1;
		else if (lx->z_offset > 1)
			lx->z_offset -= 1;
	}
	if (key == 78 && lx->scale != 0)
	{
		if (lx->projection == 1)
			lx->scale -= 1;
		else if (lx->projection == 2)
			lx->scale += 1;
		else
			lx->z_offset += 1;
	}
}

void	draw_gui(t_mlx *lx)
{
	mlx_string_put(lx->mlx_ptr, lx->win_ptr, lx->x_factor * 2 - 110,
	lx->y_factor * 2 - 30, 0x0000FF99, "ESC : Quit");
	mlx_string_put(lx->mlx_ptr, lx->win_ptr, lx->x_factor / 50,
	lx->y_factor / 25, 0x0000FF99, "Arrow keys : Movement");
	mlx_string_put(lx->mlx_ptr, lx->win_ptr, lx->x_factor / 50,
	lx->y_factor / 25 + 30, 0x0000FF99, "1 2 3 : Change projection");
	mlx_string_put(lx->mlx_ptr, lx->win_ptr, lx->x_factor / 50 + 300,
	lx->y_factor / 25, 0x0000FF99, "4/1(X) 5/2(Y) 6/3(Z) : Rotation");
	mlx_string_put(lx->mlx_ptr, lx->win_ptr, lx->x_factor / 50 + 300,
	lx->y_factor / 25 + 30, 0x0000FF99, "9 : Default view");
	mlx_string_put(lx->mlx_ptr, lx->win_ptr, lx->x_factor / 50 + 650,
	lx->y_factor / 25, 0x0000FF99, "+/- : Zoom in/out");
	mlx_string_put(lx->mlx_ptr, lx->win_ptr, lx->x_factor / 50 + 650,
	lx->y_factor / 25 + 30, 0x0000FF99, "Change Z : Up/Down");
}
