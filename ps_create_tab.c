/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:19 by amery             #+#    #+#             */
/*   Updated: 2023/01/27 15:45:12 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_tab(t_tab ab)
{
	if (ab.a)
		free(ab.a);
	if (ab.b)
		free(ab.b);
	//ft_putchar('\n');
	//system("leaks push_swap | tail -n2");
	return (0);
}

int	*create_a(char **tab, int size)
{
	int	*a;
	int	i;

	a = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		a[i] = ft_atoi(tab[i]);
	return (a);
}

int	*create_b(int size)
{
	int	*b;

	b = malloc(sizeof(int) * size);
	ft_bzero(b, size);
	return (b);
}
