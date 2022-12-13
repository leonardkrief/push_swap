/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:37:09 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/13 16:15:42 by lkrief           ###   ########.fr       */
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

/*

16	10
89
6
9
11
*/

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
		b = b->next;
		if (b->pos < b->prev->pos)
			b->pos = sizeb + 1;
	}
}
