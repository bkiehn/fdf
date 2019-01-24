/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:49:24 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/23 22:08:41 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key (int key, int param)
{
    if (key == 53)
    exit (0);
    return (0);
}

void    draw_line(t_dot *points, int a, int b, t_mlx lx)
{
    int     dx;
    int     dy;
    int     sx;
    int     sy;
    int     err;
    int     e2;
    int     x0 = points[a].x;
    int     y0 = points[a].y;
    int     x1 = points[b].x;
    int     y1 = points[b].y;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = x0 < x1 ? 1 : -1;
    sy = y0 < y1 ? 1 : -1;
    err = (dx > dy ? dx : -dy) / 2;
    while (1)
    {
        mlx_pixel_put(lx.mlx_ptr, lx.win_ptr, x0, y0, 0x00ffffff);
        if ((x0 == x1) && (y0 ==y1))
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void    projection(t_dot *points, int d)
    {
        int i;
        int tempz;

        i = 0;
        while (i <= 7)
        {
            tempz = 500 / (d + points[i].z);
            points[i].x = points[i].x * tempz + 250;
            points[i].y = points[i].y * tempz + 250;
            i++;
        }
    }

t_dot    *rotate(t_dot *points, double axis_x, double axis_y, double axis_z)
    {
        int     i;
        t_dot   *pr;

        i = 0;
        pr = (t_dot*)malloc(sizeof(t_dot) * 8);
        while (i < 7)
        {
            if (axis_x != 0)
            {
                pr[i].x = points[i].x;
                pr[i].y = points[i].y * cos(axis_x) + points[i].z * sin(axis_x);
                pr[i].z = -points[i].y * sin(axis_x) + points[i].z * cos(axis_x);
            }
            if (axis_y != 0)
            {
                pr[i].x = points[i].x * cos(axis_y) + points[i].z * sin(axis_y);
                pr[i].y = points[i].y;
                pr[i].z = -points[i].x * sin(axis_y) + points[i].z * cos(axis_y);
            }
            // else
            // {
            //     pr[i].x = points[i].x;
            //     pr[i].y = points[i].y;
            //     pr[i].z = points[i].z;
            // }
            if (axis_z != 0)
            {
                pr[i].x = points[i].x * cos(axis_z) - points[i].y * sin(axis_z);
                pr[i].y = points[i].x * sin(axis_z) + points[i].y * cos(axis_z);
                pr[i].z = points[i].z;
            }
            i++;
        }
        return (pr);
    }

int     main()
{
    t_mlx   lx;
    t_dot   points[8];
    t_dot   *points_r;
    int     i;
    int     d;
    
    points[0].x = -20;
    points[0].y = -20;
    points[0].z = -20;
    points[1].x = 20;
    points[1].y = -20;
    points[1].z = -20;
    points[2].x = 20;
    points[2].y = -20;
    points[2].z = 20;
    points[3].x = -20;
    points[3].y = -20;
    points[3].z = 20;
    points[4].x = -20;
    points[4].y = 20;
    points[4].z = -20;
    points[5].x = 20;
    points[5].y = 20;
    points[5].z = -20;
    points[6].x = 20;
    points[6].y = 20;
    points[6].z = 20;
    points[7].x = -20;
    points[7].y = 20;
    points[7].z = 20;

    lx.mlx_ptr = mlx_init();
    lx.win_ptr = mlx_new_window(lx.mlx_ptr, 500, 500, "test");
    i = 0;
    d = 100;
    points_r = rotate(points, 0, 0, M_PI);
    projection(points_r, d);

    draw_line (points_r, 0, 1, lx);
    draw_line (points_r, 1, 2, lx);
    draw_line (points_r, 2, 3, lx);
    draw_line (points_r, 3, 0, lx);

    draw_line (points_r, 4, 5, lx);
    draw_line (points_r, 5, 6, lx);
    draw_line (points_r, 6, 7, lx);
    draw_line (points_r, 7, 4, lx);

    draw_line (points_r, 0, 4, lx);
    draw_line (points_r, 1, 5, lx);
    draw_line (points_r, 2, 6, lx);
    draw_line (points_r, 3, 7, lx);

    mlx_hook(lx.win_ptr, 2, 0, deal_key, 0);
    mlx_loop(lx.mlx_ptr);
}