/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_leviticus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:42:15 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/13 00:49:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_pile **a, t_pile **b, char *str)
{
	if (*a == NULL)
		return;
	ft_push(b, ft_pop(a));
	ft_putstr_fd(str, 1);
}

void	rotate(t_pile **a, char *str)
{
	if (*a == NULL || (*a) == (*a)->next)
		return;
	*a = (*a)->next;
	ft_putstr_fd(str, 1);
}

void	revrotate(t_pile **a, char *str)
{
	if (*a == NULL || (*a) == (*a)->next)
		return;
	*a = (*a)->prev;
	ft_putstr_fd(str, 1);
}

void	swap(t_pile **a, char *str)
{
	int	tmp;

	if (*a == NULL || (*a) == (*a)->next)
		return;
	tmp = (*a)->n;
	(*a)->n = (*a)->next->n;
	(*a)->next->n = tmp;
	ft_putstr_fd(str, 1);
}

void	both(void (*f)(t_pile **, char *), t_pile **a, t_pile **b, char *str)
{
	f(a, NULL);
	f(b, NULL);
	ft_putstr_fd(str, 1);
}