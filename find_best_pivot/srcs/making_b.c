/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:47:41 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/16 05:43:08 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

unsigned int	ft_sqrt(unsigned int n)
{
	unsigned int	sqrt;

	if (n == 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt < n)
		sqrt++;
	return (sqrt - 1);
}

t_pile	*makeb(t_pile **a, unsigned int size)
{
	t_pile			*b;
	int	i;
	// unsigned int	sqrt;
	int	pivot;

	b = NULL;
	// sqrt = ft_sqrt(size);
	pivot = ((int)(double)0,55 * (double)size);
	i = 0;
	while (size > 3)
	{
		if ((((int)(*a)->x) == pivot) || (++i > ((int)size)))
			pivot = 0;
		if (((int)(*a)->x) >= pivot && ((int)--size) > 0)
		{
			NB_COUPS++;
			push(a, &b, NULL);
		}
		if (((int)(*a)->x) < pivot || ((int)(*a)->x) <= 3)
		{
			NB_COUPS++;
			rotate(a, NULL);
		}
		if (i > ((int)size))
			i = 0;
	}
	return (b);
}
