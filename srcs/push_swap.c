/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 06:01:06 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/16 19:32:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	unsigned int	sizea;
	unsigned int	sizeb;
	t_pile			*a;
	t_pile			*b;

	a = NULL;
	if (ac >= 2)
	{
		a = get_pile(ac, av);
		sizea = ft_sizepile(a);
		if (is_sorted(a, sizea) == -1)
		{
			set_xvalues(a, sizea);
			b = makeb(&a, sizea);
			three_semisort(&a);
			sizea = ft_sizepile(a);
			sizeb = ft_sizepile(b);
			while (b != NULL)
				step_sort(&a, &b, sizea++, sizeb--);
			final_set(&a, sizea);
		}
		free_pile(&a);
	}
	return (0);
}
