/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:10:28 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/17 16:15:18 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_values_array(t_pslist *stack, int len)
{
	int			*values;
	int			i;
	t_pslist	*temp;

	values = (int *)malloc(len * sizeof(int));
	if (!values)
		return (NULL);
	temp = stack;
	i = 0;
	while (i < len)
	{
		values[i] = temp->val;
		temp = temp->next;
		i++;
	}
	return (values);
}

static int	calculate_median(int *values, int len)
{
	int	median;

	bubble_sort(values, len);
	if (len % 2 == 0)
		median = (values[len / 2 - 1] + values[len / 2]) / 2;
	else
		median = values[len / 2];
	return (median);
}

int	ft_mediane(t_pslist **stack)
{
	int	len;
	int	*values;
	int	median;

	len = ft_nombre(*stack);
	if (len == 0)
		return (0);
	values = get_values_array(*stack, len);
	if (!values)
		return (0);
	median = calculate_median(values, len);
	free(values);
	return (median);
}
