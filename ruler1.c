/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:07:19 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 09:51:30 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa
void	ft_swap_a(int *a)
{
	int	i;

	i = a[0];
	a[0] = a[1];
	a[1] = i;
}

// sb
void	ft_swap_b(int *b)
{
	int	i;

	i = b[0];
	b[0] = b[1];
	b[1] = i;
}

// ss
void	ft_swap_a_b(int *a, int *b)
{
	ft_swap_a(a);
	ft_swap_b(b);
}

void	ft_push_a(int *a, int *b, int .index_a, int index_b)
