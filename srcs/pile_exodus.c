/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_exodus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:42:15 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/13 02:29:49 by lkrief           ###   ########.fr       */
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

//il faudra enlever cette fonction qui comporte printf
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
				printf("(%-8d) x=%d\n", begin->n, begin->x);
				begin = begin->next;
			}
			printf("(%-8d) x=%d\n", begin->n, begin->x);
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
