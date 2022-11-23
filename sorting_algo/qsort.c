/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:07:57 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 14:24:36 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#define PIVOT 2

/*
LESS OR EQUAL TO 100 PIVOT 3
*/


float	init_pivot(t_stack *a, int c)
{
	if (a->size < 50)
		return (2);
	else if (a->size < 200)
		return (3.2);
	else if (c == 1)
		return (2);
	else if (c == 2)
		return (3);
	else
		return (17);
}

void	empty_stack(t_stack *a, t_stack *b, int c)
{
	float		arr;
	int			pivot;
	int			iter;

	arr = init_pivot(a, c);
	while (a->size > 2)
	{
		if (c == 2)
			pivot = ft_elem_at_sia(a->datas, a->size,
					a->size - a->size / arr - 1);
		else
			pivot = ft_elem_at_sia(a->datas, a->size, a->size / arr);
		iter = a->size / arr;
		while (a->size > iter)
		{
			if ((c == 1 && goto_next_r(a, b, pivot) == 0)
				|| (c == 2 && goto_next_ru(a, b, pivot) == 0)
				|| (c == 3 && goto_next(a, b, pivot) == 0))
				break ;
		}
	}
}

void	ft_qsort_stack(t_stack *a, t_stack *b, int c)
{
	empty_stack(a, b, c);
	if (a->datas[0] < a->datas[1])
		apply("sa", "sa", a, b);
	if (c < 3 && b->size > 199)
		ft_qsort_stack(b, a, c + 1);
	else
		ft_sort_rest(b, a);
}
