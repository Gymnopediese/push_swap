/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:34:59 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 14:49:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/push_swap.h"

void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	loop;

	loop = -1;
	a->name = 'a';
	b->name = 'b';
	a->nname = 'b';
	b->nname = 'a';
	a->datas = allok(argc, sizeof(int), 1);
	b->datas = allok(argc, sizeof(int), 1);
	while (++loop < argc - 1)
	{
		a->datas[argc - 2 - loop] = ft_atoli(argv[loop + 1]);
		if (a->datas[argc - 2 - loop] > MAXINT
			|| a->datas[argc - 2 - loop] < MININT)
			loop = MAXINT;
	}
	a->size = argc - 1;
	b->size = 0;
	if (!is_valid(*a, argv) || loop == MAXINT)
		ft_garbage_colector(0, 1, 1);
}
