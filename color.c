/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:23:50 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/27 22:29:16 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     get_light(int start, int end, double percentage)
{
        return ((int)((1 - percentage) * start + percentage * end));
}

double  percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return((distance == 0) ? 1.0 : (placement / distance));
}

int     get_color(t_dot *points, int a, int b, int x, int y)
{
    t_color     current;
    t_color     start;
    t_color     end;
    t_color     delta;
    int         red;
    int         green;
    int         blue;
    double      percentage;

    start.color = 0x00ff0000;
    end.color = 0x00ffffff;
    if (points[a].z > 500 || points[b].z > 500)
    {
        if (points[a].z == points[b].z)
            return (start.color);
        start.x = points[a].x;
        start.y = points[a].y;
        end.x = points[b].x;
        end.y = points[b].y;
        current.x = x;
        current.y = y;
        current.color = 0x000000ff;
        delta.x = end.x - start.x;
        delta.y = end.y - start.y;

        if (current.color == end.color)
            return (current.color);
        if (delta.x > delta.y)
            percentage = percent(start.x, end.x, current.x);
        else
            percentage = percent(start.y, end.y, current.y);
        red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
        green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
        blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
        return ((red << 16) | (green << 8) | blue);
    }
    else
        return (end.color);
  
}