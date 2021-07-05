/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_chnk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:42:41 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:50:24 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	nr_in_chnk(t_stk *stk, int pos_stk)
{
	int	i;

	i = stk->chnk_cnt - 1;
	if (stk->chnk_nr == stk->chnk_amount - 1 && stk->chnk_rest)
		i = i + stk->chnk_rest - stk->chnk_amount;
	while (i >= 0)
		if (stk->a[pos_stk] == stk->chnk[stk->chnk_nr][i--])
			return (1);
	return (0);
}

static int	hold_first_second(t_stk *stk, int *hold_first, int *hold_second)
{
	int	i;

	i = stk->ac - 1;
	while (i >= 0)
	{
		if (nr_in_chnk(stk, i))
		{
			*hold_first = stk->a[i];
			break ;
		}
		i--;
	}
	if (i == -1)
		return (-1);
	i = 0;
	while (i < stk->ac)
	{
		if (nr_in_chnk(stk, i))
		{
			*hold_second = stk->a[i];
			break ;
		}
		i++;
	}
	return (0);
}

static int	hold_first_closest(t_stk *stk, int hold_first, int hold_second)
{
	int	i;
	int	j;

	i = 0;
	while (stk->a[stk->ac - 1 - i] != hold_first)
		i++;
	j = 1;
	while (stk->a[j - 1] != hold_second)
		j++;
	if (i < j)
		return (1);
	return (0);
}

static void	adjust_b(t_stk *stk)
{
	int	lowest;
	int	highest;	

	lowest = lowest_nr_b(*stk);
	highest = highest_nr_b(*stk);
	if (stk->a[stk->ac - 1] < lowest)
		while (stk->b[stk->bc - 1] > lowest)
			rotate_b(stk, 1);
	else if (stk->a[stk->ac - 1] > highest)
		while (stk->b[stk->bc - 1] < highest)
			rotate_b(stk, 1);
}

void	clear_chnk(t_stk *stk)
{
	int	hold_first;
	int	hold_second;

	while (hold_first_second(stk, &hold_first, &hold_second) != -1)
	{
		if (hold_first_closest(stk, hold_first, hold_second))
			while (stk->a[stk->ac - 1] != hold_first)
				rotate_a(stk, 1);
		else
			while (stk->a[stk->ac - 1] != hold_second)
				rev_rotate_a(stk, 1);
		if (stk->bc != 0)
			adjust_b(stk);
		push_b(stk, 1);
	}
}
