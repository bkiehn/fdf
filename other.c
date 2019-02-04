/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 20:25:01 by bkiehn            #+#    #+#             */
/*   Updated: 2019/02/04 21:09:23 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_list(t_mlx *lx)
{
	t_dot	*lst;
	t_dot	*tmp;

	lst = lx->dots;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = 0;
		lst = tmp;
	}
	exit(0);
}

void	b_z(t_color *start, t_color *end, t_dot *a, t_dot *b)
{
	start->x = a->x_c;
	start->y = a->y_c;
	end->x = b->x_c;
	end->y = b->y_c;
}

void	a_z(t_color *start, t_color *end, t_dot *a, t_dot *b)
{
	start->x = b->x_c;
	start->y = b->y_c;
	end->x = a->x_c;
	end->y = a->y_c;
}
