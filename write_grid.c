/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:24:55 by bkiehn            #+#    #+#             */
/*   Updated: 2019/01/29 20:52:38 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		letter_to_dec(char hex)
{
	if (hex == 'a' || hex == 'A')
    	return (10);
    if (hex == 'b' || hex == 'B')
        return (11);
    if (hex == 'c' || hex == 'C')
        return (12);
    if (hex == 'd' || hex == 'D')
        return (13);
    if (hex == 'e' || hex == 'E')
        return(14);
    if (hex == 'f' || hex == 'F')
        return (15);
    return (0);
}

int     hex_to_dec(char *str)
{
    int i;
    int l;
    int s;
    
    s = 0;
    i = 0;
    l = ft_strlen(str) - 1;
    while (str[i] != 0)
        if (str[i++] == ',')
        {
            i = 0;
            while (str[l] != 'x')
            {
                if (str[l] > 47 & str[l] < 58)
                    s = s + (str[l] - 48) * pow(16, i);
                else if ((str[l] > 64 & str[l] < 71) || (str[l] > 96 & str[l] < 103))
                    s = s + letter_to_dec(str[l]) * pow(16, i);
                l--;
                i++;
            }
            break;
        }
    return (s);
}

t_dot   *selec(t_dot **grid)
{
    t_dot   *knot;
    t_dot   *tmp;

    if (*grid == 0)
    {
        *grid = (t_dot*)malloc(sizeof(t_dot));
        knot = *grid;
    }
    else
    {
        knot = *grid;
        while (knot)
        {
            tmp = knot;
            knot = knot->next;
        }
        knot = (t_dot*)malloc(sizeof(t_dot));
        tmp->next = knot;
    }
    return (knot);
}

void    write_grid(t_dot **grid, int y, char **line)
{
    int     i;
    t_dot   *knot;

    knot = selec(grid);
    i = 0;
    while (line[i] != 0)
    {
        knot->y = y;
        knot->x = i;
        knot->z = ft_atoi(line[i]);
        knot->color = hex_to_dec(line[i]);
        i++;
        if (line[i] != 0)
            knot->next = (t_dot*)malloc(sizeof(t_dot));
        else
            knot->next = 0;
        knot = knot->next;
    }
}
