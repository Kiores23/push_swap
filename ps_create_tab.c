/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:19 by amery             #+#    #+#             */
/*   Updated: 2023/03/13 20:24:06 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putpile(t_tab ab)
{
	int	i;

	i = -1;
	printf("\n( A ) = ");
	while (++i < ab.sa)
		printf(" %i", ab.a[i]);
	i = -1;
	printf("\n( B ) = ");
	while (++i < ab.sb)
		printf(" %i", ab.b[i]);
	printf("\n");
	printf("\n");
}

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

void	create_group(t_tab ab, t_g *g)
{
	if (ab.sa <= 100)
		g->s1 = ab.sa / 33 + 2;
	else
		g->s1 = 0.0125 * ab.sa + 3.75;
	g->s2 = ab.sa / (g->s1);
	g->i = 0;
	while (g->i < g->s1)
	{
		g->j = 0;
		//printf("\nGROUP %i :\n\n", g->i + 1);
		while (g->j < g->s2 || (g->i + 1 == g->s1 && g->i * g->s2 + g->j < ab.sa))
		{
			g->grp[g->i][g->j] = get_nsmallest(ab.a, g->i * g->s2 + g->j + 1, ab.sa);
			//printf("%i\n", g->grp[g->i][g->j]);
			g->j++;
		}
		g->i++;
	}
}

void	create_subgroup(int *tab, int size, t_g *g)
{
	g->s3 = size / 2;
	g->j = 0;
	while (g->j < g->s3)
	{
		g->subgrp[0][g->j] = get_nsmallest(tab, g->j + 1, size);
		//printf("%i\n", g->grp[g->i][g->j]);
		g->j++;
	}
	while (g->j < size)
	{
		g->subgrp[0][g->j] = get_nsmallest(tab, g->j + 1, size);
		//printf("%i\n", g->grp[g->i][g->j]);
		g->j++;
	}
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
