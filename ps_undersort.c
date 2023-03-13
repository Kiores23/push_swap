/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_undersort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:34:03 by amery             #+#    #+#             */
/*   Updated: 2023/03/13 20:58:04 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(t_tab ab, t_fun f, t_g g)
{
	g.i = 0;
	g.j = 1;
	while ((g.i + 1 < g.s1 && check_group(ab.a, ab.sa, g.grp[g.i], g.s2))
			|| (g.j + 1 < g.s1 && check_group(ab.a, ab.sa, g.grp[g.j], g.s2)))
	{
		ab.sa = *ab.psa;
		ab.sb = *ab.psb;
		if (ab.sb && get_id(g.grp[g.j], g.s2, ab.b[0]) >= 0
			&& (get_id(g.grp[g.i], g.s2, ab.a[0]) >= 0
			|| get_id(g.grp[g.j], g.s2, ab.a[0]) >= 0))
			choice_fun(ab, &rotate, "rb");
		if ((g.i + 1 < g.s1 && get_id(g.grp[g.i], g.s2, ab.a[0]) >= 0)
			|| (g.j + 1 < g.s1 && get_id(g.grp[g.j], g.s2, ab.a[0]) >= 0))
			choice_fun(ab, &push, "pb");
		else if (get_id(g.grp[g.j], g.s2, ab.b[0]) >= 0)
			choice_fun(ab, &rotate, "rr");
		else
			choice_fun(ab, &rotate, "ra");
		if (g.i + 2 < g.s1 && !check_group(ab.a, ab.sa, g.grp[g.i], g.s2))
			g.i += 2;
		else if (g.j + 2 < g.s1 && !check_group(ab.a, ab.sa, g.grp[g.j], g.s2))
			g.j += 2;
	}
}

void	sort_a(t_tab ab, t_fun f, t_g g)
{
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (ft_issorta(ab.a, ab.sa, 0))
		return;
	create_subgroup(ab.a, ab.sa, &g);
	g.i = 0;
	while (check_group(ab.a, ab.sa, g.subgrp[0], g.s3))
	{
		ab.sa = *ab.psa;
		ab.sb = *ab.psb;
		if (get_id(g.subgrp[0], g.s3, ab.a[0]) >= 0)
			choice_fun(ab, &push, "pb");
		else
			choice_fun(ab, &rotate, "ra");
	}
	sort_a(ab, f, g);
}

void	btoa(t_tab ab, t_fun f, t_g g)
{
	create_subgroup(g.grp[g.i], g.s2, &g);
	while (check_group(ab.b, ab.sb, g.grp[g.i], g.s2))
	{
		ab.sa = *ab.psa;
		ab.sb = *ab.psb;
		if (ab.b[0] < ab.b[ab.sb - 1])
			choice_fun(ab, &rotate, "rrb");
		while ((get_id(g.grp[g.i], g.s2, ab.a[0]) >= 0
			&& ab.a[0] < ab.b[0] && g.i < g.s1 - 1)
			|| (ab.a[0] < ab.b[0] && ab.a[0] > ab.a[ab.sa - 1] && g.i == g.s1 - 1))
			choice_fun(ab, &rotate, "ra");
		while ((get_id(g.grp[g.i], g.s2, ab.a[ab.sa - 1]) >= 0
			&& ab.a[ab.sa - 1] > ab.b[0] && g.i < g.s1 - 1)
			|| (ab.a[ab.sa - 1] > ab.b[0] && ab.a[ab.sa - 1] < ab.a[0]
			&& g.i == g.s1 - 1))
			choice_fun(ab, &rotate, "rra");
		if (get_id(g.grp[g.i], g.s2, ab.b[0]) >= 0)
			choice_fun(ab, &push, "pa");
	}
	g.i--;
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (g.i != -1)
		btoa(ab, f, g);
}