/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:44 by amery             #+#    #+#             */
/*   Updated: 2023/03/10 17:17:04 by amery            ###   ########.fr       */
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

typedef struct s_g
{
	int	i;
	int	j;
	int	grp[100][1000];
	int	s1;
	int	s2;
}	t_g;

//SORT
void	sort(t_tab ab, t_fun f, t_g g);
//UNDERSORT
void	atob(t_tab ab, t_fun f, t_g g);
//FUNCTION
void	swap(t_tab ab, char *cmd);
void	push(t_tab ab, char *cmd);
void	rotate(t_tab ab, char *cmd);
//PS_CREATE_TAB
void	create_group(t_tab ab, t_g *g);
int		*create_a(char **tab, int size);
int		*create_b(int size);
int		free_tab(t_tab ab);
void	putpile(t_tab ab);
//PS_UTILS
void	choice_fun(t_tab ab, void (*f)(t_tab, char *), char *cmd);
int		get_nsmallest(int *tab, int n, int size);
int		get_id(int *tab, int size, int n);
int		check_group(int *tab, int size, int *n, int nsize);
/*
void	sort_goto_a(t_tab ab, t_fun f, int nb);
void	sort_goto_b(t_tab ab, t_fun f, int nb);
*/
//PS_VERIF
int		ps_verif(char **a, int size);

#endif