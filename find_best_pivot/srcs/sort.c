/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:37:09 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/16 00:06:23 by lkrief           ###   ########.fr       */
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
		{
			NB_COUPS++;
			swap(a, NULL);
		}
		// else if (tab[0] == 2 && tab[1] == 1 && tab[2] == 3)
		else if (tab[1] < tab[0] && tab[1] < tab[2] && tab[0] < tab[2])
		{
			NB_COUPS++;
			swap(a, NULL);
		}
		// else if (tab[0] == 3 && tab[1] == 2 && tab[2] == 1)
		else if (tab[0] > tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
		{
			NB_COUPS++;
			swap(a, NULL);
		}
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
		if (a->x < a->prev->x && b->x > a->prev->x)
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
	i = 0;
	
	// static int nb;
	// printf("\n\n----------------STEP %d------------------\n", ++nb);
	// if (nb == 484)
	// {
	// 	i++;
	// 	i--;
	// }
	
	t_pile	*to_push;

	get_costs(*a, *b, sizea, sizeb);
	to_push = *b;
	while (++i <= sizeb)
	{
		if ((*b)->cost < to_push->cost)
			to_push = *b;
		*b = (*b)->next;
	}
	// ft_printpile(*a, "--------a-----NULL);
	// ft_printpile(*b, "--------b-----NULL);
	// printf("\n(%d) to_push->n = %-4d   x_to_pushon = %-4d   cost = %-4d   path = %+d\n", nb, to_push->n, to_push->x_to_push, to_push->cost, to_push->path);
	if (to_push->path == -2)
	{
		while ((*b)->n != to_push->n)
		{
			NB_COUPS++;
			revrotate(b, NULL);
		}
		while ((*a)->x != to_push->x_to_push)
		{
			NB_COUPS++;
			rotate(a, NULL);
		}
	}
	else if (to_push->path == 2)
	{
		while ((*b)->n != to_push->n)
		{
			NB_COUPS++;
			rotate(b, NULL);
		}
		while ((*a)->x != to_push->x_to_push)
		{
			NB_COUPS++;
			revrotate(a, NULL);
		}
	}
	else if (to_push->path == -1)
	{
		while ((*b)->n != to_push->n && (*a)->x != to_push->x_to_push)
		{
			NB_COUPS++;
			both(rotate, a, b, NULL);
		}
		while ((*a)->x != to_push->x_to_push)
		{
			NB_COUPS++;
			rotate(a, NULL);
		}
		while ((*b)->n != to_push->n)
		{
			NB_COUPS++;
			rotate(b, NULL);
		}
	}
	else if (to_push->path == 1)
	{
		while ((*b)->n != to_push->n && (*a)->x != to_push->x_to_push)
		{
			NB_COUPS++;
			both(revrotate, a, b, NULL);
		}
		while ((*a)->x != to_push->x_to_push)
		{
			NB_COUPS++;
			revrotate(a, NULL);
		}
		while ((*b)->n != to_push->n)
		{
			NB_COUPS++;
			revrotate(b, NULL);
		}
	}
	push(b, a, NULL);
}
// la variable path indique le sens du plus court chemin pour insérer l'element dans a
// path = -1 : on rotate les deux vers le haut (r)
// path = 1 : on rotate les deux vers le bas (rr)
// path = -2 : on rotate b vers le bas (rb) et a vers le haut (rra)
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
		{
			NB_COUPS++;
			rotate(a, NULL);
		}
	}
	else
	{
		while ((*a)->x != 1)
		{
			NB_COUPS++;
			revrotate(a, NULL);
		}
	}
}