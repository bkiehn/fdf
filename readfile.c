/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:27:41 by bkiehn            #+#    #+#             */
/*   Updated: 2019/02/04 20:36:05 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_column(t_dot **grid, t_mlx lx, int ww, int w)
{
	t_dot	*gr;
	t_dot	*gr2;
	t_dot	*gr3;
	int		h;

	gr = *grid;
	gr2 = *grid;
	gr3 = *grid;
	h = lx.h_grid - 1;
	while (ww--)
	{
		while (h--)
		{
			while (w--)
				gr2 = gr2->next;
			draw_line(gr, gr2, lx);
			gr = gr2;
			w = lx.w_grid;
		}
		h = lx.h_grid - 1;
		gr3 = gr3->next;
		gr = gr3;
		gr2 = gr3;
	}
}

void	draw_string(t_dot **grid, t_mlx lx)
{
	int		w;
	t_dot	*gr;

	gr = *grid;
	w = lx.w_grid - 1;
	while (gr)
	{
		while (w--)
		{
			if (gr->next)
				draw_line(gr, gr->next, lx);
			else
				break ;
			gr = gr->next;
		}
		w = lx.w_grid - 1;
		gr = gr->next;
	}
}

void	redraw_grid(t_mlx *lx)
{
	mlx_clear_window(lx->mlx_ptr, lx->win_ptr);
	if (apply_tuning(&lx->dots, *lx))
	{
		draw_string(&lx->dots, *lx);
		draw_column(&lx->dots, *lx, lx->w_grid, lx->w_grid);
	}
}

int		apply_tuning(t_dot **grid, t_mlx lx)
{
	t_dot	*gr;

	gr = *grid;
	while (gr)
	{
		gr->x_c = (gr->x - (lx.w_grid / 2)) * -lx.scale;
		gr->y_c = (gr->y - (lx.h_grid / 2)) * -lx.scale;
		if (lx.projection != 3)
			gr->z_c = gr->z * lx.growth;
		else
			gr->z_c = -gr->z * lx.growth_get;
		if (lx.projection == 1)
			projection(&gr);
		rotate(&gr, lx.angle);
		if (lx.projection == 3)
			if (!(get_proj(&gr, lx)))
				return (0);
		center(&gr, lx);
		gr = gr->next;
	}
	return (1);
}

void	tuning(t_dot **grid, int h, int w)
{
	t_mlx	lx;

	lx.projection = 1;
	lx.growth_get = 1;
	lx.z_offset = 30;
	lx.color_flag = detect_color(grid);
	lx.dots = *grid;
	lx.w_window = 1000;
	lx.h_window = 1000;
	lx.x_factor = lx.w_window / 2;
	lx.y_factor = lx.h_window / 2;
	lx.w_grid = w;
	lx.h_grid = h;
	lx.scale = lx.w_window / (w * 2);
	lx.growth = 1;
	apply_tuning(grid, lx);
	lx.mlx_ptr = mlx_init();
	lx.win_ptr = mlx_new_window(lx.mlx_ptr, lx.w_window, lx.h_window, "fdf");
	draw_string(grid, lx);
	draw_column(grid, lx, lx.w_grid, lx.w_grid);
	draw_gui(&lx);
	mlx_hook(lx.win_ptr, 2, 0, deal_key, &lx);
	mlx_loop(lx.mlx_ptr);
}
