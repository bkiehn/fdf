/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:20:44 by dzboncak          #+#    #+#             */
/*   Updated: 2019/02/04 18:31:46 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_d0_d1(t_dot *d0, t_dot *d1, t_dot *a, t_dot *b)
{
	d0->x = a->x_c;
	d0->y = a->y_c;
	d1->x = b->x_c;
	d1->y = b->y_c;
}

void	init_diff_s_er(t_dot *diff, t_dot *d0, t_dot *d1, t_dot *s)
{
	diff->x = abs(d1->x - d0->x);
	diff->y = abs(d1->y - d0->y);
	s->x = d0->x < d1->x ? 1 : -1;
	s->y = d0->y < d1->y ? 1 : -1;
}

void	change_er_d0(t_dot *er, t_dot *diff, t_dot *s, t_dot *d0)
{
	if (er->y > -diff->x)
	{
		er->x -= diff->y;
		d0->x += s->x;
	}
	if (er->y < diff->y)
	{
		er->x += diff->x;
		d0->y += s->y;
	}
}

void	draw_line(t_dot *a, t_dot *b, t_mlx lx)
{
	t_dot	diff;
	t_dot	s;
	t_dot	er;
	t_dot	d0;
	t_dot	d1;

	init_d0_d1(&d0, &d1, a, b);
	diff.x = abs(d1.x - d0.x);
	diff.y = abs(d1.y - d0.y);
	s.x = d0.x < d1.x ? 1 : -1;
	s.y = d0.y < d1.y ? 1 : -1;
	er.x = (diff.x > diff.y ? diff.x : -(diff.y)) / 2;
	d0.x_c = lx.color_flag;
	while (1)
	{
		if (d0.x < 1000 && d0.x > 0 && d0.y < 1000 && d0.y > 0)
		{
			d0.color = get_color(a, b, d0);
			mlx_pixel_put(lx.mlx_ptr, lx.win_ptr, d0.x, d0.y, d0.color);
		}
		if ((d0.x == d1.x) && (d0.y == d1.y))
			break ;
		er.y = er.x;
		change_er_d0(&er, &diff, &s, &d0);
	}
}
