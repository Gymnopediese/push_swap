/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:06:10 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 17:17:54 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_rest(t_stack *a, t_stack *b)
{
	int	max;
	int	smax;

	while (a->size)
	{
		max = ft_max(a->datas, a->size);
		smax = ft_max_less(a->datas, a->size, max);
		while (a->datas[a->size - 1] != max)
		{
			if (a->datas[a->size - 1] >= smax)
				apply("pb", "pa", a, b);
			if (a->datas[a->size - 2] == max)
				apply("sa", "sb", a, b);
			else if (ft_indexof_ia(a->datas, a->size, max) < a->size / 2)
				apply("rra", "rrb", a, b);
			else
				apply("ra", "rb", a, b);
		}
		apply("pb", "pa", a, b);
		if (b->size > 1 && b->datas[b->size - 1] > b->datas[b->size - 2])
			apply("sb", "sa", a, b);
	}
}
