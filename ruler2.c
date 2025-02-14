/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:29:40 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 18:55:55 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_pslist **a)
{
	t_pslist	*tmp;
	t_pslist	*last;

	if (!(*a) || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_pslist **b)
{
	t_pslist	*tmp;
	t_pslist	*last;

	if (!(*b) || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_pslist **a, t_pslist **b)
{
	t_pslist	*tmp;
	t_pslist	*last;

	if ((!(*a) || !((*a)->next)) || (!(*b) || !((*b)->next)))
	{
		return (ft_ra(&*a), ft_rb(&*b));
	}
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_putstr_fd("rr\n", 1);
}

void	ft_rra(t_pslist **a)
{
	t_pslist	*last;
	t_pslist	*second_last;

	if (!(*a) || !((*a)->next))
		return ;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_pslist **b)
{
	t_pslist	*last;
	t_pslist	*second_last;

	if (!(*b) || !((*b)->next))
		return ;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	ft_putstr_fd("rrb\n", 1);
}
