/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:10:11 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/31 19:00:52 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    rotate(t_dot **points, double *angle)
{
    double x;
    double y;
    double z;  

    x = (**points).x_c;
    y = (**points).y_c;
    z = (**points).z_c;
    if (angle[0] != 0)
    {
        (**points).y_c = y * cos(angle[0]) + z * sin(angle[0]);
        (**points).z_c = (-y) * sin(angle[0]) + z * cos(angle[0]);
        y = (**points).y_c;
        z = (**points).z_c;
    }
    if (angle[1] != 0)
    {
        (**points).x_c = x * cos(angle[1]) + z * sin(angle[1]);
        (**points).z_c = (- x) * sin(angle[1]) + z * cos(angle[1]); 
        x = (**points).x_c;
        z = (**points).z_c;
    }
    if (angle[2] != 0)
    {
        (**points).x_c = x * cos(angle[2]) - y * sin(angle[2]);
        (**points).y_c = x * sin(angle[2]) + y * cos(angle[2]);
    }
}

void    projection(t_dot **points)
{

    int x;
    int y;
    int z;

    x = (**points).x_c;
    y = (**points).y_c;
    z = (**points).z_c;
    // (**points).x_c = (x + y) * cos(0.523599);
    // (**points).y_c  = (x - y) * sin(0.523599) - z;
    (**points).x_c = (x - y) * -cos(0.523599);
    (**points).y_c  = ((x + y) * sin(0.523599)) -z;
    // (**points).x_c = (x - y) * cos(0.523599);
    // (**points).y_c = ((x + y) * sin(0.523599)) - z;
    // (**points).x_c = (x + y) * -cos(0.523599);
    // (**points).y_c = ((x - y) * sin(0.523599)) - z;
    
}

void    center(t_dot **po, t_mlx lx)
{   
        (**po).x_c += lx.w_window / 2;
        (**po).y_c += lx.h_window / 2;
        //(**po).z_c += lx.w_window / 2;
}