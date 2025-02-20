/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:33:51 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/20 17:05:50 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tab_to_stack(char **argv, t_pslist **stack_a)
{
	char	**tab;

	tab = NULL;
	tab = ft_split(argv[1], ' ');
	if (ft_verif_digit(tab, 0) == 1 || ft_verif_doublon(tab, 0) == 1
		|| ft_verif_int_max_min(tab, 0) == 1)
		return (free_tab(tab), 1);
	ft_stack_a(stack_a, tab, 0);
	return (free_tab(tab), 0);
}

void	ft_tri_2(t_pslist *stack_a)
{
	if (stack_a->val > stack_a->next->val)
		ft_sa(&stack_a);
}
