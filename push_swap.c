/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:14:30 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 14:25:01 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_init_sorts(t_stack *a, t_inta *s)
// {
// 	s->arr = ft_iadup(a->datas, a->size);
// 	s->size = a->size;
// 	ft_garbage_colector(s->arr, 0, 1);
// 	ft_bubble_sort(s->arr, s->size);
// }

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	ft_init_stack(&a, &b, argc, argv);
	ft_qsort_stack(&a, &b, 1);
	ft_garbage_colector(0, 1, 0);
	return (0);
}
