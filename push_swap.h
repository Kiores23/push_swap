/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:44 by amery             #+#    #+#             */
/*   Updated: 2023/01/27 16:48:15 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils/push_swap_utils.h"
# include <stdlib.h>

typedef struct s_tab
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

typedef struct s_fun
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

void	swap(t_tab ab, char *cmd);
void	push(t_tab ab, char *cmd);
void	rotate(t_tab ab, char *cmd);
void	choice_fun(t_tab ab, void (*f)(t_tab, char *), char *cmd);
void	sort_rotate(t_tab ab, t_fun f);
void	sort(t_tab ab, t_fun f);
int		ps_verif(char **a, int size);
int		*create_a(char **tab, int size);
int		*create_b(int size);
int		free_tab(t_tab ab);
int		*get_next_smaller(int *tab, int size);

#endif