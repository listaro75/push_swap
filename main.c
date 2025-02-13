/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:49 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 14:30:12 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_pslist **stack)
{
	t_pslist	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}



void	ft_stack_a(t_pslist **stack_a, char **argv)
{
	int			i;
	t_pslist	*current;
	t_pslist	*new_element;

	i = 1;
	while (argv[i])
	{
		new_element = ft_add_val(atoi(argv[i]));
		if (!new_element)
			return ;
		if (*stack_a == NULL)
			*stack_a = new_element;
		else
		{
			current = *stack_a;
			while (current->next)
				current = current->next;
			current->next = new_element;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || ft_verif_digit(argv) == 1 || ft_verif_doublon(argv) == 1)
		return (ft_putstr_fd("error", 2), 1);
	ft_stack_a(&stack_a, argv);
	ft_pb(&stack_b, &stack_a);
	ft_pb(&stack_b, &stack_a);
	ft_ss(&stack_a, &stack_b);
	ft_pa(&stack_a, &stack_b);

	view(stack_a);
	ft_putstr_fd("--------------------\n",1);
	view(stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
