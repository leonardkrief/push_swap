/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:37:09 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/13 03:59:21 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	three_semisort(t_pile **a)
{
	int	tab[3];

	tab[0] = (*a)->x;
	tab[1] = (*a)->next->x;
	tab[2] = (*a)->next->next->x;
	if (*a != (*a)->next->next)
	{
		if (tab[0] == 1 && tab[1] == 3 && tab[2] == 2)
			swap(a, "sa\n");
		else if (tab[0] == 3 && tab[1] == 2 && tab[2] == 1)
			swap(a, "sa\n");
	}
}
/*
123 OK
132 rra sa
213 sa
231 rra
312 ra
321 sa rra
*/

void	get_costs(t_pile **a, t_pile **b, unsigned int sizea, unsigned int sizeb)
{
	unsigned int	i;
	unsigned int	a_pos;
	unsigned int	b_pos;

	i = 0;
	while (i++ < sizeb)
	{
		if (i <= sizeb / 2)
			
	}
}