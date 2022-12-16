/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:12:26 by lkrief            #+#    #+#             */
/*   Updated: 2022/12/13 02:07:53 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_validint(char *str)
{
	int		i;
	double	n;
	int		signe;

	signe = 1;
	i = 0;
	n = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		signe = (str[i] == '+') - (str[i] == '-');
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && n <= INT_MAX)
	{
		n = 10 * n + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	n *= signe;
	if (n < INT_MIN || n > INT_MAX)
		return (-1);
	return (0);
}

int	ft_noduplicate(t_pile *begin, t_pile *a, char *str, int i)
{
	int		n;
	t_pile	*start;
	t_pile	*pile;

	n = ft_atoi(str);
	start = begin;
	pile = begin;
	while (++i <= 2)
	{
		if (pile != NULL)
		{
			if (n == pile->n)
				return (-1);
			pile = pile->next;
			while (start != pile)
			{
				if (n == pile->n)
					return (-1);
				pile = pile->next;
			}
		}
		start = a;
		pile = a;
	}
	return (0);
}

int	ft_valid(t_pile *begin, t_pile *a, char *str)
{
	return (ft_validint(str) + ft_noduplicate(begin, a, str, 0));
}

t_pile	*ft_parse(t_pile *a, char *str, int i)
{
	t_pile	*begin;
	char	**tmp;

	begin = NULL;
	tmp = ft_split(str, " \t\n\v\f\r");
	if (!tmp)
		return (NULL);
	while (tmp[++i])
	{
		if (ft_valid(begin, a, tmp[i]) == 0)
		{
			ft_push_end(&begin, new_pile(ft_atoi(tmp[i])));
			free(tmp[i]);
		}
		else
		{
			while (tmp[i])
				free(tmp[i++]);
			free_pile(&begin);
			i--;
		}
	}
	free(tmp);
	return (begin);
}

t_pile	*get_pile(int ac, char **av)
{
	int		i;
	t_pile	*begin;
	t_pile	*tmp;

	begin = NULL;
	i = 0;
	while (++i < ac)
	{
		tmp = ft_parse(begin, av[i], -1);
		if (!tmp)
		{
			if (begin)
				free_pile(&begin);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		else if (begin == NULL)
			begin = tmp;
		else
			ft_merge_pile(begin, tmp);
	}
	return (begin);
}
