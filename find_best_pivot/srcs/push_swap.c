/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 06:01:06 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/16 16:04:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



unsigned int	PIVOT = 0;
unsigned int	NB_COUPS = 0;
unsigned int	BEST_PIVOT = 0;
unsigned int	BEST_NB_COUPS = 0;

int	main(int ac, char **av)
{
	unsigned int	sizea;
	unsigned int	sizeb;
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	// unsigned int	moyenne_best_pivot = 0;
	// unsigned int	moyenne_best_nb_coups = 0;
		if (ac >= 2)
		{
			a = get_pile(ac, av);
			sizea = ft_sizepile(a);
			PIVOT = sizea / 2;
			BEST_PIVOT = -1;
			BEST_NB_COUPS = -1;
			while (++PIVOT <= 7 * sizea / 10)
			{
				a = get_pile(ac, av);
				sizea = ft_sizepile(a);
				NB_COUPS = 0;
				set_xvalues(a, sizea);
				b = makeb(&a, sizea);
				three_semisort(&a);
				sizea = ft_sizepile(a);
				sizeb = ft_sizepile(b);
				while (b != NULL)
					step_sort(&a, &b, sizea++, sizeb--);
				final_set(&a, sizea);
				if (NB_COUPS < BEST_NB_COUPS)
				{
					BEST_NB_COUPS = NB_COUPS;
					BEST_PIVOT = PIVOT;
				}
				// ft_printpile(a, "\n-------a-------\n");
				// ft_printpile(b, "-------b-------\n");
				free_pile(&a);
			}
			printf("SIZE = %d   BEST_PIVOT = %d   BEST_NB_COUPS = %d\n", sizea, BEST_PIVOT, BEST_NB_COUPS);
			//printf("\n\nSIZE = %d\nBEST_PIVOT = %d\nBEST_NB_COUPS = %d\n", sizea, BEST_PIVOT, BEST_NB_COUPS);
			// moyenne_best_pivot += BEST_PIVOT;
			// moyenne_best_nb_coups += BEST_NB_COUPS;
		}
	// printf("moyenne best pivot = %d   moyenne best nb coups = %d  ", moyenne_best_pivot, moyenne_best_nb_coups);
	// printf("moyenne best pivot = %f * sizea   moyenne best nb coups = %f * sizea", (double)moyenne_best_pivot/(double)sizea, (double)moyenne_best_nb_coups/(double)sizea);
}
