/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:27:41 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/26 23:59:30 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_grid(int **grid, int i, int j)
{
    int     q;
    int     w;
    int     skv;
    t_dot   *points;
    t_mlx   lx;
    int     kor;

    
    points = (t_dot*)malloc(sizeof(t_dot) * i * j);
    q = 0;
    w = 0;
    skv = 0;
    lx.mlx_ptr = mlx_init();
    lx.width = 1000;
    lx.height = 1000;
    while (q < i)
    {
        while (w < j)
        {
            points[skv].x = w * 20;
            points[skv].y = q * 20;
            points[skv].z = grid[q][w] * 5;
            projection(points, skv);
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
    while (q < (j * i - 1))
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
    mlx_hook(lx.win_ptr, 2, 0, deal_key, 0);
    mlx_loop(lx.mlx_ptr);

    // while (q < i)
    // {
    //     while (w < j)
    //     {
    //         printf("%d  ", grid[q][w]);
    //         w++;
    //     }
    //     printf("\n");
    //     q++;
    //     w = 0;
    // }
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
    draw_grid(conversion(map, &i, &j), i , j);
    return (1);
}