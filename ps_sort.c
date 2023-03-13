/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:29 by amery             #+#    #+#             */
/*   Updated: 2023/03/13 20:47:23 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_tab ab, t_fun f, t_g g)
{
	atob(ab, f, g);
	sort_a(ab, f, g);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	g.i = g.s1 - 1;
	btoa(ab, f, g);
	/*while (check_group(ab.a, ab.sa, g.grp[0], g.s2))
	{
		if(get_id(g.grp[0], g.s2, ab.a[0]) >= 0)
			choice_fun(ab, &push, "pb");
		ab.sa = *ab.psa;
		ab.sb = *ab.psb;
		choice_fun(ab, &rotate, "ra");
	}*/
	//if(!ft_issorta(ab.a, ab.sa, 0))
	//	sort(ab, f, g);
}