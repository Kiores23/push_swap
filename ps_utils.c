/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:32 by amery             #+#    #+#             */
/*   Updated: 2023/02/28 19:14:24 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_fun(t_tab ab, void (*f)(t_tab, char *), char *cmd)
{
	int	i;

	//ft_putstr("-----------------------------------------------\n");
	ft_putstr(cmd);
	ft_putchar('\n');
	f(ab, cmd);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	i = -1;
	/*while (++i < ab.sa || i < ab.sb)
	{
		ft_putchar('\n');
		if (i < ab.sa)
			ft_putnbr(ab.a[i]);
		else
			ft_putchar(' ');
		ft_putchar('\t');
		if (i < ab.sb)
			ft_putnbr(ab.b[i]);
	}*/
	//ft_putstr("\n_\t_\na\tb\n");
}

void	sort_rotate(t_tab ab, t_fun f)
{
	t_v	var;

	var.i = 0;
	var.j = ab.sa;
	var.n = 0;
	while (!ft_issorta(ab.a, ab.sa, var.i++) && !ft_issorta(ab.a, ab.sa, var.j--) 
			&& var.n <= ab.sa / 2)
			var.n++;
	if (var.n > ab.sa / 2)
		return ;
	while (var.i > (var.j - ab.sa) * (-1) && var.n--)
		choice_fun(ab, &rotate, "ra");
	while (var.i <= (var.j - ab.sa) * (-1) && var.n--)
		choice_fun(ab, &rotate, "rra");
}

void	sort_goto(t_tab ab, t_fun f, int nb)
{
	t_v	var;

	var.i = 0;
	var.j = ab.sa;
	var.n = 0;
	while (ab.a[var.i++] != nb && (ab.a[var.j--] != nb
			|| var.j + 1 == ab.sa) && var.n < ab.sa )
			var.n++;
	if (var.n == ab.sa || var.n == 0)
		return ;
	while (var.i > (var.j - ab.sa) * (-1) && var.n--)
		choice_fun(ab, &rotate, "ra");
	while (var.i <= (var.j - ab.sa) * (-1) && var.n--)
		choice_fun(ab, &rotate, "rra");
}

int	get_nnsmallest(int *tab, int n, int size)
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

int	get_indexnbiggest(int *tab, int n, int size)
{
	int	i;

	n = 0;
	i = 0;
	while (++i < size)
	{
		if (tab[i] > tab[n])
			n = i;
	}
	return (n);
}

int	get_id(t_tab ab, int n)
{
	int	i;

	i = -1;
	while (++i < ab.sa)
	{
		if (ab.a[i] == n)
			return (i);
	}
	return (0);
}

int	nchoice(t_v n)
{
	n.i = 0;
	while (++n.i <= 5)
	{
		n.j = 0;
		if (n.i == 1)
			n.rc = n.r1;
		else if (n.i == 2)
			n.rc = n.r2;
		else if (n.i == 3)
			n.rc = n.r3;
		else if (n.i == 4)
			n.rc = n.r4 * 2;
		else
			n.rc = n.r5 * 6;
		if (n.rc >= n.r1)
			n.j++;
		if (n.rc >= n.r2)
			n.j++;
		if (n.rc >= n.r3)
			n.j++;
		if (n.rc >= n.r4 * 2)
			n.j++;
		if (n.rc >= n.r5 * 6)
			n.j++;
		//printf("%i = %i\n", n.i, n.j);
		if (n.n == n.j)
			return (n.i);
	}
	return (5 - n.n + 1);
}

int	get_nclosest(t_v n, t_tab ab)
{
	n.n = 6 - n.n;
	n.r1 = get_id(ab, n.min1);
	n.r2 = get_id(ab, n.min2);
	n.r3 = get_id(ab, n.min3);
	n.r4 = get_id(ab, n.min4);
	n.r5 = get_id(ab, n.min5);
	if (n.r1 > (n.r1 - ab.sa) * -1)
		n.r1 = (n.r1 - ab.sa) * -1;
	if (n.r2 > (n.r2 - ab.sa) * -1)
		n.r2 = (n.r2 - ab.sa) * -1;
	if (n.r3 > (n.r2 - ab.sa) * -1)
		n.r3 = (n.r3 - ab.sa) * -1;
	if (n.r4 > (n.r4 - ab.sa) * -1)
		n.r4 = (n.r4 - ab.sa) * -1;
	if (n.r5 > (n.r5 - ab.sa) * -1)
		n.r5 = (n.r5 - ab.sa) * -1;
	n.rc = nchoice(n);
	if (n.rc == 1)
		return (get_id(ab, n.min1));
	else if (n.rc == 2)
		return (get_id(ab, n.min2));
	else if (n.rc == 3)
		return (get_id(ab, n.min3));
	else if (n.rc == 4)
		return (get_id(ab, n.min4));
	else
		return (get_id(ab, n.min5));
}
