/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_deuteronomy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:37:09 by lkrief            #+#    #+#             */
/*   Updated: 2023/01/03 04:59:38 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	step_sort(t_pile **a, t_pile **b, unsigned int sizea,
	unsigned int sizeb)
{
	unsigned int	i;
	t_pile			*to_push;

	get_costs(*a, *b, sizea, sizeb);
	to_push = *b;
	i = 0;
	while (++i <= sizeb)
	{
		if ((*b)->cost < to_push->cost)
			to_push = *b;
		*b = (*b)->next;
	}
	step_sort_path1(a, b, to_push);
	step_sort_path2(a, b, to_push);
	push(b, a, "pa\n");
}
// la variable path indique le sens du plus court chemin 
// pour insérer l'element dans a
// path = -1 : on rotate les deux vers le haut (r)
// path = 1 : on rotate les deux vers le bas (rr)
// path = -2 : on rotate b vers le bas (rb) et a vers le haut (rra)
// path = 2 : on rotate b vers le bas (rb) et a vers le haut (rra)

void	step_sort_path1(t_pile **a, t_pile **b, t_pile *to_push)
{
	if (to_push->path == -1)
	{
		while ((*b)->n != to_push->n && (*a)->x != to_push->x_to_push)
			both(rotate, a, b, "rr\n");
		while ((*a)->x != to_push->x_to_push)
			rotate(a, "ra\n");
		while ((*b)->n != to_push->n)
			rotate(b, "rb\n");
	}
	else if (to_push->path == 1)
	{
		while ((*b)->n != to_push->n && (*a)->x != to_push->x_to_push)
			both(revrotate, a, b, "rrr\n");
		while ((*a)->x != to_push->x_to_push)
			revrotate(a, "rra\n");
		while ((*b)->n != to_push->n)
			revrotate(b, "rrb\n");
	}
}

void	step_sort_path2(t_pile **a, t_pile **b, t_pile *to_push)
{
	if (to_push->path == -2)
	{
		while ((*b)->n != to_push->n)
			revrotate(b, "rrb\n");
		while ((*a)->x != to_push->x_to_push)
			rotate(a, "ra\n");
	}
	else if (to_push->path == 2)
	{
		while ((*b)->n != to_push->n)
			rotate(b, "rb\n");
		while ((*a)->x != to_push->x_to_push)
			revrotate(a, "rra\n");
	}
}

void	final_set(t_pile **a, int sizea)
{
	t_pile	*top;

	set_pos(*a);
	top = *a;
	while (top->x != 1)
		top = top->next;
	if (top->pos <= sizea - top->pos + 1)
	{
		while ((*a)->x != 1)
			rotate(a, "ra\n");
	}
	else
	{
		while ((*a)->x != 1)
			revrotate(a, "rra\n");
	}
}
