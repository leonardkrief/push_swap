/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 06:01:06 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/12 19:25:10 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"




int	main(int ac, char **av)
{
	t_pile	*a;

	a = NULL;
	if (ac >= 2)
		a = get_pile(ac, av);
	get_x_values(a);
	ft_printpile(a);
	free_pile(&a);
}
 /*

 10
 2	7 (1$)
 4	3 (2$)
 9	1 (2$)
 A	B
 */