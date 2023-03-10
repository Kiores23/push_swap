/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_undersort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:34:03 by amery             #+#    #+#             */
/*   Updated: 2023/03/10 17:37:10 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(t_tab ab, t_fun f, t_g g)
{
	while (check_group(ab.a, ab.sa, g.grp[0], g.s2)
			|| check_group(ab.a, ab.sa, g.grp[1], g.s2))
	{
		ab.sa = *ab.psa;
		ab.sb = *ab.psb;
		if (get_id(g.grp[1], g.s2, ab.b[0]) >= 0
			&& (get_id(g.grp[0], g.s2, ab.a[0]) >= 0
			|| get_id(g.grp[1], g.s2, ab.a[0]) >= 0))
			choice_fun(ab, &rotate, "rb");
		if (get_id(g.grp[0], g.s2, ab.a[0]) >= 0 
			|| get_id(g.grp[1], g.s2, ab.a[0]) >= 0)
			choice_fun(ab, &push, "pb");
		else if (get_id(g.grp[1], g.s2, ab.b[0]) >= 0)
			choice_fun(ab, &rotate, "rr");
		else
			choice_fun(ab, &rotate, "ra");
	}
}