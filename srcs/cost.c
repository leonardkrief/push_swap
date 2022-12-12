/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:47:41 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/12 19:47:45 by lkrief           ###   ########.fr       */
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

// t_pile *makeb(int)
// {
	
// }