/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:06:40 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:59:11 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(t_stk *stk, int p)
{
	int	i;
	int	tmp;

	if (stk->ac == 0 || stk->ac == 1)
		return ;
	i = stk->ac;
	i--;
	tmp = stk->a[i];
	while (--i >= 0)
		stk->a[i + 1] = stk->a[i];
	stk->a[0] = tmp;
	if (p == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stk *stk, int p)
{
	int	i;
	int	tmp;

	if (stk->bc == 0 || stk->bc == 1)
		return ;
	i = stk->bc;
	i--;
	tmp = stk->b[i];
	while (--i >= 0)
		stk->b[i + 1] = stk->b[i];
	stk->b[0] = tmp;
	if (p == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stk *stk)
{
	rotate_a(stk, 0);
	rotate_b(stk, 0);
	write(1, "rr\n", 3);
}
