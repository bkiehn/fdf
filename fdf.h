/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:52:22 by bkiehn            #+#    #+#             */
/*   Updated: 2019/02/04 21:48:16 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "libft/includes/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	float			x_c;
	float			y_c;
	float			z_c;
	int				color;
	struct s_dot	*next;
}					t_dot;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				h_window;
	int				w_window;
	int				h_grid;
	int				w_grid;
	int				scale;
	int				growth;
	double			growth_get;
	double			angle[3];
	int				movement_x;
	int				movement_y;
	int				color_flag;
	int				projection;
	int				z_offset;
	int				x_factor;
	int				y_factor;
	t_dot			*dots;
}					t_mlx;

typedef struct		s_color
{
	int				color;
	int				x;
	int				y;
}					t_color;

void				rotate(t_dot **points, double *angle);
void				projection(t_dot **points);
void				center(t_dot **po, t_mlx lx);
int					rfile(int fd);
void				draw_line(t_dot *a, t_dot *b, t_mlx lx);
int					deal_key (int key, t_mlx *lx);
void				draw_grid(t_dot **grid, t_mlx lx);
int					get_color(t_dot *a, t_dot *b, t_dot current);
void				write_grid(t_dot **grid, int y, char **line);
int					apply_tuning(t_dot **grid, t_mlx lx);
void				draw_string(t_dot **grid, t_mlx lx);
void				draw_column(t_dot **grid, t_mlx lx, int ww, int w);
void				redraw_grid(t_mlx *lx);
int					get_proj(t_dot **gr, t_mlx lx);
void				draw_gui(t_mlx *lx);
void				b_z(t_color *start, t_color *end, t_dot *a, t_dot *b);
void				a_z(t_color *start, t_color *end, t_dot *a, t_dot *b);
void				move(int key, t_mlx *lx);
void				change_proj(int key, t_mlx *lx);
void				change_angle(int key, t_mlx *lx);
void				change_scale(int key, t_mlx *lx);
void				defolt(t_mlx *lx);
int					detect_color(t_dot **grid);
int					ft_strskok(char **str);
int					rfile(int fd);
void				tuning(t_dot **grid, int h, int w);

#endif
