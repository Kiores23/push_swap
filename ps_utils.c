/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:32 by amery             #+#    #+#             */
/*   Updated: 2023/03/13 16:27:57 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_fun(t_tab ab, void (*f)(t_tab, char *), char *cmd)
{
	ft_putstr(cmd);
	ft_putchar('\n');
	f(ab, cmd);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
}

int	get_id(int *tab, int size, int n)
{
	int	i;

	i = 0;
	while (tab[i] != n && i <= size)
		i++;
	if (i > size)
		return (-1);
	return (i);
}

int	check_group(int *tab, int size, int *n, int nsize)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if(get_id(n, nsize, tab[i]) >= 0)
			return(1);
		i++;
	}
	return (0);
}

int	get_nsmallest(int *tab, int n, int size)
{
	int	it1;
	int	it2;
	int	i;

	it1 = 0;
	it2 = -1;
	while (++it2 < size)
	{
		if (tab[it2] < tab[it1])
			it1 = it2;
	}
	if (n == 1)
		return (tab[it1]);
	i = it1;
	while (n-- > 1)
	{
		it1 = i;
		it2 = -1;
		while (++it2 < size && i == it1)
		{
			if (tab[it2] > tab[it1])
				i = it2;
		}
		--it2;
		while (++it2 < size)
		{
			if (tab[it2] < tab[i] && tab[it2] > tab[it1])
				i = it2;
		}
	}
	return (tab[i]);
}