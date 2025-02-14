/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luda-cun <luda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:14:17 by luda-cun          #+#    #+#             */
/*   Updated: 2025/02/13 18:55:45 by luda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*ft_add_val(int val)
{
	t_pslist	*element;

	element = malloc(sizeof(t_pslist));
	if (!element)
		return (NULL);
	element->val = val;
	element->next = NULL;
	return (element);
}
