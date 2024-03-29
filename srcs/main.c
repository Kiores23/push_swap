/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:41 by amery             #+#    #+#             */
/*   Updated: 2023/03/24 16:58:09 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	freexit(int argc, char *argv[], t_tab ab, char **arg)
{
	if (argc <= 1 && ab.sa > argc - 1 && ft_strchr(argv[1], ' ') && arg)
		free_julien(arg);
	free_tab(ab);
	return (0);
}

void	init_ab(t_tab *ab, int argc)
{
	ab->sa = argc - 1;
	ab->sb = 0;
	ab->a = NULL;
	ab->b = NULL;
}

int	main(int argc, char *argv[])
{
	char	**arg;
	t_tab	ab;

	init_ab(&ab, argc);
	arg = argv + 1;
	if (ab.sa == 0)
		return (0);
	else if (ab.sa == 1 && ft_strchr(arg[0], ' '))
		arg = ft_julien(&ab, arg);
	else if (ab.sa > 1 && !check_julien(arg, ab.sa))
		return (ft_rerror());
	if (!ps_verif(arg, ab.sa))
		return (freexit(argc, argv, ab, arg) + ft_rerror());
	ab.psa = &ab.sa;
	ab.psb = &ab.sb;
	ab.a = create_a(arg, ab.sa);
	ab.b = create_b(ab.sa);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (!ab.a || !ab.b || !checkdouble(ab))
		return (freexit(argc, argv, ab, arg) + ft_rerror());
	if (!ft_issorta(ab.a, ab.sa, 0))
		sort(ab);
	return (freexit(argc, argv, ab, arg));
}
