/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsortops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:45:18 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 12:47:07 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	find_next_qsort(t_stack *a, int pivot)
{
	int	i;
	int	e;

	i = 0;
	e = a->size - 1;
	while (i <= a->size / 2)
	{
		if (a->datas[i] <= pivot)
			return (i + 1);
		if (a->datas[e] <= pivot)
			return (e - a->size + 1);
		i++;
		e--;
	}
	return (2147483648);
}

int	goto_next_ru(t_stack *a, t_stack *b, int pivot)
{
	if (ft_max(a->datas, a->size) < pivot)
		return (0);
	while (a->datas[a->size - 1] < pivot)
		apply("ra", "rb", a, b);
	apply("pb", "pa", a, b);
	return (1);
}

int	goto_next_r(t_stack *a, t_stack *b, int pivot)
{
	if (ft_min(a->datas, a->size) > pivot)
		return (0);
	while (a->datas[a->size - 1] > pivot)
		apply("ra", "ra", a, b);
	apply("pb", "pb", a, b);
	return (1);
}

int	goto_next(t_stack *a, t_stack *b, int pivot)
{
	long	next;

	next = find_next_qsort(a, pivot);
	if (next == 2147483648)
		return (0);
	while (next > 0 && next--)
		apply("rra", "rra", a, b);
	while (next < 0 && next++)
		apply("ra", "ra", a, b);
	apply("pb", "pb", a, b);
	return (1);
}
