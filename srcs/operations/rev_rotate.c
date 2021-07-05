/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:49:17 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/22 14:52:39 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rotate_a(t_stk *stk, int p)
{
	int	i;
	int	tmp;

	if (stk->ac == 0 || stk->ac == 1)
		return ;
	i = 0;
	tmp = stk->a[i];
	while (++i < stk->ac)
		stk->a[i - 1] = stk->a[i];
	stk->a[--i] = tmp;
	if (p == 1)
		write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stk *stk, int p)
{
	int	i;
	int	tmp;

	if (stk->bc == 0 || stk->bc == 1)
		return ;
	i = 0;
	tmp = stk->b[i];
	while (++i < stk->bc)
		stk->b[i - 1] = stk->b[i];
	stk->b[--i] = tmp;
	if (p == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stk *stk)
{
	rev_rotate_a(stk, 0);
	rev_rotate_b(stk, 0);
	write(1, "rrr\n", 4);
}
