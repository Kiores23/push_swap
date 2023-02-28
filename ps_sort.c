/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:29 by amery             #+#    #+#             */
/*   Updated: 2023/02/28 19:02:25 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_end(t_tab ab, t_fun f)
{
	ab.sb = *ab.psb;
	while (ab.sb)
	{
		ab.sa = *ab.psa;
		choice_fun(ab, &push, "pa");
		ab.sb = *ab.psb;
	}
}

void	sort(t_tab ab, t_fun f, t_v n)
{
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (ft_issorta(ab.a, ab.sa, 0) && n.n <= 0)
		return (sort_end(ab, f));
	if (n.n == 0 && ab.sa > 5)
	{
		n.min1 = get_nnsmallest(ab.a, 1, ab.sa);
		n.min2 = get_nnsmallest(ab.a, 2, ab.sa);
		n.min3 = get_nnsmallest(ab.a, 3, ab.sa);
		n.min4 = get_nnsmallest(ab.a, 4, ab.sa);
		n.min5 = get_nnsmallest(ab.a, 5, ab.sa);
		//printf("%i, %i, %i, %i, %i\n", n.min1, n.min2, n.min3, n.min4, n.min5);
		n.n = 5;
	}
	if (n.n > 0)
		n.i_current = get_nclosest(n, ab);
	else
		n.i_current = get_id(ab, get_nnsmallest(ab.a, 1, ab.sa));
	//printf("GOTO %i\n", ab.a[n.i_current]);
	sort_goto(ab, f, ab.a[n.i_current]);
	if (!ft_issorta(ab.a, ab.sa, 0) || ab.a[0] == n.min1 || ab.a[0] == n.min2
		|| ab.a[0] == n.min3 || ab.a[0] == n.min4 || ab.a[0] == n.min5)
		choice_fun(ab, &push, "pb");
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	n.i = -1;
	while (++n.i || !ft_issortrn(ab.b, ab.sb, 6 - n.n - n.i))
	{
		while (!ft_issortrn(ab.b, ab.sb, 6 - n.n - n.i))
		{
			if (ab.b[0] < ab.b[1])
				choice_fun(ab, &swap, "sb");
			else if (++n.i)
				choice_fun(ab, &rotate, "rb");
		}
		while (ft_issortrn(ab.b, ab.sb, 6 - n.n - n.i) && n.i--)
			choice_fun(ab, &rotate, "rrb");
	}
	n.n--;
	sort(ab, f, n);
}
