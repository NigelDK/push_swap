/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:31:22 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/22 15:09:23 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	two_sorter(t_stk *stk)
{
	if (stk->a[1] > stk->a[0])
		swap_a(stk, 1);
}

void	three_sorter(t_stk *stk)
{
	if (stk->a[1] == lowest_nr_a(*stk) && stk->a[2] < stk->a[0])
		swap_a(stk, 1);
	else if (stk->a[0] == lowest_nr_a(*stk) && stk->a[2] > stk->a[1])
	{
		swap_a(stk, 1);
		rev_rotate_a(stk, 1);
	}
	else if (stk->a[1] == lowest_nr_a(*stk) && stk->a[2] > stk->a[0])
		rotate_a(stk, 1);
	else if (stk->a[2] == lowest_nr_a(*stk) && stk->a[1] > stk->a[0])
	{
		swap_a(stk, 1);
		rotate_a(stk, 1);
	}
	else if (stk->a[0] == lowest_nr_a(*stk) && stk->a[2] < stk->a[1])
		rev_rotate_a(stk, 1);
}

void	sorter(t_stk *stk)
{
	int	low;

	low = lowest_nr_a(*stk);
	while (stk->ac > 1)
	{
		if (stk->a[stk->ac - 1] > stk->a[stk->ac - 2])
			swap_a(stk, 0);
		if (stk->a[stk->ac - 1] == low)
		{
			push_b(stk, 0);
			low = lowest_nr_a(*stk);
		}
		if (stk->ac >= 2 && stk->a[stk->ac - 2] == low)
			rotate_a(stk, 0);
		else
			rev_rotate_a(stk, 0);
	}
	while (stk->bc > 0)
		push_a(stk, 0);
}
