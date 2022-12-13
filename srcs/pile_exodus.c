/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_exodus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:42:15 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/13 16:11:24 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

unsigned int	ft_sizepile(t_pile *a)
{
	t_pile	*start;
	int		n;

	if (a == NULL)
		return (0);
	n = 1;
	start = a;
	a = a->next;
	while (start != a)
	{
		n++;
		a = a->next;
	}
	return (n);
}

void	ft_printpile(t_pile *begin, char *str)
{
	t_pile	*start;

	if (begin && str)
	{
		printf("%s", str);
		start = begin;
		if (begin != NULL)
		{
			while (start != begin->next)
			{
				printf("%-8d x=%-3d   cost = %-3d   path = %2d   x_to_push = %-3d   pos = %2d\n", begin->n, begin->x, begin->cost, begin->path, begin->x_to_push, begin->pos);
				begin = begin->next;
			}
			printf("%-8d x=%-3d   cost = %-3d   path = %2d   x_to_push = %-3d   pos = %2d\n", begin->n, begin->x, begin->cost, begin->path, begin->x_to_push, begin->pos);
		}
	}
	// se rappeller de retirer cette fonction avant de push
}

void	ft_printpile_rev(t_pile *begin, char *str)
{
	t_pile	*start;

	if (begin && str)
	{
		printf("reverted-");
		printf("%s", str);
		start = begin;
		if (begin != NULL)
		{
			while (start != begin->prev)
			{
				printf("%-8d x=%-3d   cost = %-3d   path = %2d   pos = %2d\n", begin->n, begin->x, begin->cost, begin->path, begin->pos);
				begin = begin->prev;
			}
			printf("%-8d x=%-3d   cost = %-3d   path = %2d\n", begin->n, begin->x, begin->cost, begin->path);
		}
	}
	// se rappeller de retirer cette fonction avant de push
}

t_pile	*ft_merge_pile(t_pile *begin, t_pile *tmp)
{
	t_pile	*b;
	t_pile	*bp;
	t_pile	*t;
	t_pile	*tp;

	b = begin;
	bp = begin->prev;
	t = tmp;
	tp = tmp->prev;
	begin->prev = tp;
	tp->next = b;
	bp->next = t;
	tmp->prev = bp;
	return (begin);
}
