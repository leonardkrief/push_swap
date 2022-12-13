/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 06:01:06 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/13 02:21:13 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	unsigned int	size;
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	if (ac >= 2)
		a = get_pile(ac, av);
	size = ft_sizepile(a);
	set_xvalues(a, size);
	b = makeb(&a, size);
	free_pile(&a);
	free_pile(&b);
}
