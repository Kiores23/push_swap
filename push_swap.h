
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils/push_swap_utils.h"
# include <stdlib.h>

typedef struct	s_tab
{
	int	*a;
	int	*b;
	int	*c;
	int	*d;
	int	sa;
	int	*psa;
	int	sb;
	int	*psb;
	int	sc;
	int	sd;
}		t_tab;

typedef struct	s_fun
{
	void	(*swap)(t_tab, char*);
	void	(*push)(t_tab, char*);
	void	(*rotate)(t_tab, char*);
	void	(*current)(t_tab, char*);
}			t_fun;

typedef struct s_v
{
	int	i;
	int	j;
	int	n;
}	t_v;


int		ps_verif(char **a, int size);
int		*create_a(char **tab, int size);
int		*create_b(int size);
int		free_tab(t_tab ab);
int 	*get_next_smaller(int *tab, int size);
void	swap(t_tab ab, char *cmd);
void	push(t_tab ab, char *cmd);
void	rotate(t_tab ab, char *cmd);
void 	sort(t_tab ab, t_fun f);

#endif