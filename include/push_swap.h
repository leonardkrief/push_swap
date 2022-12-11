/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:25:45 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/11 06:17:30 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_pile
{
	int				n;
	struct s_pile	*next;
	struct s_pile	*prev;
}	t_pile;

// parsing.c
int	ft_validint(char *str);
int	ft_noduplicate(t_pile *begin, t_pile *a, char *str, int i);
int	ft_valid(t_pile *begin, t_pile *a, char *str);
t_pile	*ft_parse(t_pile *a, char *str);
t_pile	*get_pile(int ac, char **av);

// pile.c
t_pile	*new_pile(int n);
t_pile	*ft_push(t_pile **begin, int n);
t_pile	*ft_push_end(t_pile **begin, int n);
int	ft_pop(t_pile **begin);
t_pile	*ft_push_pile(t_pile **begin, t_pile *tmp);
void	free_pile(t_pile **begin);
void	ft_printpile(t_pile *begin);

#endif