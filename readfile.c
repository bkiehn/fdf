/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:27:41 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/27 22:18:28 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    redraw(t_redraw nabor, int y)
{
    int         q;
    int         w;
    int         skv;
    t_dot       *points;
    t_mlx       lx;
    int         kor;
    double      *angle;

    lx.width = nabor.width;
    lx.height = nabor.height;
    lx.win_ptr = nabor.win_ptr;
    lx.mlx_ptr = nabor.mlx_ptr;    
    points = (t_dot*)malloc(sizeof(t_dot) * nabor.i * nabor.j);
    q = 0;
    w = 0;
    skv = 0;
    angle = (double*)malloc(sizeof(double) * 3);
    angle[0] = nabor.x;
    angle[1] = nabor.y;
    angle[2] = nabor.z;
    while (q < nabor.i)
    {
        while (w < nabor.j)
        {
            points[skv].x = (w - (nabor.j / 2)) * 30;
            points[skv].y = (q - (nabor.i / 2)) * 30;
            points[skv].z = nabor.grid[q][w] * y;
            projection(points, skv);
            rotate(&points, skv, angle);
            center(&points, skv, lx);
            skv++;
            w++;
        }
        q++;
        w = 0;
    }
    
    q = 0;
    kor = 0;
    while (q < (nabor.j * nabor.i - 1))
    { 
        draw_line (points, q, q + 1, lx);
        q++;
        if (((q - kor) % (nabor.j - 1)) == 0)
        { 
             q++;
             kor++;
        }
    }
    q = 0;
    while (q < (nabor.i * nabor.j - nabor.j))
    { 
        draw_line (points, q, q + nabor.j, lx);
        q += nabor.j;
        if (q > (nabor.i * nabor.j - 2 * nabor.j))
        { 
            w++;
            q = w;
        }
    }    
}

void    draw_grid(int **grid, int i, int j, int y)
{
    int         q;
    int         w;
    int         skv;
    t_dot       *points;
    t_mlx       lx;
    int         kor;
    double      *angle;
    t_redraw    nabor;

    angle = (double*)malloc(sizeof(double) * 3);
    points = (t_dot*)malloc(sizeof(t_dot) * i * j);
    q = 0;
    w = 0;
    skv = 0;
    lx.mlx_ptr = mlx_init();
    lx.width = 1000;
    lx.height = 1000;
    angle[0] = 0;
    angle[1] = 0;
    angle[2] = 0;
    while (q < i)
    {
        while (w < j)
        {
            points[skv].x = (w - (j / 2)) * 30;
            points[skv].y = (q - (i / 2)) * 30;
            points[skv].z = grid[q][w] * y;
            projection(points, skv);
            rotate(&points, skv, angle);
            center(&points, skv, lx);
            skv++;
            w++;
        }
        q++;
        w = 0;
    }
    
    lx.win_ptr = mlx_new_window(lx.mlx_ptr, lx.width, lx.height, "fdf");
    q = 0;
    kor = 0;
    while (q < (j * i))
    { 
        draw_line (points, q, q + 1, lx);
        q++;
        if (((q - kor) % (j - 1)) == 0)
        { 
             q++;
             kor++;
        }
    }
    q = 0;
    while (q < (i * j - j))
    { 
        draw_line (points, q, q + j, lx);
        q += j;
        if (q > (i * j - 2 * j))
        { 
            w++;
            q = w;
        }
    }
    nabor.mlx_ptr = lx.mlx_ptr;
    nabor.win_ptr = lx.win_ptr;
    nabor.grid = grid;
    nabor.i = i;
    nabor.j = j;
    nabor.height = lx.height;
    nabor.width = lx.width;
    nabor.x = angle[0];
    nabor.y = angle[1];
    nabor.z = angle[2];

    mlx_hook(lx.win_ptr, 2, 0, deal_key, &nabor);
    mlx_loop(lx.mlx_ptr);
}

int     **conversion(char *map, int *str, int *stlb)
{
    int     i;
    int     j;
    char    **matrix;
    char    **grid;
    int     **number;

    *str = 0;
    *stlb = 0;
    matrix = ft_strsplit(map, 'Q');
    while (matrix[*str] != 0)
        *str = *str + 1;
    number = (int**)malloc(sizeof(int*) * *str);
    i = 0;
    j = 0;
    while (matrix[i] != 0)
    {
        grid = ft_strsplit(matrix[i], ' ');
        while (grid[*stlb] != 0) //при условии что на вход податся именно матрица, с постоянным количеством символов в строке
            *stlb = *stlb + 1;
        number[i] = (int*)malloc(sizeof(int) * *stlb);
        while (grid[j] != 0)
        { 
            number[i][j] = ft_atoi(grid[j]);
            j++;
        }
        i++;
        j = 0;
    } 
     
    i = 0;
    j = 0;

    return(number);
}

int     rfile(int fd)
{
    char    *line;
    char    *line2;
    char    *map;
    int     i;
    int     j;
    int     y;
    
    y = 1;
    j = 0;
    while(get_next_line(fd, &line))
    {
        i = ft_strlen(line) + 1;
        line2 = (char*)malloc(sizeof(char) * i);
        line2[i] = 0;
        line2 = ft_strcpy(line2, line);
        line2[i - 1] = 'Q';
        if (j == 0)
            map = ft_strdup(line2);
        else
            map = ft_strjoin(map, line2);        
        j++;
    }
    draw_grid(conversion(map, &i, &j), i , j, y);
    return (1);
}