/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:37:09 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/13 02:46:08 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	three_sort(t_pile *a)
{
	int	tab[3];

	tab[0] = a->x;
	tab[1] = a->next->x;
	tab[2] = a->next->next->x;
	if (tab[0] == 1 && tab[1] == 2 && tab[2] == 3)
		return ;
	else if (tab[0] == 1 && tab[1] == 3 && tab[2] == 2)
	{
		rev_
	}
	else if (tab[0] == 1 && tab[1] == 2 && tab[2] == 3)
		return ;
	else if (tab[0] == 1 && tab[1] == 2 && tab[2] == 3)
		return ;
	else if (tab[0] == 1 && tab[1] == 2 && tab[2] == 3)
		return ;
	else if (tab[0] == 1 && tab[1] == 2 && tab[2] == 3)
		return ;
}
/*
123 OK
132 rra sa
213 sa
231 rra
312 ra
321 sa rra
*/