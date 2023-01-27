
#include "push_swap.h"

void	choice_fun(t_tab ab, void (*f)(t_tab, char *), char *cmd)
{
	int i;

	ft_putstr("-----------------------------------------------\n");
	ft_putstr(cmd);
	ft_putchar('\n');
	f(ab, cmd);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	i = -1;
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
	ft_putstr("\n_\t_\na\tb\n");
}

void	sort3(t_tab ab, t_fun f)
{
	if (ft_issorta(ab.a, ab.sa, 0) && !ab.sb)
		return ;
	else if (ab.a[0] > ab.a[1] && ab.a[0] < ab.a[2])
		choice_fun(ab, &swap, "sa");
	else
		choice_fun(ab, &rotate, "ra");
	sort3(ab, f);
}

void	sort(t_tab ab, t_fun f)
{
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (ft_issorta(ab.a, ab.sa, 0) && !ab.sb)
		return (ft_putstr("Is sort\n"));
	else if (ab.sa <= 3 && ab.sb == 0)
		sort3(ab, f);
	return (sort(ab, f));
}