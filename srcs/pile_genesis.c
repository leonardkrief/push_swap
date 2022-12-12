/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_genesis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:42:15 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/12 18:12:33 by lkrief           ###   ########.fr       */
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
	new->x = 0;
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

void	free_pile(t_pile **begin)
{
	if (*begin != NULL)
	{
		while (*begin != (*begin)->next)
			ft_pop(begin);
		ft_pop(begin);
	}
}
