/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:52:22 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/26 16:15:12 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "libft/includes/mlx.h"
# include <math.h>
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

void    rotate(t_dot **points, int i, double *angle);
void    projection(t_dot *points, int i);
void    center(t_dot **po, int i, t_mlx lx);

#endif