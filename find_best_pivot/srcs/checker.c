/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:00:08 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/15 22:33:49 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_error(t_pile **a, t_pile **b, int n)
{
	free_pile(a);
	free_pile(b);
	if (n == -1)
		ft_putstr_fd("Error\n", 2);
	if (n != 0)
		exit(-1);
}

void	ft_action(t_pile **a, t_pile **b, char **str)
{
	if (!strncmp(*str, "pa\n", 4))
		push(b, a, "");
	else if (!strncmp(*str, "pb\n", 4))
		push(a, b, "");
	else if (!strncmp(*str, "sa\n", 4))
		swap(a, "");
	else if (!strncmp(*str, "sb\n", 4))
		swap(b, "");
	else if (!strncmp(*str, "ra\n", 4))
		rotate(a, "");
	else if (!strncmp(*str, "rb\n", 4))
		rotate(b, "");
	else if (!strncmp(*str, "rra\n", 4))
		revrotate(a, "");
	else if (!strncmp(*str, "rrb\n", 4))
		revrotate(b, "");
	else if (!strncmp(*str, "rr\n", 4))
		both(rotate, a, b, "");
	else if (!strncmp(*str, "rrr\n", 4))
		both(revrotate, a, b, "");
	else
	{
		// static int i;
		// printf("str===%s\n", *str);
		free_error(a, b, -1);
	}
	// static int i;
	// printf("(%d) %s", i++, *str);
	// ft_printpile(*a, "----a----\n");
	*str = get_next_line(0);
}

int	main(int ac, char **av)
{
	t_pile *a;
	t_pile *b;
	unsigned int size;
	char *str;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		a = get_pile(ac, av);
		while (1)
		{
			str = get_next_line(0);
			if (!str)
				break ;
			ft_action(&a, &b, &str);
		}
		size = ft_sizepile(a);
		// ft_printpile(a, "----a----\n");
		while (--size)
		{
			if (a->n > a->next->n)
			{
				ft_putstr_fd("KO\n", 1);
				free_error(&a, &b, 1);
			}
		}
		ft_putstr_fd("OK\n", 1);
		free_error(&a, &b, 0);
	}
}