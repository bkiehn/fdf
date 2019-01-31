/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:52:22 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/31 21:43:09 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "libft/includes/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_dot
{
	int             x;
	int             y;
	int             z;
	int				x_c;
	int				y_c;
	int				z_c;
	int				color;
	struct s_dot	*next;
}					t_dot;

typedef struct      s_mlx
{
    void            *mlx_ptr;
    void            *win_ptr;
	int				h_window;
	int				w_window;
	int				h_grid;
	int				w_grid;
	int				scale;
	int				growth;
	double			angle[3];
	int				movement_x;
	int				movement_y;
	int				color_flag;
	t_dot			*dots;
}                   t_mlx;

typedef struct      s_color
{
    int				color;
	int				x;
	int				y;
}                   t_color;

void    rotate(t_dot **points, double *angle);
void    projection(t_dot **points);
void    center(t_dot **po, t_mlx lx);
int     rfile(int fd);
void    draw_line(t_dot *a, t_dot *b, t_mlx lx);
int     deal_key (int key, t_mlx *lx);
void    draw_grid(t_dot **grid, t_mlx lx);
int     get_color(t_dot *a, t_dot *b, int x, int y, int f);
void    write_grid(t_dot **grid, int y, char **line);
void	apply_tuning(t_dot **grid, t_mlx lx);
void	draw_column(t_dot **grid, t_mlx lx);
void    draw_string(t_dot **grid, t_mlx lx, int ww, int w);
void	redraw_grid(t_mlx *lx);

#endif