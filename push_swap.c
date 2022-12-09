/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:15:00 by lkrief            #+#    #+#             */
/*   Updated: 2022/10/06 03:22:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	print_tab(int *tab, int n)
{
	int	i;

	if (n >= 0)
	{
		printf("{");
		i = -1;
		while (++i < n - 1)
			printf("%d, ", tab[i]);
		printf("%d}", tab[i]);
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	*tab;

	if (argc >= 2)
	{
		tab = malloc(sizeof(*tab) * (argc - 1));
		if (!tab)
			return (0);
		n = -1;
		while (++n < argc - 1)
			tab[n] = ft_atoi(argv[n + 1]);
		tab = merge_sort(tab, argc - 1);
		print_tab(tab, argc - 1);
	}
}