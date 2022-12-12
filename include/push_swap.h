/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:25:45 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/12 19:42:18 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_pile
{
	int				n;
	unsigned int	x;
	int				size;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

// cost.c
t_pile				*set_minx(t_pile *a, int x, int size);
void				set_xvalues(t_pile *a, int size);

// parsing.c
int					ft_validint(char *str);
int					ft_noduplicate(t_pile *begin, t_pile *a, char *str, int i);
int					ft_valid(t_pile *begin, t_pile *a, char *str);
t_pile				*ft_parse(t_pile *a, char *str, int i);
t_pile				*get_pile(int ac, char **av);

// pile_exodus.c
void				ft_printpile(t_pile *begin);
t_pile				*ft_merge_pile(t_pile *begin, t_pile *tmp);
int					ft_sizepile(t_pile *a);

// pile_genesis.c
t_pile				*new_pile(int n);
t_pile				*ft_push(t_pile **begin, int n);
t_pile				*ft_push_end(t_pile **begin, int n);
int					ft_pop(t_pile **begin);
void				free_pile(t_pile **begin);

#endif