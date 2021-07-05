/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:40:01 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 13:36:26 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_double(t_stk *stk, int nr)
{
	int	i;
	int	j;

	i = stk->ac - 1;
	j = 0;
	while (i >= 0)
		if (stk->a[i--] == nr)
			j++;
	if (j > 1)
		return (1);
	return (0);
}

void	duplicate_check(t_stk *stk)
{
	int	i;

	i = stk->ac - 1;
	while (i >= 0)
		if (is_double(stk, stk->a[i--]))
			ft_error(stk);
}
