/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:49:24 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/30 23:11:57 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key (int key, t_mlx *lx)
{
    if (key == 92)
    {
        lx->growth = 1;
        lx->scale = 30;
        lx->angle[0] = 0;
        lx->angle[1] = 0;
        lx->angle[2] = 0;
        redraw_grid(lx);
    }
    if (key == 126)
        lx->w_window += 10;
    if (key == 125)
        lx->w_window -= 10;
    if (key == 116)
        lx->growth += 1;
    if (key == 121)
        lx->growth -= 1;
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
    if (key == 69)
        lx->scale += 5;
    if (key == 78)
        lx->scale -= 5;
    if (key == 53)
        exit (0);
    redraw_grid(lx);
    return (0);
}

void    draw_line(t_dot *a, t_dot *b, t_mlx lx)
{
    int     dx;
    int     dy;
    int     sx;
    int     sy;
    int     err;
    int     e2;
    int     c;
    int     x0 = a->x_c;
    int     y0 = a->y_c;
    int     x1 = b->x_c;
    int     y1 = b->y_c;
    int     color;
    
    c = 0;
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = x0 < x1 ? 1 : -1;
    sy = y0 < y1 ? 1 : -1;
    err = (dx > dy ? dx : -dy) / 2;
    while (1)
    {
        //color = get_color(points, a, b, x0, y0);
        mlx_pixel_put(lx.mlx_ptr, lx.win_ptr, x0, y0, 0xFF0000);
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