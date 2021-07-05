/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:01:11 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:58:30 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ra_else_rra(t_stk *stk, int highest)
{
	int	i;
	int	j;

	i = 0;
	while (stk->b[stk->bc - 1 - i] != highest)
		i++;
	j = 1;
	while (stk->b[j - 1] != highest)
		j++;
	if (i < j)
		return (1);
	return (0);
}

void	big_sorter(t_stk *stk)
{
	int	highest;

	chunker(stk);
	while (stk->chnk_nr < stk->chnk_amount)
	{
		clear_chnk(stk);
		stk->chnk_nr++;
	}
	while (stk->bc)
	{
		highest = highest_nr_b(*stk);
		if (ra_else_rra(stk, highest))
			while (stk->b[stk->bc - 1] != highest)
				rotate_b(stk, 1);
		else
			while (stk->b[stk->bc - 1] != highest)
				rev_rotate_b(stk, 1);
		push_a(stk, 1);
	}
}
