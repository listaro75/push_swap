/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:09:51 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 17:12:55 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_rrr(t_pslist **a, t_pslist **b)
{
	t_pslist	*last;
	t_pslist	*second_last;

	if ((!(*a) || !((*a)->next)) || (!(*b) || !((*b)->next)))
	{
		return (ft_rra(&*a), ft_rrb(&*b));
	}
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	ft_putstr_fd("rrr\n", 1);
}
