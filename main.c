/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:49 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 09:39:06 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_digit(char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[i][j])
	{
		if (ft_isdigit(argv[i][j]) == 0)
			return (1);
		j++;
	}
	return (0);
}

int	ft_verif_doublon(int *a, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < index)
	{
		while (j < index)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	*ft_init_array(char **argv, int index)
{
	int	*a;
	int	i;

	i = 0;
	a = (int *)malloc((index) * sizeof(int));
	if (!a)
		return (NULL);
	while (i < index)
	{
		if (ft_verif_digit(argv, i + 1) == 1)
			return (free(a), NULL);
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	i;
	int	h;
	int	index_a;
	int	index_b;

	i = 0;
	h = 0;
	index_a = argc - 1;
	index_b = 1;
	if (argc < 2)
	{
		ft_printf("error");
		return (1);
	}
	a = ft_init_array(argv, index_a);
	b = ft_init_array(argv, index_b);
	if (!a || !b)
		return (ft_putstr_fd("error", 1), free(a), free(b), 1);
	if (ft_verif_doublon(a, index_a) == 1)
		return (ft_putstr_fd("error", 1), free(a), 1);
	ft_putstr_fd("| A  | B |\n", 1);
	while (h < index_a)
	{
		ft_printf("| %d  ", a[h]);
		ft_printf("| %d |\n", b[h++]);
	}
	free(a);
	return (0);
}
