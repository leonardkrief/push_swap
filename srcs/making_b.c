/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:47:41 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/16 19:35:45 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_pile *a, int sizea)
{
	int	i;

	i = 0;
	while (i + 1 < sizea)
	{
		if (a->n > a->next->n)
			return (-1);
		a = a->next;
		i++;
	}
	return (0);
}

void	set_xvalues(t_pile *a, int size)
{
	int		x;
	int		i;
	t_pile	*min;

	x = 1;
	min = a;
	while (min != NULL)
	{
		i = 1;
		while (a->x != 0 && (i++) <= size)
			a = a->next;
		if (i > size)
			return ;
		i = 1;
		min = a;
		while (i++ <= size)
		{
			if (a->x == 0 && min->n > a->n)
				min = a;
			a = a->next;
		}
		min->x = x;
		x++;
	}
}

t_pile	*makeb(t_pile **a, unsigned int size)
{
	t_pile			*b;
	unsigned int	i;
	unsigned int	pivot;

	b = NULL;
	pivot = ((int)(0.6 * (double)size));
	i = 0;
	while (size > 3)
	{
		if (((*a)->x == pivot) || (++i > size))
			pivot = ft_max(0, ft_min(pivot - size / 4, pivot - 1));
		if ((*a)->x >= pivot && --size > 0)
			push(a, &b, "pb\n");
		if ((*a)->x < pivot || (*a)->x <= 3)
			rotate(a, "ra\n");
		if (i > size)
			i = 0;
	}
	return (b);
}
