/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:17:54 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/14 04:13:05 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fonction permettamt de retouner la valeur la plus proche en positif de val
int	ft_find_closest(t_pslist *a, int val)
{
	int	closest;

	closest = 2147483647;
	while (a)
	{
		if (a->val > val && a->val < closest)
			closest = a->val;
		a = a->next;
	}
	return (closest);
}

//// fonction qui permet de mettre en dessous de la valeur la plus proche de a->val

void	ft_good_insert(t_pslist *a, t_movelist **m, int val)
{
	int	nbr;
	int	i;
	int	size;

	i = 0;
	(*m)->ra = 0;
	(*m)->rra = 0;
	nbr = ft_find_closest(a, val);
	size = ft_nombre(a);
	while (a)
	{
		if (a->val == nbr)
			break ;
		a = a->next;
		i++;
	}
	if (i < size / 2)
		(*m)->ra = i;
	else
		(*m)->rra = size - i;
	// printf("nbr = %d", nbr);
}
// le nombre de ra a faire si max_a est plus petit que stack_b_val
void	ft_max_bottom(t_pslist *a, t_movelist **m, int max_a)
{
	int	i;
	int	size;

	size = ft_nombre(a);
	(*m)->ra = 0;
	(*m)->rra = 0;
	i = 0;
	while (a)
	{
		if (a->val == max_a)
			break ;
		i++;
		a = a->next;
	}
	if (i > size / 2)
		(*m)->rra = size - i - 1;
	else
		(*m)->ra = i + 1;
}

void	ft_combine_rrr(t_movelist **m)
{
	(*m)->rr = 0;
	(*m)->rrr = 0;
	while ((*m)->ra != 0 && (*m)->rb != 0)
	{
		(*m)->ra--;
		(*m)->rb--;
		(*m)->rr++;
	}
	while ((*m)->rra != 0 && (*m)->rrb != 0)
	{
		(*m)->rra--;
		(*m)->rrb--;
		(*m)->rrr++;
	}
}
// fonmction qui compare les couts
void	ft_cheapmove(t_movelist **m, t_cheaplist **p)
{
	(*m)->cost = (*m)->ra + (*m)->rra + (*m)->rb + (*m)->rrb + (*m)->rrr
		+ (*m)->rr + (*m)->pa;
	if ((*m)->cost < (*p)->cost)
	{
		(*p)->ra = (*m)->ra;
		(*p)->rra = (*m)->rra;
		(*p)->rb = (*m)->rb;
		(*p)->rrb = (*m)->rrb;
		(*p)->rrr = (*m)->rrr;
		(*p)->rr = (*m)->rr;
		(*p)->pa = (*m)->pa;
		(*p)->cost = (*m)->cost;
	}
}

// la fonction pour trouver le nombre de deplacement
void	find_cheapest(t_pslist **a, t_pslist **b, t_movelist **m,
		t_cheaplist **p)
{
	t_pslist	*tmp;
	int			max_a;

	(*p)->cost = 9;
	tmp = *a;
	tmp = *b;
	max_a = ft_val_max_a(*a);
	(*p)->cost = 2147483647;
	while (tmp)
	{
		ft_top_b(tmp->val, m, b);
		// printf("rb = %d rrb = %d \n",(*m)->rb,(*m)->rrb);
		if (max_a < tmp->val)
			ft_max_bottom(*a, m, max_a);
		// printf("ra = %d rra = %d \n",(*m)->ra,(*m)->rra);
		else
			ft_good_insert(*a, m, tmp->val);
		// printf("ra = %d rra = %d \n",(*m)->ra,(*m)->rra);
		tmp = tmp->next;
		ft_combine_rrr(m);
		ft_cheapmove(m, p);
	}
}
// max de la piles a
int	ft_val_max_a(t_pslist *a)
{
	int	res;

	res = -2147483648;
	while (a)
	{
		if (res < a->val)
			res = a->val;
		a = a->next;
	}
	return (res);
}

void	ft_end(t_pslist **a, t_pslist **b, t_cheaplist **p)
{
	while ((*p)->ra > 0)
	{
		ft_ra(a);
		(*p)->ra--;
	}
	while ((*p)->rra > 0)
	{
		ft_rra(a);
		(*p)->rra--;
	}
	while ((*p)->rrr > 0)
	{
		ft_rrr(a, b);
		(*p)->rrr--;
	}
	while ((*p)->rr > 0)
	{
		ft_rr(a, b);
		(*p)->rr--;
	}
	while ((*p)->rb > 0)
	{
		ft_rb(b);
		(*p)->rb--;
	}
	while ((*p)->rrb > 0)
	{
		ft_rrb(b);
		(*p)->rrb--;
	}
	while ((*p)->pa > 0)
	{
		ft_pa(a, b);
		(*p)->pa--;
	}
}
int	ft_val_min_a(t_pslist *a)
{
	int	res;

	res = 2147483647;
	while (a)
	{
		if (res > a->val)
			res = a->val;
		a = a->next;
	}
	return (res);
}

int	ft_emp_min(t_pslist *a)
{
	int	emp;
	int	min;

	emp = 0;
	min = ft_val_min_a(a);
	while (a)
	{
		if (a->val == min)
			break;
		a = a->next;
		emp++;
	}
	return (emp);
}

void	ft_end2(t_pslist **a)
{
	int	mid;
	int	size;
	int emp_min;

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
// fonctiomn qui permet de faire le plus petits cout
void	ft_count_move(t_pslist **stack_a, t_pslist **stack_b)
{
	t_movelist	*move;
	t_cheaplist	*cheap;
	// int			emp_min;

	move = ft_calloc(sizeof(t_movelist), 1);
	cheap = ft_calloc(sizeof(t_cheaplist), 1);
	while ((*stack_b))
	{
		find_cheapest(stack_a, stack_b, &move, &cheap);
		ft_end(stack_a, stack_b, &cheap);
	}

	// while (*stack_a)
	// {
	ft_end2(stack_a);
	// }
	return (free(move), free(cheap));
}
// trouver la size d'une pile
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

// Fonction pour trier un tableau d'entiers (tri à bulles)
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

// Fonction pour trouver la médiane de la liste
int long	ft_mediane(t_pslist **stack)
{
	int			len;
	int			*values;
	t_pslist	*temp;
	int			i;
	int			median;

	len = ft_nombre(*stack);
	if (len == 0)
		return (0); // Gérer le cas d'une liste vide
	values = (int *)malloc(len * sizeof(int));
	if (!values)
		return (0); // Gérer l'erreur d'allocation
	temp = *stack;
	i = 0;
	while (i < len)
	{
		values[i] = temp->val;
		temp = temp->next;
		i++;
	}
	bubble_sort(values, len);
	if (len % 2 == 0)
		median = (values[len / 2 - 1] + values[len / 2]) / 2;
	else
		median = values[len / 2];
	free(values);
	return (median);
}

void	ft_tri(t_pslist **t)
{
	int	a;
	int	b;
	int	c;

	a = (*t)->val;
	b = (*t)->next->val;
	c = (*t)->next->next->val;
	if (a > b && a < c)
		ft_sa(t);
	else if (a < b && a > c)
		ft_rra(t);
	else if (a > b && b > c)
	{
		ft_ra(t);
		ft_sa(t);
	}
	else if (a > b && b < c)
		ft_ra(t);
	else if (a < b && b > c)
	{
		ft_rra(t);
		ft_sa(t);
	}
}

// fonction push dans b en fonction de la mediane
void	ft_algo_base(t_pslist **stack_a, t_pslist **stack_b)
{
	int	median;
	int	len;

	len = ft_nombre(*stack_a);
	// stack_is_sorted -> regarde si stack deja trie
	if (len <= 3)
		return (ft_tri(stack_a));
	median = ft_mediane(stack_a);
	while (ft_nombre(*stack_a) > 3)
	{
		ft_pb(stack_b, stack_a);
		if ((*stack_b)->val > median)
			ft_rb(stack_b);
	}
	ft_tri(stack_a);
	ft_count_move(stack_a, stack_b);
}
// fonction pour savoir combien de coup pour le mettre en haut de b
void	ft_top_b(int value, t_movelist **m, t_pslist **b)
{
	t_pslist	*tmp;
	int			i;
	int			size;

	tmp = (*b);
	i = 0;
	(*m)->rb = 0;
	(*m)->rrb = 0;
	(*m)->pa = 1;
	while (tmp)
	{
		if (tmp->val == value)
			break ;
		tmp = tmp->next;
		i++;
	}
	size = ft_nombre((*b));
	if (i < size / 2)
		(*m)->rb = i;
	else
		(*m)->rrb = size - i;
}

// tri a
