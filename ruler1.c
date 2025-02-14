/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:09:57 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 18:54:57 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_pslist **stack_a)
{
	t_pslist	*tmp;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_pslist **stack_b)
{
	t_pslist	*tmp;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_pslist **a, t_pslist **b)
{
	t_pslist	*tmpa;
	t_pslist	*tmpb;

	if ((!(*a) || !((*a)->next)) || (!(*b) || !((*b)->next)))
	{
		return (ft_sa(&*a), ft_sb(&*b));
	}
	tmpa = (*a)->next;
	tmpb = (*b)->next;
	(*a)->next = tmpa->next;
	(*b)->next = tmpb->next;
	tmpa->next = *a;
	tmpb->next = *b;
	*a = tmpa;
	*b = tmpb;
	ft_putstr_fd("ss\n", 1);
}

void	ft_pa(t_pslist **a, t_pslist **b)
{
	t_pslist	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_pslist **b, t_pslist **a)
{
	t_pslist	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_putstr_fd("pb\n", 1);
}
