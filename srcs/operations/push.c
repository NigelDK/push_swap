/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:05:58 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:59:57 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(t_stk *stk, int p)
{
	if (stk->bc == 0)
		return ;
	stk->a[stk->ac++] = stk->b[--stk->bc];
	if (p == 1)
		write(1, "pa\n", 3);
}

void	push_b(t_stk *stk, int p)
{
	if (stk->ac == 0)
		return ;
	stk->b[stk->bc++] = stk->a[--stk->ac];
	if (p == 1)
		write(1, "pb\n", 3);
}
