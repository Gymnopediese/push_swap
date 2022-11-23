/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:41:03 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 11:44:28 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	are_all_vaild(char **tar)
{
	char	**all;
	int		is;

	all = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	is = ft_all_str_in_sa(tar, all);
	ft_free_pp((void **) all);
	return (is);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		loop;
	char	**inst;

	ft_init_stack(&a, &b, argc, argv);
	inst = ft_read_lignes_fd(0);
	loop = -1;
	if (!are_all_vaild(inst))
	{
		ft_putendl("Error");
		return (0);
	}
	while (inst[++loop])
		apply(inst[loop], 0, &a, &b);
	ft_free_pp((void **)inst);
	if (ft_is_sort_ia(a.datas, a.size, -1))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
