/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:59:24 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/22 16:33:05 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_sort(t_stk *stk, t_stk *tmp)
{
	int		i;

	tmp->ac = stk->ac;
	tmp->bc = stk->bc;
	tmp->a = malloc(sizeof(int) * (stk->ac));
	if (!tmp->a)
		ft_error(stk);
	tmp->b = malloc(sizeof(int) * (stk->ac));
	if (!tmp->b)
	{
		free(tmp->a);
		ft_error(stk);
	}
	i = -1;
	while (++i < stk->ac)
		tmp->a[i] = stk->a[i];
	sorter(tmp);
}

void	chunker(t_stk *stk)
{
	t_stk	tmp;
	int		i;
	int		j;
	int		k;

	init_sort(stk, &tmp);
	j = tmp.ac - 1;
	k = 0;
	while (k < stk->chnk_amount)
	{
		i = stk->chnk_cnt - 1;
		if (k == stk->chnk_amount - 1 && stk->chnk_rest)
			i = i + stk->chnk_rest - stk->chnk_amount;
		while (i >= 0 && j >= 0)
			stk->chnk[k][i--] = tmp.a[j--];
		k++;
	}
	free(tmp.a);
	free(tmp.b);
}
