/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:41 by amery             #+#    #+#             */
/*   Updated: 2023/02/28 19:02:34 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_tab	ab;
	t_fun	f;
	t_v		n;
	int		i;

	f.swap = &swap;
	f.push = &push;
	f.rotate = &rotate;
	ab.sa = argc - 1;
	ab.sb = 0;
	ab.psa = &ab.sa;
	ab.psb = &ab.sb;
	if (argc < 2 || !ps_verif(argv + 1, ab.sa))
		return (ft_rerror());
	ab.a = create_a(argv + 1, ab.sa);
	ab.b = create_b(ab.sa);
	if (!ab.a || !ab.b)
		return (free_tab(ab) + ft_rerror());
	n.n = 0;
	sort(ab, f, n);
	/*i = -1;
	while (++i < ab.sa || i < ab.sb)
	{
		ft_putchar('\n');
		if (i < ab.sa)
			ft_putnbr(ab.a[i]);
		else
			ft_putchar(' ');
		ft_putchar('\t');
		if (i < ab.sb)
			ft_putnbr(ab.b[i]);
	}
	ft_putstr("\n_\t_\na\tb\n");*/
	return (free_tab(ab));
}
