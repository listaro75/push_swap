/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:29:40 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 16:37:36 by luda-cun         ###   ########.fr       */
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
