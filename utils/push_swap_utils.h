/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:56:16 by amery             #+#    #+#             */
/*   Updated: 2023/01/27 15:56:28 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_bzero(int *s, size_t n);
int		ft_strlen(char *str);
int		ft_nbrlen(int nbr);
int		ft_issorta(int *tab, int size, int place);
int		ft_isnumber(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		ft_rerror(void);

#endif