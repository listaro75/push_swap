/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:44:01 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/17 15:46:34 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_closest(t_pslist *a, int val)
{
	int	closest;

	closest = 2147483647;
	while (a)
	{
		if (a->val > val && a->val < closest)
			closest = a->val;
		a = a->next;
	}
	return (closest);
}

void	ft_good_insert(t_pslist *a, t_movelist **m, int val)
{
	int	nbr;
	int	i;
	int	size;

	i = 0;
	(*m)->ra = 0;
	(*m)->rra = 0;
	nbr = ft_find_closest(a, val);
	size = ft_nombre(a);
	while (a)
	{
		if (a->val == nbr)
			break ;
		a = a->next;
		i++;
	}
	if (i < size / 2)
		(*m)->ra = i;
	else
		(*m)->rra = size - i;
}

void	ft_max_bottom(t_pslist *a, t_movelist **m, int max_a)
{
	int	i;
	int	size;

	size = ft_nombre(a);
	(*m)->ra = 0;
	(*m)->rra = 0;
	i = 0;
	while (a)
	{
		if (a->val == max_a)
			break ;
		i++;
		a = a->next;
	}
	if (i > size / 2)
		(*m)->rra = size - i - 1;
	else
		(*m)->ra = i + 1;
}

void	ft_combine_rrr(t_movelist **m)
{
	(*m)->rr = 0;
	(*m)->rrr = 0;
	while ((*m)->ra != 0 && (*m)->rb != 0)
	{
		(*m)->ra--;
		(*m)->rb--;
		(*m)->rr++;
	}
	while ((*m)->rra != 0 && (*m)->rrb != 0)
	{
		(*m)->rra--;
		(*m)->rrb--;
		(*m)->rrr++;
	}
}

void	ft_cheapmove(t_movelist **m, t_cheaplist **p)
{
	(*m)->cost = (*m)->ra + (*m)->rra + (*m)->rb + (*m)->rrb + (*m)->rrr
		+ (*m)->rr + (*m)->pa;
	if ((*m)->cost < (*p)->cost)
	{
		(*p)->ra = (*m)->ra;
		(*p)->rra = (*m)->rra;
		(*p)->rb = (*m)->rb;
		(*p)->rrb = (*m)->rrb;
		(*p)->rrr = (*m)->rrr;
		(*p)->rr = (*m)->rr;
		(*p)->pa = (*m)->pa;
		(*p)->cost = (*m)->cost;
	}
}
