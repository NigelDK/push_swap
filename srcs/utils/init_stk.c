/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:07:56 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 11:31:36 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	fill_array(t_stk *stk, char **nrs)
{
	int			i;
	int			j;
	long long	tmp;

	i = 0;
	j = stk->ac - 1;
	while (i < stk->ac)
	{
		tmp = ft_atol(nrs[i++]);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			i = 0;
			while (i < stk->ac)
				free(nrs[i++]);
			free(nrs);
			ft_error(stk);
		}
		stk->a[j--] = tmp;
	}	
}

static void	str_init(char **argv, t_stk *stk)
{
	char	**nrs;
	int		i;

	nrs = ft_split(argv[1], ' ');
	if (!nrs)
		ft_error(stk);
	stk->ac = tab_cnt(nrs);
	stk->bc = 0;
	stk->a = malloc(sizeof(int) * (stk->ac));
	stk->b = malloc(sizeof(int) * (stk->ac));
	if (!stk->a || !stk->b)
	{
		ft_free_tab(nrs, stk->ac);
		ft_error(stk);
	}
	fill_array(stk, nrs);
	i = 0;
	while (i < stk->ac)
		free(nrs[i++]);
	free(nrs);
}

static void	argv_init(int argc, char **argv, t_stk *stk)
{
	int		i;
	int		j;	
	long	tmp;

	stk->ac = argc - 1;
	stk->bc = 0;
	stk->a = malloc(sizeof(int) * (stk->ac));
	stk->b = malloc(sizeof(int) * (stk->ac));
	if (!stk->a || !stk->b)
		ft_error(stk);
	i = 1;
	j = argc - 2;
	while (i < argc)
	{
		tmp = ft_atol(argv[i++]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ft_error(stk);
		stk->a[j--] = tmp;
	}
}

static void	chnk_init(t_stk *stk)
{
	int	i;

	i = -1;
	stk->chnk_nr = 0;
	if (stk->ac > 5 && stk->ac <= 100)
		stk->chnk_amount = 5;
	else if (stk->ac > 100)
		stk->chnk_amount = 11;
	stk->chnk_cnt = stk->ac / stk->chnk_amount;
	stk->chnk_rest = stk->ac % stk->chnk_amount;
	if (stk->chnk_rest)
		stk->chnk_cnt++;
	stk->chnk = malloc(sizeof(int *) * stk->chnk_amount);
	if (!stk->chnk)
		ft_error(stk);
	while (++i < stk->chnk_amount)
	{
		stk->chnk[i] = malloc(sizeof(int) * stk->chnk_cnt);
		if (!stk->chnk[i])
		{
			ft_free_tab_int(stk->chnk, i);
			ft_error(stk);
		}
	}
}

void	init_stk(int argc, char **argv, t_stk *stk)
{
	if (argc == 2)
		str_init(argv, stk);
	else
		argv_init(argc, argv, stk);
	if (stk->ac > 5)
		chnk_init(stk);
}
