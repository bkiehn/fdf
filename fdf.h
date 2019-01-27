/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:52:22 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/27 20:45:28 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "libft/includes/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_dot
{
	int             x;
	int             y;
	int             z;
}					t_dot;

typedef struct      s_mlx
{
    void            *mlx_ptr;
    void            *win_ptr;
	int				height;
	int				width;
}                   t_mlx;

typedef struct      s_redwraw
{
    void            *mlx_ptr;
    void            *win_ptr;
	int				height;
	int				width;
	int				i;
	int				j;
	int				**grid;
	double			x;
	double			y;
	double			z;
}                   t_redraw;

typedef struct      s_color
{
    int				color;
	int				x;
	int				y;
}                   t_color;

void    rotate(t_dot **points, int i, double *angle);
void    projection(t_dot *points, int i);
void    center(t_dot **po, int i, t_mlx lx);
int     rfile(int fd);
void    draw_line(t_dot *points, int a, int b, t_mlx lx);
int     deal_key (int key, t_redraw *param);
void    draw_grid(int **grid, int i, int j, int y);
void    redraw(t_redraw nabor, int y);
int     get_color(t_dot *points, int a, int b, int x, int y);

#endif