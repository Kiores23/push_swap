/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:41 by amery             #+#    #+#             */
/*   Updated: 2023/03/10 17:43:31 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_tab	ab;
	t_fun	f;
	t_g		g;

	f.swap = &swap;
	f.push = &push;
	f.rotate = &rotate;
	ab.sa = argc - 1;
	ab.sb = 0;
	if (argc < 2 || !ps_verif(argv + 1, ab.sa))
		return (ft_rerror());
	ab.psa = &ab.sa;
	ab.psb = &ab.sb;
	ab.a = create_a(argv + 1, ab.sa);
	ab.b = create_b(ab.sa);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (!ab.a || !ab.b)
		return (free_tab(ab) + ft_rerror());
	create_group(ab, &g);
	sort(ab, f, g);
	//putpile(ab);
	return (free_tab(ab));
}
