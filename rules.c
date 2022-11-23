/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:57:09 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 11:49:30 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/push_swap.h"

void	rotate(t_stack *a)
{
	int	i;

	i = -1;
	ft_swap(&a->datas[0], &a->datas[a->size - 1]);
	while (++i < a->size - 2)
	{
		ft_swap(&a->datas[a->size - 1 - i], &a->datas[a->size - 2 - i]);
	}
}

void	rrotate(t_stack *a)
{
	int	i;

	i = -1;
	ft_swap(&a->datas[0], &a->datas[a->size - 1]);
	while (++i < a->size - 2)
	{
		ft_swap(&a->datas[i], &a->datas[i + 1]);
	}
}

void	counter(int mode)
{
	static int	count;

	if (mode)
	{
		ft_putnbrn(count);
		return ;
	}
	else
		count++;
}

void	apply(char *action, char *print, t_stack *a, t_stack *b)
{
	if ((!ft_strcmp(action, "sa") || !ft_strcmp(action, "ss")) && a->size > 1)
		ft_swap(&a->datas[a->size - 2], &a->datas[a->size - 1]);
	if ((!ft_strcmp(action, "sb") || !ft_strcmp(action, "ss")) && b->size > 1)
		ft_swap(&b->datas[b->size - 2], &b->datas[b->size - 1]);
	if (!ft_strcmp(action, "pa") && b->size)
		ft_swap(&a->datas[a->size++], &b->datas[--b->size]);
	if (!ft_strcmp(action, "pb") && a->size)
		ft_swap(&a->datas[--a->size], &b->datas[b->size++]);
	if ((!ft_strcmp(action, "ra") || !ft_strcmp(action, "rr")) && a->size > 1)
		rotate(a);
	if ((!ft_strcmp(action, "rb") || !ft_strcmp(action, "rr")) && b->size > 1)
		rotate(b);
	if ((!ft_strcmp(action, "rra") || !ft_strcmp(action, "rrr")) && a->size > 1)
		rrotate(a);
	if ((!ft_strcmp(action, "rrb") || !ft_strcmp(action, "rrr")) && b->size > 1)
		rrotate(b);
	if (print)
		ft_putendl(print);
	counter(0);
}

int	is_valid(t_stack a, char **argv)
{
	if (ft_doublons_ia(a.datas, a.size))
	{
		ft_putendl("Error");
		return (0);
	}
	if (!ft_are_all_num(&argv[1]))
	{
		ft_putendl("Error");
		return (0);
	}
	return (1);
}
