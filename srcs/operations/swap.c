/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:27:54 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:58:42 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stk *stk, int p)
{
	int	i;
	int	tmp;

	if (stk->ac == 0 || stk->ac == 1)
		return ;
	i = stk->ac;
	i--;
	tmp = stk->a[i];
	stk->a[i] = stk->a[i - 1];
	stk->a[i - 1] = tmp;
	if (p == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_stk *stk, int p)
{
	int	i;
	int	tmp;

	if (stk->bc == 0 || stk->bc == 1)
		return ;
	i = stk->bc;
	i--;
	tmp = stk->b[i];
	stk->b[i] = stk->b[i - 1];
	stk->b[i - 1] = tmp;
	if (p == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stk *stk)
{
	swap_a(stk, 0);
	swap_b(stk, 0);
	write(1, "ss\n", 3);
}
