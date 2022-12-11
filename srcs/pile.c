/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:42:15 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/11 07:10:09 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*new_pile(int n)
{
	t_pile	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = new;
	new->prev = new;
	return (new);
}

t_pile	*ft_push(t_pile **begin, int n)
{
	t_pile	*new;

	if (*begin == NULL)
		*begin = new_pile(n);
	else
	{
		new = new_pile(n);
		new->next = *begin;
		new->prev = (*begin)->prev;
		((*begin)->prev)->next = new;
		(*begin)->prev = new;
		*begin = new;
	}
	return (*begin);
}

t_pile	*ft_push_end(t_pile **begin, int n)
{
	t_pile	*new;

	if (*begin == NULL)
		*begin = new_pile(n);
	else
	{
		new = new_pile(n);
		new->next = *begin;
		new->prev = (*begin)->prev;
		((*begin)->prev)->next = new;
		(*begin)->prev = new;
	}
	return (*begin);
}

// attention, on ne peut appeler cette fonction que si begin est non NULL
int	ft_pop(t_pile **begin)
{
	int		n;
	t_pile	*tmp;

	n = (*begin)->n;
	if (*begin == (*begin)->next)
	{
		free(*begin);
		*begin = NULL;
	}
	else
	{
		(*begin)->next->prev = (*begin)->prev;
		(*begin)->prev->next = (*begin)->next;
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
	return (n);
}

t_pile	*ft_push_pile(t_pile **begin, t_pile *tmp)
{
	if (*begin == NULL)
		*begin = tmp;
	else
	{
		(*begin)->prev->next = tmp;
		tmp->prev->next = *begin;
	}
	return (*begin);
}

void	free_pile(t_pile **begin)
{
	if (*begin != NULL)
	{
		while (*begin != (*begin)->next)
			ft_pop(begin);
		ft_pop(begin);
	}
}

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