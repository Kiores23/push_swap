/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:32 by amery             #+#    #+#             */
/*   Updated: 2023/01/27 17:08:10 by amery            ###   ########.fr       */
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
	while (ab.a[var.i++] != nb && ab.a[var.j--] != nb
			&& var.n < ab.sa)
			var.n++;
	if (var.n == ab.sa || var.n == 0)
		return ;
	while (var.i > (var.j - ab.sa) * (-1) && var.n--)
		choice_fun(ab, &rotate, "ra");
	while (var.i <= (var.j - ab.sa) * (-1) && var.n--)
		choice_fun(ab, &rotate, "rra");
}

int	get_indexsmallest(int *tab, int size)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (++i < size)
	{
		if (tab[i] < tab[n])
			n = i;
	}
	return (n);
}

int	get_indexbiggest(int *tab, int size)
{
	int	n;
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

int	*get_next_smaller(int *tab, int size)
{
	static int	init = 0;
	static int	n = 0;
	int			i;
	int			tmp;
	int			tmp2;

	i = 0;
	tmp2 = n;
	while (!init && ++i < size)
	{
		if (tab[i] > tab[n])
			n = i;
	}
	while (init && i < size && tab[i] >= tab[n])
		i++;
	tmp = i;
	while (init && ++i < size)
	{
		if (tab[i] < tab[n] && tab[tmp] < tab[i])
			tmp = i;
		if (i + 1 == size)
			n = tmp;
	}
	init = 1;
	if (n == tmp2)
		return (NULL);
	return (&tab[n]);
}
