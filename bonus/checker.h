/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:18:44 by albaud            #+#    #+#             */
/*   Updated: 2022/11/07 13:19:55 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../koflibc/sources.h"

typedef struct s_stack
{
	int		*datas;
	char	name;
	char	nname;
	int		size;
}	t_stack;

void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv);
void	apply(char *action, char *print, t_stack *a, t_stack *b);


#endif