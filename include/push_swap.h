/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:25:45 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/15 19:35:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

// la variable path indique le sens du plus court chemin pour insérer l'element dans a
// path = 1 : on rotate les deux vers le bas (r)
// path = -1 : on rotate les deux vers le haut (rr)
// path = 2 : on rotate b vers le haut (rrb) et a vers le bas (ra)
// path = -2 : on rotate b vers le bas (rb) et a vers le haut (rra)
typedef struct s_pile
{
	int				n;
	unsigned int	x;
	unsigned int	pos;
	unsigned int	cost;
	unsigned int	x_to_push;
	int				path;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

// checker.c
void				free_error(t_pile **a, t_pile **b, int n);
int					main(int ac, char **av);

// making_b.c
void				set_xvalues(t_pile *a, int size);
unsigned int		ft_sqrt(unsigned int n);
t_pile				*makeb(t_pile **a, unsigned int size);

// parsing.c
int					ft_validint(char *str);
int					ft_noduplicate(t_pile *begin, t_pile *a, char *str, int i);
int					ft_valid(t_pile *begin, t_pile *a, char *str);
t_pile				*ft_parse(t_pile *a, char *str, int i);
t_pile				*get_pile(int ac, char **av);

// pile_exodus.c
unsigned int		ft_sizepile(t_pile *a);
void				ft_printpile(t_pile *begin, char *str);
void				ft_printpile_rev(t_pile *begin, char *str);
t_pile				*ft_merge_pile(t_pile *begin, t_pile *tmp);

// pile_genesis.c
t_pile				*new_pile(int n);
t_pile				*ft_push(t_pile **begin, t_pile *new);
t_pile				*ft_push_end(t_pile **begin, t_pile *new);
t_pile				*ft_pop(t_pile **begin);
void				free_pile(t_pile **begin);

// pile_leviticus.c
void				push(t_pile **a, t_pile **b, char *str);
void				rotate(t_pile **a, char *str);
void				revrotate(t_pile **a, char *str);
void				swap(t_pile **a, char *str);
void				both(void (*f)(t_pile **, char *), t_pile **a, t_pile **b,
						char *str);

// sort.c
void				three_semisort(t_pile **a);
void				set_pos(t_pile *a);
t_pile				*get_insertion(t_pile *a, t_pile *b);
void				get_costs(t_pile *a, t_pile *b, unsigned int sizea,
						unsigned int sizeb);
void				step_sort(t_pile **a, t_pile **b, unsigned int sizea,
						unsigned int sizeb);
void				final_set(t_pile **a, int sizea);

#endif