/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:52:22 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/23 17:24:33 by bkiehn           ###   ########.fr       */
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
}                   t_mlx;


#endif