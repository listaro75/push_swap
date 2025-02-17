/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:57:13 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/17 16:10:08 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_emp_min(t_pslist *a)
{
	int	emp;
	int	min;

	emp = 0;
	min = ft_val_min_a(a);
	while (a)
	{
		if (a->val == min)
			break ;
		a = a->next;
		emp++;
	}
	return (emp);
}

void	ft_end2(t_pslist **a)
{
	int	mid;
	int	size;
	int	emp_min;

	mid = ft_nombre(*a) / 2;
	size = ft_nombre(*a);
	emp_min = ft_emp_min(*a);
	if (emp_min < mid)
	{
		while (emp_min > 0)
		{
			ft_ra(a);
			emp_min--;
		}
	}
	else
	{
		while (size - emp_min > 0)
		{
			ft_rra(a);
			emp_min++;
		}
	}
}

void	ft_count_move(t_pslist **stack_a, t_pslist **stack_b)
{
	t_movelist	*move;
	t_cheaplist	*cheap;

	move = ft_calloc(sizeof(t_movelist), 1);
	cheap = ft_calloc(sizeof(t_cheaplist), 1);
	while ((*stack_b))
	{
		find_cheapest(stack_a, stack_b, &move, &cheap);
		ft_end(stack_a, stack_b, &cheap);
	}
	ft_end2(stack_a);
	return (free(move), free(cheap));
}

int	ft_nombre(t_pslist *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	bubble_sort(int *arr, int len)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
