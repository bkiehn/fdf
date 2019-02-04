/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:49:24 by bkiehn            #+#    #+#             */
/*   Updated: 2019/02/04 21:01:53 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	defolt(t_mlx *lx)
{
	lx->growth = 1;
	lx->growth_get = 1;
	lx->z_offset = 30;
	if (lx->projection == 1)
		lx->scale = lx->w_window / (lx->w_grid * 2);
	else if (lx->projection == 2)
		lx->scale = -lx->w_window / (lx->w_grid * 2);
	else if (lx->projection == 3)
		lx->scale = -lx->w_window / (lx->w_grid * 20);
	lx->angle[0] = 0;
	lx->angle[1] = 0;
	lx->angle[2] = 0;
	lx->h_window = 1000;
	lx->w_window = 1000;
}

int		deal_key(int key, t_mlx *lx)
{
	if (key == 92 || (key >= 18 && key <= 20))
		change_proj(key, lx);
	if (key >= 123 && key <= 126)
		move(key, lx);
	if (key == 116)
	{
		lx->growth += 1;
		lx->growth_get += 0.1;
	}
	if (key == 121)
	{
		lx->growth -= 1;
		lx->growth_get -= 0.1;
	}
	if (key >= 83 && key <= 88)
		change_angle(key, lx);
	if (key == 69 || ((key == 78 && lx->scale) != 0))
		change_scale(key, lx);
	if (key == 53)
		exit(0);
	redraw_grid(lx);
	draw_gui(lx);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;

	if ((argc == 1 || argc > 2))
		ft_putendl("Usage: ./fdf <filename>");
	else if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("No file ");
		ft_putendl(argv[1]);
	}
	else if (!(rfile(fd)))
		ft_putendl("error");
}
