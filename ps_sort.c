/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:29 by amery             #+#    #+#             */
/*   Updated: 2023/01/27 17:10:32 by amery            ###   ########.fr       */
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

void	sort(t_tab ab, t_fun f)
{
	int	i_min;
	int	i_max;

	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (ft_issorta(ab.a, ab.sa, 0))
		return (sort_end(ab, f));
	i_max = get_indexbiggest(ab.a, ab.sa);
	i_min = get_indexsmallest(ab.a, ab.sa);
	if(i_max - i_min == 1 || i_max - i_min == -1
		|| i_max - i_min == ab.sa - 1 || i_max - i_min == (ab.sa - 1) * -1
		|| i_min <= ab.sa - i_max - 1 || i_max != ab.sa)
	{
		sort_goto(ab, f, ab.a[i_min]);
		if (!ft_issorta(ab.a, ab.sa, 0))
			choice_fun(ab, &push, "pb");
	}
	else
	{
		i_max = i_max - ab.sa + 1;
		if (i_max < 0)
			i_max = ab.sa + i_max;
		sort_goto(ab, f, ab.a[i_max]);
	}
	sort(ab, f);
}
