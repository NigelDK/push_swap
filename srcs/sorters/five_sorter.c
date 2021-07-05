/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 08:42:35 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:54:48 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	lowest_rotation(t_stk *stk, int lowest)
{
	if (stk->a[stk->ac - 2] == lowest)
		while (stk->a[stk->ac - 1] != lowest)
			rotate_a(stk, 1);
	else
		while (stk->a[stk->ac - 1] != lowest)
			rev_rotate_a(stk, 1);
}

static void	highest_rotation(t_stk *stk, int highest)
{
	if (stk->a[1] == highest || stk->a[2] == highest)
		while (stk->a[0] != highest)
			rev_rotate_a(stk, 1);
	else
		while (stk->a[0] != highest)
			rotate_a(stk, 1);
}

static void	sorting(t_stk *stk)
{
	int	lowest;
	int	highest;	

	lowest = lowest_nr_a(*stk);
	highest = highest_nr_a(*stk);
	if (stk->b[stk->bc - 1] < lowest)
		lowest_rotation(stk, lowest);
	else if (stk->b[stk->bc - 1] > highest)
		highest_rotation(stk, highest);
	else
	{
		if (stk->a[stk->ac - 2] > stk->b[stk->bc - 1])
		{
			while (stk->a[stk->ac - 1] < stk->b[stk->bc - 1]
				|| stk->a[0] > stk->b[stk->bc - 1])
				rotate_a(stk, 1);
		}
		else
		{
			while (stk->a[stk->ac - 1] < stk->b[stk->bc - 1]
				|| stk->a[0] > stk->b[stk->bc - 1])
				rev_rotate_a(stk, 1);
		}
	}
	push_a(stk, 1);
}

static void	end_sort_a(t_stk *stk)
{
	int	lowest;

	lowest = lowest_nr_a(*stk);
	if (stk->a[stk->ac - 2] == lowest || stk->a[stk->ac - 3] == lowest)
	{
		while (stk->a[stk->ac - 1] != lowest)
			rotate_a(stk, 1);
	}
	else
		while (stk->a[stk->ac - 1] != lowest)
			rev_rotate_a(stk, 1);
}

void	five_sorter(t_stk *stk)
{
	if (stk->ac == 5)
		push_b(stk, 1);
	push_b(stk, 1);
	three_sorter(stk);
	while (stk->bc)
		sorting(stk);
	end_sort_a(stk);
}
