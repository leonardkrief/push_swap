/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_exode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:42:15 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/11 07:24:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//il faudra enlever cette fonction qui comporte printf
void	ft_printpile(t_pile *begin)
{
	t_pile	*start;

	start = begin;
	if (begin != NULL)
	{
		while (start != begin->next)
		{
			printf("(%d)\n", begin->n);
			begin = begin->next;
		}
		printf("(%d)\n", begin->n);
	}
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
