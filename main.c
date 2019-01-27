/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:49:24 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/27 21:22:44 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key (int key, t_redraw *param)
{
    static int y = 1;
    
    if (key == 126)
    {
        y += 1;
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
    if (key == 92)
    {
        y = 1;
        (*param).x = 0;
        (*param).y = 0;
        (*param).z = 0;
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
    if (key == 125)
    {
        y -= 1;
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
    if (key == 86)
    {
        (*param).x += 0.069813; 
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
    if (key == 83)
    {
        (*param).x -= 0.069813;
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
    if (key == 87)
    {
        (*param).y += 0.069813; 
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
    if (key == 84)
    {
        (*param).y -= 0.069813;
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
    if (key == 88)
    {
        (*param).z += 0.069813; 
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
    if (key == 85)
    {
        (*param).z -= 0.069813;
        mlx_clear_window((*param).mlx_ptr, (*param).win_ptr);
        redraw (*param, y);
    }
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
    int     c;
    int     x0 = points[a].x;
    int     y0 = points[a].y;
    int     x1 = points[b].x;
    int     y1 = points[b].y;
    int     color;
    
    c = 0;
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = x0 < x1 ? 1 : -1;
    sy = y0 < y1 ? 1 : -1;
    err = (dx > dy ? dx : -dy) / 2;
    while (1)
    {
        color = get_color(points, a, b, x0, y0);
        mlx_pixel_put(lx.mlx_ptr, lx.win_ptr, x0, y0, color);
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
        c++;
    }
}

int     main(int argc, char **argv)
{
    int     fd;

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