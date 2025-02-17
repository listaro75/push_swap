/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:17:54 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/17 16:14:59 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tri(t_pslist **t)
{
	int	a;
	int	b;
	int	c;

	a = (*t)->val;
	b = (*t)->next->val;
	c = (*t)->next->next->val;
	if (a > b && a < c)
		ft_sa(t);
	else if (a < b && a > c)
		ft_rra(t);
	else if (a > b && b > c)
	{
		ft_ra(t);
		ft_sa(t);
	}
	else if (a > b && b < c)
		ft_ra(t);
	else if (a < b && b > c)
	{
		ft_rra(t);
		ft_sa(t);
	}
}

void	ft_algo_base(t_pslist **stack_a, t_pslist **stack_b)
{
	int	median;
	int	len;

	len = ft_nombre(*stack_a);
	if (len <= 3)
		return (ft_tri(stack_a));
	median = ft_mediane(stack_a);
	while (ft_nombre(*stack_a) > 3)
	{
		ft_pb(stack_b, stack_a);
		if ((*stack_b)->val > median)
			ft_rb(stack_b);
	}
	ft_tri(stack_a);
	ft_count_move(stack_a, stack_b);
}

void	ft_top_b(int value, t_movelist **m, t_pslist **b)
{
	t_pslist	*tmp;
	int			i;
	int			size;

	tmp = (*b);
	i = 0;
	(*m)->rb = 0;
	(*m)->rrb = 0;
	(*m)->pa = 1;
	while (tmp)
	{
		if (tmp->val == value)
			break ;
		tmp = tmp->next;
		i++;
	}
	size = ft_nombre((*b));
	if (i < size / 2)
		(*m)->rb = i;
	else
		(*m)->rrb = size - i;
}
