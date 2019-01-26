/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:10:11 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/26 16:35:30 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    rotate(t_dot **points, int i, double *angle)
{
    double x;
    double y;
    double z;  

    x = (*points)[i].x;
    y = (*points)[i].y;
    z = (*points)[i].z;
    if (angle[0] != 0)
    {
        (*points)[i].y = y * cos(angle[0]) + z * sin(angle[0]);
        (*points)[i].z = (-y) * sin(angle[0]) + z * cos(angle[0]);
        y = (*points)[i].y;
        z = (*points)[i].z;
    }
    if (angle[1] != 0)
    {
        (*points)[i].x = x * cos(angle[1]) + z * sin(angle[1]);
        (*points)[i].z = (- x) * sin(angle[1]) + z * cos(angle[1]); 
        x = (*points)[i].x;
        z = (*points)[i].z;
    }
    if (angle[2] != 0)
    {
        (*points)[i].x = x * cos(angle[2]) - y * sin(angle[2]);
        (*points)[i].y = x * sin(angle[2]) + y * cos(angle[2]);
    }
}

void    projection(t_dot *points, int i)
{

    int x;
    int y;
    int z;

    x = points[i].x;
    y = points[i].y;
    z = points[i].z;
    // points[i].x = (x + y) * cos(0.523599);
    // points[i].y = (x - y) * sin(0.523599) - z;
    // points[i].x = (x - y) * -cos(0.523599);
    // points[i].y = ((x + y) * sin(0.523599)) -z;
    // points[i].x = (x - y) * cos(0.523599);
    // points[i].y = ((x + y) * sin(0.523599)) - z;
    points[i].x = (x + y) * -cos(0.523599);
    points[i].y = ((x - y) * sin(0.523599)) - z;
    
}

void    center(t_dot **po, int i, t_mlx lx)
{   
        (*po)[i].x += lx.width / 2;
        (*po)[i].y += lx.width / 2;
        (*po)[i].z += lx.width / 2;
}