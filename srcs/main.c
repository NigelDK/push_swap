/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:47:30 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 14:54:44 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_null(t_stk *stk)
{
	stk->a = NULL;
	stk->b = NULL;
	stk->chnk = NULL;
}

static void	end_free_all(t_stk *stk)
{
	int	i;

	if (stk->a)
		free(stk->a);
	if (stk->b)
		free(stk->b);
	i = -1;
	if (stk->chnk)
	{
		while (++i < stk->chnk_amount)
			free(stk->chnk[i]);
		free(stk->chnk);
	}
}

int	main(int argc, char **argv)
{
	t_stk	stk;

	if (!numeric(argc, argv))
		return (0);
	if (argc == 1)
		return (0);
	init_null(&stk);
	init_stk(argc, argv, &stk);
	duplicate_check(&stk);
	if (a_sorted(stk))
	{
		end_free_all(&stk);
		return (0);
	}
	if (stk.ac == 2)
		two_sorter(&stk);
	else if (stk.ac == 3)
		three_sorter(&stk);
	else if (stk.ac <= 5)
		five_sorter(&stk);
	else if (stk.ac > 5)
		big_sorter(&stk);
	end_free_all(&stk);
	return (0);
}
