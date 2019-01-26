/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:49:24 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/26 16:40:40 by bkiehn           ###   ########.fr       */
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

int     main()
{
    t_mlx       lx;
    t_dot       *points;
    int         i;
    double      *angle;
    
    angle = (double*)malloc(sizeof(double) * 3);
    points = (t_dot*)malloc(sizeof(t_dot) * 8);
    i = 0; 
    
    points[0].x = -50;
    points[0].y = 50;
    points[0].z = 50;
    points[1].x = 50;
    points[1].y = 50;
    points[1].z = 50;
    points[2].x = 50;
    points[2].y = 50;
    points[2].z = -50;
    points[3].x = -50;
    points[3].y = 50;
    points[3].z = -50;
    points[4].x = -50;
    points[4].y = -50;
    points[4].z = 50;
    points[5].x = 50;
    points[5].y = -50;
    points[5].z = 50;
    points[6].x = 50;
    points[6].y = -50;
    points[6].z = -50;
    points[7].x = -50;
    points[7].y = -50;
    points[7].z = -50;

    lx.mlx_ptr = mlx_init();
    lx.width = 1000;
    lx.height = 1000;
    lx.win_ptr = mlx_new_window(lx.mlx_ptr, lx.width, lx.height, "fdf");
    
    angle[0] = 0;
    angle[1] = 0;
    angle[2] = 0;
  
    while (i < 8)
    {
        projection(points, i);
        rotate(&points, i, angle);
        center(&points, i, lx);
        i++;
    }
    

    mlx_string_put(lx.mlx_ptr, lx.win_ptr, points[0].x, points[0].y, 0x00ffffff, "0");
    mlx_string_put(lx.mlx_ptr, lx.win_ptr, points[1].x, points[1].y, 0x00ffffff, "1");
    mlx_string_put(lx.mlx_ptr, lx.win_ptr, points[2].x, points[2].y, 0x00ffffff, "2");
    mlx_string_put(lx.mlx_ptr, lx.win_ptr, points[3].x, points[3].y, 0x00ffffff, "3");
    mlx_string_put(lx.mlx_ptr, lx.win_ptr, points[4].x, points[4].y, 0x00ffffff, "4");
    mlx_string_put(lx.mlx_ptr, lx.win_ptr, points[5].x, points[5].y, 0x00ffffff, "5");
    mlx_string_put(lx.mlx_ptr, lx.win_ptr, points[6].x, points[6].y, 0x00ffffff, "6");
    mlx_string_put(lx.mlx_ptr, lx.win_ptr, points[7].x, points[7].y, 0x00ffffff, "7");
    

     draw_line (points, 0, 1, lx);
     draw_line (points, 1, 2, lx);
     draw_line (points, 2, 3, lx);
     draw_line (points, 3, 0, lx);

     draw_line (points, 4, 5, lx);
     draw_line (points, 5, 6, lx);
     draw_line (points, 6, 7, lx);
     draw_line (points, 7, 4, lx);

     draw_line (points, 0, 4, lx);
     draw_line (points, 1, 5, lx);
     draw_line (points, 2, 6, lx);
     draw_line (points, 3, 7, lx);

    mlx_hook(lx.win_ptr, 2, 0, deal_key, 0);
    mlx_loop(lx.mlx_ptr);
}