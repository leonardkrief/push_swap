/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:00:08 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/16 18:55:18 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_error(t_pile **a, t_pile **b, char *str, int fd)
{
	free_pile(a);
	free_pile(b);
	if (str)
		ft_putstr_fd(str, fd);
	if (!strncmp(str, "KO\n", 4) || !strncmp(str, "Error\n", 7))
		exit(-1);
}

void	ft_action(t_pile **a, t_pile **b, char *str)
{
	if (!strncmp(str, "pa\n", 4))
		push(b, a, "");
	else if (!strncmp(str, "pb\n", 4))
		push(a, b, "");
	else if (!strncmp(str, "sa\n", 4))
		swap(a, "");
	else if (!strncmp(str, "sb\n", 4))
		swap(b, "");
	else if (!strncmp(str, "ra\n", 4))
		rotate(a, "");
	else if (!strncmp(str, "rb\n", 4))
		rotate(b, "");
	else if (!strncmp(str, "rra\n", 5))
		revrotate(a, "");
	else if (!strncmp(str, "rrb\n", 5))
		revrotate(b, "");
	else if (!strncmp(str, "rr\n", 4))
		both(rotate, a, b, "");
	else if (!strncmp(str, "rrr\n", 5))
		both(revrotate, a, b, "");
	else
	{
		free(str);
		free_error(a, b, "Error\n", 2);
	}
}

void	ft_checksort(t_pile **a, t_pile **b)
{
	unsigned int	size;

	size = ft_sizepile(*a);
	while (--size)
	{
		if ((*a)->n > (*a)->next->n)
			free_error(a, b, "KO\n", 1);
		*a = (*a)->next;
	}
	ft_putstr_fd("OK\n", 1);
	free_pile(a);
	free_pile(b);
}

int	main(int ac, char **av)
{
	t_pile			*a;
	t_pile			*b;
	char			*str;

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
			ft_action(&a, &b, str);
			free(str);
		}
		ft_checksort(&a, &b);
	}
	return (0);
}
