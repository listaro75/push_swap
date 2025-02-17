/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:03 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/17 15:56:48 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheapest(t_pslist **a, t_pslist **b, t_movelist **m,
		t_cheaplist **p)
{
	t_pslist	*tmp;
	int			max_a;

	(*p)->cost = 9;
	tmp = *a;
	tmp = *b;
	max_a = ft_val_max_a(*a);
	(*p)->cost = 2147483647;
	while (tmp)
	{
		ft_top_b(tmp->val, m, b);
		if (max_a < tmp->val)
			ft_max_bottom(*a, m, max_a);
		else
			ft_good_insert(*a, m, tmp->val);
		tmp = tmp->next;
		ft_combine_rrr(m);
		ft_cheapmove(m, p);
	}
}

int	ft_val_max_a(t_pslist *a)
{
	int	res;

	res = -2147483648;
	while (a)
	{
		if (res < a->val)
			res = a->val;
		a = a->next;
	}
	return (res);
}

void	ft_end_p2(t_pslist **a, t_pslist **b, t_cheaplist **p)
{
	while ((*p)->rr > 0)
	{
		ft_rr(a, b);
		(*p)->rr--;
	}
	while ((*p)->rb > 0)
	{
		ft_rb(b);
		(*p)->rb--;
	}
	while ((*p)->rrb > 0)
	{
		ft_rrb(b);
		(*p)->rrb--;
	}
	while ((*p)->pa > 0)
	{
		ft_pa(a, b);
		(*p)->pa--;
	}
}

void	ft_end(t_pslist **a, t_pslist **b, t_cheaplist **p)
{
	while ((*p)->ra > 0)
	{
		ft_ra(a);
		(*p)->ra--;
	}
	while ((*p)->rra > 0)
	{
		ft_rra(a);
		(*p)->rra--;
	}
	while ((*p)->rrr > 0)
	{
		ft_rrr(a, b);
		(*p)->rrr--;
	}
	ft_end_p2(a, b, p);
}

int	ft_val_min_a(t_pslist *a)
{
	int	res;

	res = 2147483647;
	while (a)
	{
		if (res > a->val)
			res = a->val;
		a = a->next;
	}
	return (res);
}
