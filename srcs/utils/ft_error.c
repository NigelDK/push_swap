/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:14 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:47:09 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(t_stk *stk)
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
	write(2, "Error\n", 6);
	exit (0);
}
