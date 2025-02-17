/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:49 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/17 15:41:59 by luda-cun         ###   ########.fr       */
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

void	ft_stack_a(t_pslist **stack_a, char **argv, int i)
{
	t_pslist	*current;
	t_pslist	*new_element;

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

void	ft_merge(t_pslist **f, t_pslist **s)
{
	t_pslist	*tmp;

	if (*f == NULL)
	{
		*f = *s;
		return ;
	}
	tmp = *f;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *s;
	*s = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	t_pslist	*stack_a_f;
	t_pslist	*stack_a_s;
	t_pslist	*stack_b;

	if (argc == 2)
	{
		if (ft_tab_to_stack(argv, &stack_a_f) == 1)
			return (ft_putstr_fd("Error", 2), 1);
	}
	else if (argc < 2 || ft_verif_digit(argv, 1) == 1 || ft_verif_doublon(argv,
			1) == 1 || ft_verif_int_max_min(argv, 1) == 1)
		return (ft_putstr_fd("Error", 2), 1);
	if (argc > 2)
		ft_stack_a(&stack_a_s, argv, 1);
	ft_merge(&stack_a_f, &stack_a_s);
	ft_algo_base(&stack_a_f, &stack_b);
	view(stack_a_f);
	view(stack_b);
	return (ft_free_stack(&stack_a_f), ft_free_stack(&stack_b), 0);
}
