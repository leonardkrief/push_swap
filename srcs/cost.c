/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:47:41 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/12 19:33:35 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*set_minx(t_pile *a, int x, int size)
{
	int		i;
	t_pile	*min;

	i = 1;
	while (a->x != 0 && (i++) <= size)
		a = a->next;
	if (i > size)
		return (NULL);
	i = 1;
	min = a;
	while (i++ <= size)
	{
		if (a->x == 0 && min->n > a->n)
			min = a;
		a = a->next;
	}
	min->x = x;
	return (min);
}

void	get_x_values(t_pile *a)
{
	int		x;
	t_pile	*min;
	int		size;

	x = 1;
	size = ft_sizepile(a);
	min = a;
	while (min != NULL)
		min = set_minx(min, x++, size);
}