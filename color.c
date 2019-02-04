/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:23:50 by bkiehn            #+#    #+#             */
/*   Updated: 2019/02/04 21:41:58 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			choise_color(t_color start, t_color end, t_dot current)
{
	t_color	delta;
	int		red;
	int		green;
	int		blue;
	double	percentage;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	if (abs(delta.x) > abs(delta.y))
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
	(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
	(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void		use_color(t_dot *a, t_dot *b, t_color *end, t_color *start)
{
	if (a->color == 0)
		start->color = 0x00FFFFFF;
	else
		start->color = a->color;
	if (b->color == 0)
		end->color = 0x00FFFFFF;
	else
		end->color = b->color;
}

int			get_color(t_dot *a, t_dot *b, t_dot current)
{
	t_color	start;
	t_color	end;

	if (current.x_c == 0)
	{
		start.color = 0x000000FF;
		end.color = 0x0000FF00;
	}
	else
		use_color(a, b, &end, &start);
	if ((a->z == b->z) && (a->z != 0))
		return (end.color);
	else if (b->z != 0)
		b_z(&start, &end, a, b);
	else if (a->z != 0)
		a_z(&start, &end, a, b);
	else
		return (start.color);
	return (choise_color(start, end, current));
}
