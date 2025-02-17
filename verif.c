/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:25:52 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/17 15:41:05 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_digit(char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				return (1);
			}
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (argv[i][j + 1] == '-' || argv[i][j + 1] == '+')
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_verif_doublon(char **argv, int i)
{
	int	j;

	j = i + 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_verif_int_max_min(char **argv, int i)
{
	int long	value;

	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		if (value > 2147483647 || value < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

void	view(t_pslist *stack)
{
	while (stack)
	{
		ft_printf("%d \n", stack->val);
		stack = stack->next;
	}
}
