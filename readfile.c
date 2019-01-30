/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:27:41 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/30 23:13:23 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void        draw_column(t_dot **grid, t_mlx lx, int ww, int w)
{
    t_dot   *gr;
    t_dot   *gr2;
    t_dot   *gr3;
    int     h;

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
            draw_line (gr, gr2, lx);
            gr = gr2;
            w = lx.w_grid;
        }        
        h = lx.h_grid - 1;
        gr3 = gr3->next;
        gr = gr3;
        gr2 = gr3;
    }
}

void        draw_string(t_dot **grid, t_mlx lx)
{
    int     w;
    t_dot   *gr;

    gr = *grid;
    w = lx.w_grid - 1;
    while (gr)
    { 
        while (w--)
        {
            if (gr->next)
                draw_line (gr, gr->next, lx);
            else
                break;
            gr = gr->next;
        }
        w = lx.w_grid - 1;
        gr = gr->next;
    }
}

void        redraw_grid(t_mlx *lx)
{
    mlx_clear_window(lx->mlx_ptr, lx->win_ptr);
    apply_tuning(&lx->dots, *lx);
    draw_string(&lx->dots, *lx);
    draw_column(&lx->dots, *lx, lx->w_grid, lx->w_grid);
}

void        apply_tuning(t_dot **grid, t_mlx lx)
{
    t_dot   *gr;

    gr = *grid;
    while (gr)
    {
        gr->x_c = (gr->x - (lx.w_grid / 2)) * lx.scale;
        gr->y_c = (gr->y - (lx.h_grid / 2)) * lx.scale;
        gr->z_c = gr->z * lx.growth;
        projection (&gr);
        rotate(&gr, lx.angle);
        center(&gr, lx);
        gr = gr->next;
    }
}

void        tuning(t_dot **grid, int h, int w)
{
    t_dot   *gr;
    t_mlx   lx;

    lx.dots = *grid;
    lx.w_window = 1000;
    lx.h_window = 1000;
    lx.w_grid = w;
    lx.h_grid = h;
    lx.scale = 30;
    lx.growth = 1;
    gr = *grid;
    apply_tuning(grid, lx);
    lx.mlx_ptr = mlx_init();
    lx.win_ptr = mlx_new_window(lx.mlx_ptr, lx.w_window, lx.h_window, "fdf");
    draw_string(grid, lx);
    draw_column(grid, lx, lx.w_grid, lx.w_grid);
    mlx_hook(lx.win_ptr, 2, 0, deal_key, &lx);
    mlx_loop(lx.mlx_ptr);
}

int     ft_strskok(char **str)
{
    int i;

    i = 0;
    while (str[i] != 0)
        i++;
    return (i);
}

int     rfile(int fd)
{
    char    *line;
    int     h;
    int     w;
    char    **line2;
    t_dot   *grid;
    t_dot   *gr;
    
    h = 0;
    grid = 0;
    get_next_line(fd, &line);
    line2 = ft_strsplit(line, ' ');
    w = ft_strskok(line2);
    write_grid(&grid, h, line2);
    h++;
    while(get_next_line(fd, &line))
    {
        line2 = ft_strsplit(line, ' ');
        if (w != ft_strskok(line2))
            return (0);
        else
            write_grid(&grid, h, line2);
        h++;
    }
    // gr = grid;
    // // while (gr)
    // // {
    // //     printf("x = %d y = %d z = %d color = %d\n", gr->x, gr->y, gr->z, gr->color);
    // //     gr = gr->next;
    // // }
    tuning(&grid, h, w);
    return (1);
}