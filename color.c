/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:23:50 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/31 22:12:30 by bkiehn           ###   ########.fr       */
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

int     get_color(t_dot *a, t_dot *b, int x, int y, int f)
{
    t_color     current;
    t_color     start;
    t_color     end;
    t_color     delta;
    int         red;
    int         green;
    int         blue;
    double      percentage;

    if (f == 0)
    { 
        start.color = 0x000000FF;
        end.color = 0x0000FF00;
    }
    else
    { 
        if (a->color == 0)
            start.color = 0x00FFFFFF;
        else
            start.color = a->color;
        if (a->color == 0)
            end.color = 0x00FFFFFF;
        else
            end.color = b->color;
    }
    if (b->z != 0)
    {
        start.x = a->x_c;
        start.y = a->y_c;
        end.x = b->x_c;
        end.y = b->y_c;
    }
    else if (a->z != 0)
    {
        start.x = b->x_c;
        start.y = b->y_c;
        end.x = a->x_c;
        end.y = a->y_c;
    }
    else
        return (start.color);  
    if (a->z == b->z)
        return (end.color);      
    current.x = x;
    current.y = y;
    //current.color = 0x00ff0000;
    delta.x = end.x - start.x;
    delta.y = end.y - start.y;
    //if (current.color == end.color)
    //    return (current.color);
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}