/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:15:00 by lkrief            #+#    #+#             */
/*   Updated: 2022/10/06 03:07:20 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	free_merge(int *t1, int *t2)
{
	if (t1)
		free(t1);
	if (t2)
		free(t2);
}

int	*copie(int *t, int *tab, int start, int end)
{
	int	i;

	i = 0;
	if (!t || !tab)
		return (NULL);
	while (start + i < end)
	{
		t[i] = tab[start + i];
		i++;
	}
	return (tab);
}

int	*fusion(int *t1, int *t2, int s1, int s2, int *tab)
{
	int	i;
	int	j;

	if (!t1)
		return (t2);
	else if (!t2)
		return (t1);
	i = 0;
	j = 0;
	while (i < s1 || j < s2)
	{
		if ((j == s2) || (i < s1 && j < s2) && (t1[i] < t2[j]))
		{
			tab[i + j] = t1[i];
			i++;
		}
		else
		{
			tab[i + j] = t2[j];
			j++;
		}
	}
	return (tab);
}

int	*merge_sort(int *tab, int n)
{
	int	*t1;
	int	*t2;

	if (n > 1)
	{
		t1 = malloc(sizeof(*t1) * (n - n / 2));
		t2 = malloc(sizeof(*t2) * (n / 2));
		if (!t1 || !t2)
		{
			free_merge(t1, t2);
			return (NULL);
		}
		copie(t1, tab, 0, n - n / 2);
		copie(t2, tab, n - n / 2, n);
		merge_sort(t1, n - n / 2);
		merge_sort(t2, n / 2);
		fusion(t1, t2, n - n / 2, n / 2, tab);
		free_merge(t1, t2);
	}
	return (tab);
}

// int	main(void)
// {
// 	int	i = 0;
// 	int	t1[] = {2, 6, 8, 9};
// 	int	t2[] = {1, 3, 4, 5, 7};
// 	int	tab[] = {0,  3, 2, 8, 1, 6, 7, 5};
// 	int	tab1[] = {4, 0, 5};
// 	int taille = sizeof(tab) / sizeof(*tab);

// 	merge_sort(tab, taille);
// 	if (i < taille)
// 		printf("{");
// 	while (i < taille - 1)
// 		printf("%d, ", tab[i++]);
// 	if (i < taille)
// 		printf("%d}", tab[i]);
// }