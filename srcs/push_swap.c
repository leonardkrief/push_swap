/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 06:01:06 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/14 07:02:01 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	unsigned int	sizea;
	unsigned int	sizeb;
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	if (ac >= 2)
	{
		a = get_pile(ac, av);
		sizea = ft_sizepile(a);
		set_xvalues(a, sizea);
		b = makeb(&a, sizea);
		three_semisort(&a);
		sizea = ft_sizepile(a);
		sizeb = ft_sizepile(b);
		while (b != NULL)
			step_sort(&a, &b, sizea++, sizeb--);
		final_set(&a, sizea);
		ft_printpile(a, "\n-------a-------\n");
		// ft_printpile(b, "-------b-------\n");
		free_pile(&a);
	}
}
