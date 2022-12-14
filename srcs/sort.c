/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:37:09 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/14 06:50:30 by lkrief           ###   ########.fr       */
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
		// if (tab[0] == 1 && tab[1] == 3 && tab[2] == 2)
		if (tab[0] < tab[1] && tab[0] < tab[2] && tab[2] < tab[1])
			swap(a, "sa\n");
		// else if (tab[0] == 2 && tab[1] == 1 && tab[2] == 3)
		else if (tab[1] < tab[0] && tab[1] < tab[2] && tab[0] < tab[2])
			swap(a, "sa\n");
		// else if (tab[0] == 3 && tab[1] == 2 && tab[2] == 1)
		else if (tab[0] > tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
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

void	set_pos(t_pile *a)
{
	unsigned int	pos;
	t_pile			*start;

	if (a == NULL)
		return ;
	pos = 1;
	start = a;
	a->pos = pos++;
	a = a->next;
	while (start != a)
	{
		a->pos = pos++;
		a = a->next;
	}
	
}

t_pile	*get_insertion(t_pile *a, t_pile *b)
{
	if (b->x > a->x)
	{
		if (a->x < a->prev->x)
			return (a);
		while (b->x > a->next->x && a->next->x > a->x)
			a = a->next;
		return (a->next);
	}
	else
	{
		while (b->x < a->prev->x && a->prev->x < a->x)
			a = a->prev;
		return (a);
	}
}

void	get_costs(t_pile *a, t_pile *b, unsigned int sizea, unsigned int sizeb)
{
	int	down_path;
	int	up_path;
	int	oposite;

	set_pos(a);
	set_pos(b);
	// int nb=1;
	// printf("\n---getting costs---\n");
	while (b->pos <= sizeb)
	{
		a = get_insertion(a, b);
		b->x_to_push = a->x;
		down_path = ft_max(sizeb - b->pos + 1, sizea - a->pos + 1) + 1;
		up_path = ft_max(b->pos - 1, a->pos - 1) + 1;
		oposite = ft_min(b->pos + sizea - a->pos, a->pos + sizeb - b->pos) + 1;
		b->cost = ft_min(ft_min(down_path, up_path), oposite);
		b->path = 2;
		if ((int)b->cost == down_path)
			b->path = 1;
		else if ((int)b->cost == up_path)
			b->path = -1;
		else if ((int)b->cost == (int)sizeb - (int)b->pos + (int)a->pos + 1)
			b->path = -2;
		// printf("(%-4d) b->n = %-4d   x_to_pushon = %-4d   b->cost = %-4d   b->path = %+d    down = %-4d   up = %-4d   oposite = %-4d\n", nb++, b->n, b->x_to_push, b->cost, b->path, down_path, up_path, oposite);
		b = b->next;
		if (b->pos <= b->prev->pos)
			b->pos = sizeb + 1;
	}
}

void	step_sort(t_pile **a, t_pile **b, unsigned int sizea, unsigned int sizeb)
{
	unsigned int	i;
	t_pile	*to_push;

	get_costs(*a, *b, sizea, sizeb);
	i = 0;
	to_push = *b;
	while (++i <= sizeb)
	{
		if ((*b)->cost < to_push->cost)
			to_push = *b;
		*b = (*b)->next;
	}
	// static int nb;
	// printf("\n\n----------------STEP %d------------------\n", ++nb);
	// ft_printpile(*a, "----a----\n");
	// ft_printpile(*b, "----b----\n");
	// printf("\nb->n = %-4d   x_to_pushon = %-4d   b->cost = %-4d   b->path = %+d\n", (*b)->n, (*b)->x_to_push, (*b)->cost, (*b)->path);
	if ((*b)->path == -2)
	{
		while ((*b)->n != to_push->n)
			revrotate(b, "rrb\n");
		while ((*a)->x != to_push->x_to_push)
			rotate(a, "ra\n");
	}
	else if ((*b)->path == 2)
	{
		while ((*b)->n != to_push->n)
			rotate(b, "rb\n");
		while ((*a)->x != to_push->x_to_push)
			revrotate(a, "rra\n");
	}
	else if ((*b)->path == -1)
	{
		while ((*b)->n != to_push->n && (*a)->x != to_push->x_to_push)
			both(rotate, a, b, "rr\n");
		while ((*a)->x != to_push->x_to_push)
			rotate(a, "ra\n");
		while ((*b)->n != to_push->n)
			rotate(b, "rb\n");
	}
	else if ((*b)->path == 1)
	{
		while ((*b)->n != to_push->n && (*a)->x != to_push->x_to_push)
			both(revrotate, a, b, "rrr\n");
		while ((*a)->x != to_push->x_to_push)
			revrotate(a, "rra\n");
		while ((*b)->n != to_push->n)
			revrotate(b, "rrb\n");
	}
	push(b, a, "pa\n");
}
// la variable path indique le sens du plus court chemin pour insérer l'element dans a
// path = -1 : on rotate les deux vers le bas (rr)
// path = 1 : on rotate les deux vers le haut (rrr)
// path = -2 : on rotate b vers le haut (rrb) et a vers le bas (ra)
// path = 2 : on rotate b vers le bas (rb) et a vers le haut (rra)

void	final_set(t_pile **a, int sizea)
{
	t_pile	*top;

	set_pos(*a);
	top = *a;
	while (top->x != 1)
		top = top->next;
	if (top->pos < sizea - top->pos + 1)
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