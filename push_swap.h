/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:58:04 by albaud            #+#    #+#             */
/*   Updated: 2022/11/08 14:24:49 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../koflibc/sources.h"

typedef struct s_stack
{
	int		*datas;
	char	name;
	char	nname;
	int		size;
}	t_stack;


int		is_valid(t_stack a, char **argv);;
void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv);
void	ft_qsort_stack(t_stack *a, t_stack *b, int c);
long	find_next_qsort(t_stack *a, int pivot);
void	ft_sort_rest(t_stack *a, t_stack *b);
void	ft_putchars(char a, char b, char c);
void	ft_radix_sort(t_stack *a, t_stack *b, int index, int count);
void	counter(int mode);
void	apply(char *action, char *print, t_stack *a, t_stack *b);

long	find_next_qsort(t_stack *a, int pivot);
int		goto_next_ru(t_stack *a, t_stack *b, int pivot);
int		goto_next_r(t_stack *a, t_stack *b, int pivot);
int		goto_next(t_stack *a, t_stack *b, int pivot);

#endif