/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:38:42 by nde-koni          #+#    #+#             */
/*   Updated: 2021/05/23 14:07:02 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stk
{
	int	*a;
	int	ac;
	int	*b;
	int	bc;
	int	**chnk;
	int	chnk_amount;
	int	chnk_cnt;
	int	chnk_nr;
	int	chnk_rest;
}				t_stk;

void	swap_a(t_stk *stk, int p);
void	swap_b(t_stk *stk, int p);
void	ss(t_stk *stk);
void	push_a(t_stk *stk, int p);
void	push_b(t_stk *stk, int p);
void	rotate_a(t_stk *stk, int p);
void	rotate_b(t_stk *stk, int p);
void	rr(t_stk *stk);
void	rev_rotate_a(t_stk *stk, int p);
void	rev_rotate_b(t_stk *stk, int p);
void	rrr(t_stk *stk);
int		lowest_nr_a(t_stk stk);
int		highest_nr_a(t_stk stk);
int		a_sorted(t_stk stk);
void	sorter(t_stk *stk);
void	two_sorter(t_stk *stk);
void	three_sorter(t_stk *stk);
void	five_sorter(t_stk *stk);
void	big_sorter(t_stk *stk);
void	init_stk(int argc, char **argv, t_stk *stk);
void	ft_error(t_stk *stk);
void	chunker(t_stk *stk);
int		lowest_nr_b(t_stk stk);
int		highest_nr_b(t_stk stk);
void	clear_chnk(t_stk *stk);
void	ft_free_tab_int(int **tab, int j);
void	ft_free_tab(char **tab, int j);
int		numeric(int argc, char **argv);
int		tab_cnt(char **tab2);
void	duplicate_check(t_stk *stk);
long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);

#endif