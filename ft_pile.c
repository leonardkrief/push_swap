/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:15:00 by lkrief            #+#    #+#             */
/*   Updated: 2022/10/06 03:04:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	free_pile(t_pile **add_a)
{
	t_pile	*begin;
	t_pile	*tmp;

	begin = *add_a;
	*add_a = NULL;
	while (begin)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
}

void	print_pile(t_pile *begin, char *s)
{
	if (!begin)
		printf("%s = (null)\n", s);
	else
		printf("%s = ", s);
	while (begin)
	{
		if (begin->next)
			printf("%d -> ", begin->data);
		else
			printf("%d\n", begin->data);
		begin = begin->next;
	}
}

t_pile	*push(t_pile *a, int data)
{
	t_pile	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	if (!a)
		return (new);
	new->next = a;
	return (new);
}

//sa ___ sb ___ ss
void	s(t_pile **add_a)
{
	t_pile	*begin;
	t_pile	*tmp;

	begin = *add_a;
	if (begin && begin->next)
	{
		*add_a = begin->next;
		tmp = begin->next->next;
		begin->next->next = begin;
		begin->next = tmp;
	}
}

void	ss(t_pile **add_a, t_pile **add_b)
{
	s(add_a);
	s(add_b);
}

//pa ___ pb
void	p(t_pile **add_a, t_pile **add_b)
{
	t_pile	*a;
	t_pile	*b;

	a = *add_a;
	b = *add_b;
	if (b)
	{
		*add_b = b->next;
		*add_a = b;
		b->next = a;
	}
}

// ra ___ rb ___ rr
void	r(t_pile **add_a)
{
	t_pile	*a;
	t_pile	*begin;

	a = *add_a;
	if (a && a->next)
	{
		*add_a = a->next;
		begin = a->next;
		while (begin->next)
			begin = begin->next;
		begin->next = a;
		a->next = NULL;
	}
}

void	rr(t_pile **add_a, t_pile **add_b)
{
	r(add_a);
	r(add_b);
}

// rra ___ rrb ___ rrr

void	r_r(t_pile **add_a)
{
	t_pile	*a;
	t_pile	*begin;

	a = *add_a;
	if (a && a->next)
	{
		begin = a;
		while (begin->next->next)
			begin = begin->next;
		*add_a = begin->next;
		begin->next->next = a;
		begin->next = NULL;
	}
}

void	rr_r(t_pile **add_a, t_pile **add_b)
{
	r_r(add_a);
	r_r(add_b);
}

// int	main(void)
// {
// 	t_pile	*a;
// 	t_pile	*b;

// 	a = NULL;
// 	b = NULL;
// 	a = push(a, 12);
// 	a = push(a, 2);
// 	a = push(a, 7);
// 	a = push(a, 8);
// 	a = push(a, 23);
// 	p(&b, &a);
	

// 	print_pile(a, "a");
// 	print_pile(b, "b");
// 	free_pile(&a);
// 	free_pile(&b);
// 	print_pile(a, "a");
// 	print_pile(b, "b");
// }