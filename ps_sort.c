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

void	sort3(t_tab ab, t_fun f)
{
	if (ft_issorta(ab.a, ab.sa, 0))
		return ;
	sort_rotate(ab, f);
	if (ab.a[0] > ab.a[1])
		choice_fun(ab, &swap, "sa");
	sort3 (ab, f);
}

void	sort5(t_tab ab, t_fun f)
{
	sort_rotate(ab, f);
	return ;
}

void	sort(t_tab ab, t_fun f)
{
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (ft_issorta(ab.a, ab.sa, 0) && !ab.sb)
		return (ft_putstr("-----------------------------------------------\nIs sort\n"));
	else if (ab.sa <= 3 && ab.sb == 0)
		sort3(ab, f);
	else if (ab.sa <= 5)
		sort5(ab, f);
	return (sort(ab, f));
}
