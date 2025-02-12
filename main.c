/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:12:49 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/12 14:59:35 by luda-cun         ###   ########.fr       */
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

int	ft_verif_doublon(int *a, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < argc - 1)
	{
		while (j < argc - 1)
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

int	*ft_init_array(char **argv, int argc)
{
	int	*a;
	int	i;

	i = 0;
	a = (int *)malloc((argc - 1) * sizeof(int));
	if (!a)
		return (NULL);
	while (i < argc - 1)
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
	int	i;
	int	h;

	i = 0;
	h = 0;
	if (argc < 3)
	{
		ft_printf("error");
		return (1);
	}
	a = ft_init_array(argv, argc);
	if (!a)
		return (ft_putstr_fd("error", 1), free(a), 1);
	if (ft_verif_doublon(a, argc) == 1)
		return (ft_putstr_fd("error", 1), free(a), 1);
	while (h < argc - 1)
		ft_printf("%d \n", a[h++]);
	free(a);
	return (0);
}
