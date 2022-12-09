/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:15:00 by lkrief            #+#    #+#             */
/*   Updated: 2022/10/06 03:05:29 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PILE_H
# define FT_PILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_pile
{
	int	data;
	struct s_pile *next;
}t_pile;

//basics
void	free_pile(t_pile **add_a);
void	print_pile(t_pile *begin, char *s);
t_pile	*push(t_pile *a, int data);

//sa ___ sb ___ ss
void	s(t_pile **add_a);
void	ss(t_pile **add_a, t_pile **add_b);

//pa ___ pb
void	p(t_pile **add_a, t_pile **add_b);

//ra ___ rb ___ rr
void	r(t_pile **add_a);
void	rr(t_pile **add_a, t_pile **add_b);

//rra ___ rrb ___ rrr
void	r_r(t_pile **add_a);
void	rr_r(t_pile **add_a, t_pile **add_b);

//merge_sort.c
void	free_merge(int *t1, int *t2);
int	*copie(int *t, int *tab, int start, int end);
int	*fusion(int *t1, int *t2, int s1, int s2, int *tab);
int	*merge_sort(int *tab, int n);

//ft_utils.c
int	ft_atoi(const char *str);

#endif